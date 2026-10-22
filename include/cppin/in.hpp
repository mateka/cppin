#pragma once

#include <algorithm>
#include <concepts>
#include <ranges>

namespace mad::cppin {
namespace details {

template <typename Collection>
using in_unsafe_iterator_t = std::ranges::iterator_t<const std::remove_reference_t<Collection>>;

template <typename Collection>
using in_iterator_t = std::conditional_t<std::ranges::borrowed_range<Collection>,
                                         in_unsafe_iterator_t<Collection>, std::ranges::dangling>;

template <typename Collection, typename Element>
concept HasFind = requires(const std::remove_reference_t<Collection>& c, const Element& e) {
    { c.find(e) } -> std::same_as<in_unsafe_iterator_t<Collection>>;
};

template <typename Collection, typename Element>
constexpr auto find_position(Collection&& c, const Element& e) -> in_unsafe_iterator_t<Collection> {
    if constexpr (HasFind<Collection, Element>) {
        return c.find(e);
    } else {
        return std::ranges::find(c, e);
    }
}

template <typename Element, typename Collection> class in_implementation {
public:
    using iterator = in_iterator_t<Collection>;

    constexpr in_implementation(const Element& e, const std::remove_reference_t<Collection>& c)
        : in_implementation{find_position(c, e), std::ranges::end(c)} {}

    constexpr explicit operator bool() const { return found_; }

    [[nodiscard]]
    constexpr iterator position() const {
        return position_;
    }

private:
    constexpr in_implementation(in_unsafe_iterator_t<Collection> pos,
                                in_unsafe_iterator_t<Collection> end)
        : position_{pos}, found_{pos != end} {}

    const iterator position_;
    const bool found_;
};

template <typename Element> class in_left {
public:
    constexpr in_left(const Element& e) : e_{e} {}

    template <typename Collection>
    friend constexpr in_implementation<Element, Collection> operator<<(const in_left<Element>& l,
                                                                       Collection&& c) {
        return in_implementation<Element, Collection>{l.e_, c};
    }

private:
    const Element& e_;
};

}  // namespace details

struct in_type {};

template <typename Element>
constexpr details::in_left<Element> operator<<(const Element& e, const in_type) {
    return details::in_left<Element>{e};
}

inline constexpr in_type in_{};
}  // namespace mad::cppin

#ifndef NO_IN_MACRO
#define in << ::mad::cppin::in_ <<
#endif
