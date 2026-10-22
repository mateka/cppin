#pragma once

#include <iterator>
#include <utility>

namespace mad::cppin {

template <typename Collection> struct iterator_type {
    using type = decltype(std::end(std::declval<const Collection&>()));
};

}  // namespace mad::cppin
