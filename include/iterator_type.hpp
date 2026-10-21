#pragma once

namespace mad {
namespace cppin {

template<typename Collection>
struct iterator_type {
	typedef decltype(std::end(std::declval<const Collection&>())) type;
};

}	// cppin
}	// mad
