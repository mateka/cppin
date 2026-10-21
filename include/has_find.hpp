#pragma once

#include <type_traits>
#include <map>
#include <unordered_map>

namespace mad {
namespace cppin {

// Has a template for collection member function find?
template<template<typename...> class TCollection>
struct template_has_member_find : std::false_type {};

template<>
struct template_has_member_find<std::set> : std::true_type {};

template<>
struct template_has_member_find<std::multiset> : std::true_type {};

template<>
struct template_has_member_find<std::map> : std::true_type {};

template<>
struct template_has_member_find<std::multimap> : std::true_type {};

template<>
struct template_has_member_find<std::unordered_set> : std::true_type {};

template<>
struct template_has_member_find<std::unordered_multiset> : std::true_type {};

template<>
struct template_has_member_find<std::unordered_map> : std::true_type {};

template<>
struct template_has_member_find<std::unordered_multimap> : std::true_type {};


// Has a concrete type member function find?
template<typename Collection, typename... Args>
struct has_member_find : public std::false_type {};

template<template<typename...> class Collection, typename... Args>
struct has_member_find<Collection<Args...>> : template_has_member_find <Collection> {};


}	// cppin
}	// mad