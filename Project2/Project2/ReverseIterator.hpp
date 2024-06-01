#pragma once
#include "Error.hpp"
#include "ReverseIterator.h"

template<workable T>
class ReverseIterator;

template <workable T>
ReverseIterator<T>::ReverseIterator(const Matrix<T>& matrix) noexcept : 
	BasicIterator<T>::BasicIterator(matrix.n * matrix.m - 1, matrix.n * matrix.m)
{
	this->base = matrix.data;
}

template <workable T>
ReverseIterator<T>::ReverseIterator(const ReverseIterator<T>& iter) noexcept : BasicIterator<T>::BasicIterator(iter)
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ReverseIterator<T>::ReverseIterator(ReverseIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator=(const ReverseIterator<T>& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator=(ReverseIterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
ReverseIterator<T>::reference ReverseIterator<T>::operator *()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return *(ptr_cpy.get() + (*this).index);
}

template <workable T>
ReverseIterator<T>::pointer ReverseIterator<T>::operator->()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return ptr_cpy.get() + (*this).index;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator ++() noexcept
{
	this->index--;
	return *this;
}

template <workable T>
ReverseIterator<T> ReverseIterator<T>::operator ++(int) noexcept
{
	ReverseIterator<T> temp = *this;
	--(*this);
	return temp;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator --() noexcept
{
	this->index++;
	return *this;
}

template <workable T>
ReverseIterator<T> ReverseIterator<T>::operator --(int) noexcept
{
	ReverseIterator<T> temp = *this;
	++(*this);
	return temp;
}

template <workable T>
ReverseIterator<T> ReverseIterator<T>::operator +(const ReverseIterator<T>::difference_type i) const noexcept
{
	ReverseIterator<T> res(*this);
	res.index -= i;
	return res;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator +=(const ReverseIterator<T>::difference_type i) noexcept
{
	(*this).index -= i;
	return *this;
}

template <workable T>
ReverseIterator<T> ReverseIterator<T>::operator -(const ReverseIterator<T>::difference_type i) const noexcept
{
	this->index += i;
	return *this;
}

template <workable T>
ReverseIterator<T>& ReverseIterator<T>::operator -=(const ReverseIterator<T>::difference_type i) noexcept
{
	(*this).index += i;
	return (*this);
}

template <workable T>
ReverseIterator<T>::difference_type ReverseIterator<T>::operator -(const ReverseIterator<T>& iter) const noexcept
{
	ReverseIterator<T> res(*this);
	return res.index + iter.index;
}

template <workable T>
ReverseIterator<T>::difference_type ReverseIterator<T>::distance(const ReverseIterator<T>& iter) const noexcept
{
	ReverseIterator<T> res(*this);
	return res.index + iter.index;
}

template <workable T>
ReverseIterator<T>::reference ReverseIterator<T>::operator[](const ReverseIterator<T>::difference_type i) const noexcept
{
	auto tmp = *this; 

	tmp += i; 
	return *tmp;
}