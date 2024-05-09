#pragma once
#include <memory>
#include "BasicIterator.h"
#include "Concepts.h"


template <workable T>
class Matrix;

template <workable T>
class ReverseIterator : public BasicIterator<T>
{
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

	ReverseIterator() noexcept = default;
	explicit ReverseIterator(const Matrix<T>& matrix) noexcept;
	ReverseIterator(const ReverseIterator<T>& iter) noexcept;
	ReverseIterator(ReverseIterator<T>&& iter) noexcept;

	ReverseIterator<T>& operator =(const ReverseIterator<T>& iter) noexcept;
	ReverseIterator<T>& operator =(ReverseIterator<T>&& iter) noexcept;

	reference operator*();
	pointer operator->();
	reference operator[](const difference_type i) const noexcept;

	ReverseIterator<T>& operator ++() noexcept;
	ReverseIterator<T> operator ++(int) noexcept;
	ReverseIterator<T>& operator --() noexcept;
	ReverseIterator<T> operator --(int) noexcept;

	ReverseIterator<T> operator +(const difference_type i) const noexcept;
	ReverseIterator<T>& operator +=(const difference_type i) noexcept;

	ReverseIterator<T> operator -(const difference_type i) const noexcept;
	ReverseIterator<T>& operator -=(const difference_type i) noexcept;

	difference_type operator -(const ReverseIterator<T>& iter) const noexcept;
	difference_type distance(const ReverseIterator<T>& other) const noexcept;
};

template <workable T>
ReverseIterator<T> operator + (const typename ReverseIterator<T>::difference_type i, const ReverseIterator<T> iter) noexcept
{
	Iterator<T> res(*this);
	res += i;
	return res;
}

template <workable T>
ReverseIterator<T> operator - (const typename ReverseIterator<T>::difference_type i, ReverseIterator<T> iter) noexcept
{
	Iterator<T> res(*this);
	res -= i;
	return res;
}

#include "ReverseIterator.hpp"