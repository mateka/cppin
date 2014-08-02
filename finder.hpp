#pragma once

#include <algorithm>
#include "has_find.hpp"

namespace mad {
namespace cppin {

template<typename Element, typename Collection, bool HasMemberFind = false>
class finder {
public:
	bool operator()(const Element& e, const Collection& c) const {
		using namespace std;
		return end(c) != find(begin(c), end(c), e);
	}
};

template<typename Element, typename Collection>
class finder<Element, Collection, true> {
public:
	bool operator()(const Element& e, const Collection& c) const {
		using namespace std;
		return end(c) != c.find(e);
	}
};

template<typename Element, typename Collection>
bool find_impl(const Element& e, const Collection& c) {
	return finder<Element, Collection, has_member_find<Collection>::value>()(e, c);
}

}	// cppin
}	// mad