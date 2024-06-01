#pragma once
#include "Error.hpp"
#include "ConstIterator.h"

template<workable T>
class ConstIterator;

template <workable T>
ConstIterator<T>::ConstIterator(const Iterator<T>& iter): BasicIterator<T>(0, iter.size)
{
	this->base(*iter);
}

template <workable T>
ConstIterator<T>::ConstIterator(const Matrix<T>& matrix) noexcept : 
	BasicIterator<T>::BasicIterator(0, matrix.n * matrix.m)
{
	this->base = matrix.data;
}

template <workable T>
ConstIterator<T>::ConstIterator(const ConstIterator<T>& iter) noexcept : BasicIterator<T>::BasicIterator(iter)
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ConstIterator<T>::ConstIterator(ConstIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator=(const ConstIterator<T>& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator=(ConstIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

/*template <workable T>
const T& ConstIterator<T>::operator *() const
{
	time_t err_time = time(nullptr);
	if (!(*this))
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return *(ptr_cpy.get() + (*this).index);
}

template <workable T>
const T* ConstIterator<T>::operator ->() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return ptr_cpy.get() + (*this).index;
}*/

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator ++() noexcept
{
	this->index++;
	return *this;
}

template <workable T>
ConstIterator<T> ConstIterator<T>::operator ++(int) noexcept
{
	ConstIterator temp = *this;
	++(*this);
	return temp;
}

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator --() noexcept
{
	this->index--;
	return *this;
}

template <workable T>
ConstIterator<T> ConstIterator<T>::operator --(int) noexcept
{
	ConstIterator temp = *this;
	--(*this);
	return temp;
}

template <workable T>
ConstIterator<T> ConstIterator<T>::operator +(const ConstIterator<T>::difference_type i) const noexcept
{
	ConstIterator<T> res(*this);
	res.index += i;
	return res;
}

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator +=(const ConstIterator<T>::difference_type i) noexcept
{
	(*this).index += i;
	return *this;
}

template <workable T>
ConstIterator<T> ConstIterator<T>::operator -(const ConstIterator<T>::difference_type i) const noexcept
{
	this->index -= i;
	return *this;
}

template <workable T>
ConstIterator<T>& ConstIterator<T>::operator -=(const ConstIterator<T>::difference_type i) noexcept
{
	(*this).index -= i;
	return (*this);
}

template <workable T>
ConstIterator<T>::difference_type ConstIterator<T>::operator -(const ConstIterator<T>& iter) const noexcept
{
	ConstIterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
ConstIterator<T>::difference_type ConstIterator<T>::distance(const ConstIterator<T>& iter) const noexcept
{
	ConstIterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
ConstIterator<T>::reference ConstIterator<T>::operator[](const ConstIterator<T>::difference_type i) const noexcept

{
	auto tmp = *this;
	tmp += i;
	return *tmp;
}