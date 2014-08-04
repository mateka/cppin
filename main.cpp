#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>

#include "in.hpp"

template<typename ValueType>
struct printer {
	printer(const ValueType& val) {
		std::cout << "\t\tvalue = " << val << std::endl;
	}
};

template<typename Key, typename Value>
struct printer<std::pair<Key, Value>> {
	printer(const std::pair<Key, Value>& val) {
		std::cout << "\t\tvalue = (" << val.first << ", " << val.second << ")" << std::endl;
	}
};

template<typename ValueType> void print(const ValueType& val) {
	printer<ValueType> p = val;
}

template<typename C>
void check(const int e, const C& c) {
	if(auto pos = e in c) {
		std::cout << "\t" << e << " is in given collection: " << typeid(c).name() << std::endl;
		print(*pos.position());
	}
	else {
		std::cout << "\t" << e << " is not in given collection: " << typeid(c).name() << std::endl;
	}
}

int main() {
	std::cout << "Checking raw array:" << std::endl;
	int array[] = { 3, 2, 7, 10 };
	check(50, array);
	check(2, array);
	check(10, array);
	check(1, array);

	std::cout << "Checking array:" << std::endl;
	const std::array<int, 4> stdarray = { 3, 2, 7, 10 };
	check(50, stdarray);
	check(2, stdarray);
	check(10, stdarray);
	check(1, stdarray);

	std::cout << "Checking vector:" << std::endl;
	const std::vector<int> vec = { 3, 2, 7, 10 };
	check(50, vec);
	check(2, vec);
	check(10, vec);
	check(1, vec);

	std::cout << "Checking list:" << std::endl;
	const std::list<int> l = { 3, 2, 7, 10 };
	check(50, l);
	check(2, l);
	check(10, l);
	check(1, l);

	std::cout << "Checking set:" << std::endl;
	const std::set<int> os = { 3, 2, 7, 10 };
	check(50, os);
	check(2, os);
	check(10, os);
	check(1, os);

	std::cout << "Checking unordered set:" << std::endl;
	const std::unordered_set<int> us = { 3, 2, 7, 10 };
	check(50, us);
	check(2, us);
	check(10, us);
	check(1, us);

	std::cout << "Checking map:" << std::endl;
	const std::map<int, std::string> om = { { 3, "three" }, { 2, "two" }, { 7, "seven" }, { 10, "ten" } };
	check(50, om);
	check(2, om);
	check(10, om);
	check(1, om);

	std::cout << "Checking unordered map:" << std::endl;
	const std::unordered_map<int, std::string> um = { { 3, "three" }, { 2, "two" }, { 7, "seven" }, { 10, "ten" } };
	check(50, um);
	check(2, um);
	check(10, um);
	check(1, um);
}