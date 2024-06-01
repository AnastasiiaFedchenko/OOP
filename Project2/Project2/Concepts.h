#pragma once
#include <concepts>

template <typename T>
concept workable = requires (T a, T b)
{
	std::semiregular<T>;
	{a + b} -> std::same_as<T>;
	{a - b} -> std::same_as<T>;
	{a * b} -> std::same_as<T>;
	{a / b} -> std::convertible_to<T>;
	{a = b} -> std::same_as<T&>;
	{a < b} -> std::convertible_to<bool>;
	{a > b} -> std::convertible_to<bool>;
	{a <= b} -> std::convertible_to<bool>;
	{a >= b} -> std::convertible_to<bool>;
	{a == b} -> std::convertible_to<bool>;
	{a != b} -> std::convertible_to<bool>;
};

template <typename T, typename U>
concept convertible = requires
{
	//requires workable<T>;
	requires workable<U>;
	std::convertible_to<T, U>;
};

template <typename T, typename U>
concept convertible_in_any_direction = convertible<T, U> || convertible<U, T>;

template <typename T, typename U>
concept matrix_like_container = requires(T Matrix, U my_type)
{
	typename T::value_type;
	typename T::iterator;
	typename T::const_iterator;
	typename T::pointer;
	typename T::reference;

	{Matrix.begin()} -> std::same_as<class T::iterator>;
	Matrix.end();

	{*((*Matrix.begin()).begin())} -> std::convertible_to<U>;
};

template <typename T, typename U>
concept container = requires(T Matrix, U my_type)
{
	typename T::value_type;
	typename T::iterator;
	typename T::const_iterator;
	typename T::pointer;
	typename T::reference;

	{*Matrix.begin()} -> std::convertible_to<U>;
	Matrix.end();
};

template <typename Iter, typename U>
concept iter_type = requires (Iter a)
{
	requires std::input_iterator<Iter>;
	{ *a } -> std::convertible_to<U>;
};