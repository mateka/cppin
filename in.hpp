#pragma once

#include <algorithm>

#include "has_find.hpp"
#include "iterator_type.hpp"

namespace mad {
namespace cppin {
namespace details {

template<typename Collection>
class in_impl_base {
public:
	typedef typename iterator_type<Collection>::type iterator;

	in_impl_base(const iterator& position, const iterator& end)
		: position_(position), end_(end) {}

	explicit operator bool() const {
		return end_ != position_;
	}

	iterator position() const {
		return position_;
	}
private:
	iterator position_;
	iterator end_;
};

template<typename Element, typename Collection, bool HasMemberFind = false>
class in_impl : public in_impl_base<Collection> {
public:
	in_impl(const Element& e, const Collection& c)
		: in_impl_base<Collection>(std::find(std::begin(c), std::end(c), e), std::end(c)) {}
};

template<typename Element, typename Collection>
class in_impl<Element, Collection, true> : public in_impl_base<Collection> {
public:
	in_impl(const Element& e, const Collection& c)
		: in_impl_base<Collection>(c.find(e), std::end(c)) {}
};

template<typename Element, typename Collection> using in_implementation = in_impl<Element, Collection, has_member_find<Collection>::value>;

template<typename Element>
class in_left {
public:
	in_left(const Element& e) : e_(e) {}

	template<typename Collection> friend
		in_implementation<Element, Collection> operator<<(const in_left<Element>& l,
											const Collection& c) {
		return in_implementation<Element, Collection>(l.e_, c);
	}
private:
	const Element& e_;
};

template<typename Collection>
class in_right {
public:
	in_right(const Collection& c) : c_(c) {}

	template<typename Element> friend
		in_implementation<Element, Collection> operator<<(const Element& e,
											const in_right<Collection>& r) {
		return in_implementation<Element, Collection>(e, r.c_);
	}
private:
	const Collection& c_;
};

}	// details

struct in_type {};

template<typename Element>
details::in_left<Element> operator<<(const Element& e, const in_type) {
	return details::in_left<Element>(e);
}

template<typename Collection>
details::in_right<Collection> operator<<(const in_type, const Collection& c) {
	return details::in_right<Collection>(c);
}

namespace {
const in_type in_;
}	// anon namespace
}	// cppin
}	// mad

#ifndef NO_IN_MACRO
#define in << ::mad::cppin::in_ <<
#endif