#pragma once

#include <utility>
#include <iterator>


namespace mad::cppin {

template<typename Collection>
struct iterator_type {
	using type = decltype(std::end(std::declval<const Collection&>()));
};

}
