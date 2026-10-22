#pragma once

#include <algorithm>
#include <concepts>
#include <optional>
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

template <typename Element> class in_left {
public:
    constexpr in_left(const Element& e) : e_{e} {}

    template <typename Collection>
    friend constexpr std::optional<in_iterator_t<Collection>> operator<<(const in_left<Element>& l,
                                                                         Collection&& c) {
        // NOLINTNEXTLINE(readability-qualified-auto)
        const auto position = find_position(c, l.e_);
        if (position != std::ranges::cend(c)) {
            return in_iterator_t<Collection>{position};
        }
        return std::nullopt;
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

#ifdef CPPIN_ENABLE_IN_MACRO
#define in << ::mad::cppin::in_ <<
#endif
