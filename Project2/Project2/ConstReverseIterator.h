#pragma once
#include <memory>
#include "BasicIterator.h"
#include "Concepts.h"

#include "ReverseIterator.h"

template <workable T>
class Matrix;

template <workable T>
class ConstReverseIterator : public BasicIterator<T>
{
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = ptrdiff_t;
	using pointer = const T*;
	using reference = const T&;

	ConstReverseIterator() noexcept = default;
	explicit ConstReverseIterator(const Matrix<T>& matrix) noexcept;
	ConstReverseIterator(const ReverseIterator<T>& iter);
	ConstReverseIterator(const ConstReverseIterator<T>& iter) noexcept;
	ConstReverseIterator(ConstReverseIterator<T>&& iter) noexcept;

	ConstReverseIterator<T>& operator =(const ConstReverseIterator<T>& iter) noexcept;
	ConstReverseIterator<T>& operator =(ConstReverseIterator<T>&& iter) noexcept;

	//const T& operator *() const;
	//const T* operator ->() const;
	reference operator[](const difference_type i) const noexcept;

	ConstReverseIterator<T>& operator ++() noexcept;
	ConstReverseIterator<T> operator ++(int) noexcept;
	ConstReverseIterator<T>& operator --() noexcept;
	ConstReverseIterator<T> operator --(int) noexcept;

	ConstReverseIterator<T> operator +(const difference_type i) const noexcept;
	ConstReverseIterator<T>& operator +=(const difference_type i) noexcept;

	ConstReverseIterator<T> operator -(const difference_type i) const noexcept;
	ConstReverseIterator<T>& operator -=(const difference_type i) noexcept;

	difference_type operator -(const ConstReverseIterator<T>& iter) const noexcept;
	difference_type distance(const ConstReverseIterator<T>& other) const noexcept;
};

template <workable T>
ConstReverseIterator<T> operator + (const typename ConstReverseIterator<T>::difference_type i, const ConstReverseIterator<T> iter) noexcept
{
	ConstReverseIterator<T> res(*this);
	res += i;
	return res;
}

template <workable T>
ConstReverseIterator<T> operator - (const typename ConstReverseIterator<T>::difference_type i, ConstReverseIterator<T> iter) noexcept
{
	ConstReverseIterator<T> res(*this);
	res -= i;
	return res;
}

#include "ConstReverseIterator.hpp"