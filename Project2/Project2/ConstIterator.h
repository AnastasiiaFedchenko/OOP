#pragma once
#include <memory>
#include "BasicIterator.h"
#include "Concepts.h"

#include "Iterator.h"

template <workable T>
class Matrix;

template <workable T>
class ConstIterator : public BasicIterator<T>
{
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = ptrdiff_t;
	using pointer = const T*;
	using reference = const T&;

	ConstIterator() noexcept = default;
	explicit ConstIterator(const Matrix<T>& matrix) noexcept;
	ConstIterator(const Iterator<T>& iter);
	ConstIterator(const ConstIterator<T>& iter) noexcept;
	ConstIterator(ConstIterator<T>&& iter) noexcept;

	ConstIterator<T>& operator =(const ConstIterator<T>& iter) noexcept;
	ConstIterator<T>& operator =(ConstIterator<T>&& iter) noexcept;

	//const T& operator *() const;
	//const T* operator ->() const;
	reference operator[](const difference_type i) const noexcept;

	ConstIterator<T>& operator ++() noexcept;
	ConstIterator<T> operator ++(int) noexcept;
	ConstIterator<T>& operator --() noexcept;
	ConstIterator<T> operator --(int) noexcept;

	ConstIterator<T> operator +(const difference_type i) const noexcept;
	ConstIterator<T>& operator +=(const difference_type i) noexcept;

	ConstIterator<T> operator -(const difference_type i) const noexcept;
	ConstIterator<T>& operator -=(const difference_type i) noexcept;

	difference_type operator -(const ConstIterator<T>& iter) const noexcept;
	difference_type distance(const ConstIterator<T>& other) const noexcept;
};

template <workable T>
ConstIterator<T> operator + (const typename ConstIterator<T>::difference_type i, const ConstIterator<T> iter) noexcept
{
	ConstIterator<T> res(*this);
	res += i;
	return res;
}

template <workable T>
ConstIterator<T> operator - (const typename ConstIterator<T>::difference_type i, ConstIterator<T> iter) noexcept
{
	ConstIterator<T> res(*this);
	res -= i;
	return res;
}

#include "ConstIterator.hpp"