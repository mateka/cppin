#pragma once

namespace mad {
namespace cppin {

template<typename Collection>
struct iterator_type {
	typedef decltype(std::end(Collection())) type;
};

template<typename T, size_t S>
struct iterator_type<T[S]> {
	typedef T* type;
};

}	// cppin
}	// mad