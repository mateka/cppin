cppin
=====

Python's `in` in c++:
```cpp
#include <iostream>
#include <map>
#include <string>

#include <cppin/in.hpp>

std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
if (auto p = 2 in dict) {
    std::cout << (*p)->second << std::endl;  // prints: "two"
}
```
It is slightly more powerful than `in` in Python and c++20 `contains`, because it does both things:
1. Check if the key is in the container
2. If it is, return an iterator to the element

Using `NO_IN_MACRO` would disable the `in` macro and the code would look like this:
```cpp
#include <iostream>
#include <map>
#include <string>

#define NO_IN_MACRO
#include <cppin/in.hpp>

using namespace mad::cppin;

std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
if (auto p = 2 << in_ << dict) {
    std::cout << (*p)->second << std::endl;  // prints: "two"
}
```

Currently it requires c++26 and is tested on gcc 14 and llvm 23.

Build
-----
```bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

Development
-----------
```bash
cmake --workflow --preset ci       # configure, build and test with warnings as errors
cmake --workflow --preset lint     # build with clang-tidy
cmake --build --preset format      # format sources with clang-format (needs `cmake --preset debug` first)
cmake --build --preset format-check
```
Presets `debug` and `asan` (address and undefined behaviour sanitizers) can be used with `cmake --preset`, `cmake --build --preset` and `ctest --preset`.
