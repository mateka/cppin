#pragma once

#include "finder.hpp"

namespace mad {
namespace cppin {
namespace details {

template<typename Element, typename Collection>
class in_impl {
public:
	in_impl(const Element& e, const Collection& c)
		: c_(c), e_(e) {}

	explicit operator bool() const {
		return find_impl(e_, c_);
	}
private:
	const Collection& c_;
	const Element& e_;
};

template<typename Element>
class in_left {
public:
	in_left(const Element& e) : e_(e) {}

	template<typename Collection> friend
	in_impl<Element, Collection> operator<<(const in_left<Element>& l,
											const Collection& c) {
		return in_impl<Element, Collection>(l.e_, c);
	}
private:
	const Element& e_;
};

template<typename Collection>
class in_right {
public:
	in_right(const Collection& c) : c_(c) {}

	template<typename Element> friend
	in_impl<Element, Collection> operator<<(const Element& e,
											const in_right<Collection>& r) {
		return in_impl<Element, Collection>(e, r.c_);
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