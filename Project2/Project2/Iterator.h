#pragma once
#include <memory>
#include "BasicIterator.h"
#include "Concepts.h"


template <workable T>
class Matrix;

template <workable T>
class Iterator : public BasicIterator<T>
{
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

	Iterator() noexcept = default;
	explicit Iterator(const Matrix<T>& matrix) noexcept;
	Iterator(const Iterator<T>& iter) noexcept;
	Iterator(Iterator<T>&& iter) noexcept;

	Iterator<T>& operator =(const Iterator<T>& iter) noexcept;
	Iterator<T>& operator =(Iterator<T>&& iter) noexcept;

	reference operator *();
	pointer operator->();
	const T& operator *() const;
	const T* operator->() const;

	reference operator[](const difference_type i) const noexcept;

	Iterator<T>& operator ++() noexcept;
	Iterator<T> operator ++(int) noexcept;
	Iterator<T>& operator --() noexcept;
	Iterator<T> operator --(int) noexcept;

	Iterator<T> operator +(const difference_type i) const noexcept;
	Iterator<T>& operator +=(const difference_type i) noexcept;

	Iterator<T> operator -(const difference_type i) const noexcept;
	Iterator<T>& operator -=(const difference_type i) noexcept;

	difference_type operator -(const Iterator<T>& iter) const noexcept;
	difference_type distance(const Iterator<T>& other) const noexcept;
};

template <workable T>
Iterator<T> operator + (const typename Iterator<T>::difference_type i, const Iterator<T> iter) noexcept
{
	Iterator<T> res(*this);
	res += i;
	return res;
}

template <workable T>
Iterator<T> operator - (const typename Iterator<T>::difference_type i, Iterator<T> iter) noexcept
{
	Iterator<T> res(*this);
	res -= i;
	return res;
}

#include "Iterator.hpp"