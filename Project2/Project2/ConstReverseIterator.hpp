#pragma once
#include "Error.hpp"
#include "ConstReverseIterator.h"

template<workable T>
class ConstReverseIterator;

template <workable T>
ConstReverseIterator<T>::ConstReverseIterator(const ReverseIterator<T>& iter): BasicIterator<T>(0, iter.size)
{
	this->base(*iter);
}

template <workable T>
ConstReverseIterator<T>::ConstReverseIterator(const Matrix<T>& matrix) noexcept :
	BasicIterator<T>::BasicIterator(0, matrix.n * matrix.m)
{
	this->base = matrix.data;
}

template <workable T>
ConstReverseIterator<T>::ConstReverseIterator(const ConstReverseIterator<T>& iter) noexcept : BasicIterator<T>::BasicIterator(iter)
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ConstReverseIterator<T>::ConstReverseIterator(ConstReverseIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator=(const ConstReverseIterator<T>& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator=(ConstReverseIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

/*template <workable T>
const T& ConstReverseIterator<T>::operator *() const
{
	time_t err_time = time(nullptr);
	if (!(*this))
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return *(ptr_cpy.get() + (*this).index);
}

template <workable T>
const T* ConstReverseIterator<T>::operator ->() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return ptr_cpy.get() + (*this).index;
}*/


template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator ++() noexcept
{
	this->index++;
	return *this;
}

template <workable T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator ++(int) noexcept
{
	ConstIterator temp = *this;
	++(*this);
	return temp;
}

template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator --() noexcept
{
	this->index--;
	return *this;
}

template <workable T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator --(int) noexcept
{
	ConstReverseIterator temp = *this;
	--(*this);
	return temp;
}

template <workable T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator +(const ConstReverseIterator<T>::difference_type i) const noexcept
{
	ConstReverseIterator<T> res(*this);
	res.index += i;
	return res;
}

template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator +=(const ConstReverseIterator<T>::difference_type i) noexcept
{
	(*this).index += i;
	return *this;
}

template <workable T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator -(const ConstReverseIterator<T>::difference_type i) const noexcept
{
	this->index -= i;
	return *this;
}

template <workable T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator -=(const ConstReverseIterator<T>::difference_type i) noexcept
{
	(*this).index -= i;
	return (*this);
}

template <workable T>
ConstReverseIterator<T>::difference_type ConstReverseIterator<T>::operator -(const ConstReverseIterator<T>& iter) const noexcept
{
	ConstReverseIterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
ConstReverseIterator<T>::difference_type ConstReverseIterator<T>::distance(const ConstReverseIterator<T>& iter) const noexcept
{
	ConstIterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
ConstReverseIterator<T>::reference ConstReverseIterator<T>::operator[](const ConstReverseIterator<T>::difference_type i) const noexcept

{
	auto tmp = *this;
	tmp += i;
	return *tmp;
}