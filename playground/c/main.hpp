#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

namespace detail {

template<typename T>
struct is_vector : std::false_type {};

template<typename T, typename A>
struct is_vector<std::vector<T, A>> : std::true_type {};

}

template<typename T>
struct is_vector : detail::is_vector<T> {};

template<typename T>
struct is_vector<const T> : detail::is_vector<T> {};

template<typename T>
struct is_vector<T&> : detail::is_vector<T> {};

template<typename T>
struct is_vector<T&&> : detail::is_vector<T> {};

template<typename T>
struct is_vector<std::vector<T>> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>> : std::true_type {};

template<typename T>
struct is_vector<std::vector<T>&> : std::true_type {};

template<typename T>
struct is_vector<std::vector<T>&&> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>&> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>&&> : std::true_type {};

template<typename T>
struct is_vector<std::vector<T>*> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>*> : std::true_type {};

template<typename T>
struct is_vector<std::vector<T>*&> : std::true_type {};

template<typename T>
struct is_vector<std::vector<T>*&&> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>*&> : std::true_type {};

template<typename T>
struct is_vector<const std::vector<T>*&&> : std::true_type {};

template<typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

#endif // MAIN_H

template<typename T>
struct is_vector<T> : std::false_type {};
