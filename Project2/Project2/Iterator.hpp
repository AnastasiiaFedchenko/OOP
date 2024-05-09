#pragma once
#include "Error.hpp"
#include "Iterator.h"

template<workable T>
class Iterator;

template <workable T>
Iterator<T>::Iterator(const Matrix<T>& matrix) noexcept : 
	BasicIterator<T>::BasicIterator(0, matrix.n * matrix.m)
{
	this->base = matrix.data;
}

template <workable T>
Iterator<T>::Iterator(const Iterator<T>& iter) noexcept : BasicIterator<T>::BasicIterator(iter)
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
Iterator<T>::Iterator(Iterator<T>&& iter) noexcept 
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
}

template <workable T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
Iterator<T>& Iterator<T>::operator=(Iterator<T>&& iter) noexcept
{
	this->base = iter.base;
	this->size = iter.size;
	this->index = iter.index;
	return *this;
}

template <workable T>
Iterator<T>& Iterator<T>::operator ++() noexcept
{
	this->index++;
	return *this;
}

template <workable T>
Iterator<T> Iterator<T>::operator ++(int) noexcept
{
	Iterator temp = *this;
	++(*this);
	return temp;
}

template <workable T>
Iterator<T>& Iterator<T>::operator --() noexcept
{
	this->index--;
	return *this;
}

template <workable T>
Iterator<T> Iterator<T>::operator --(int) noexcept
{
	Iterator temp = *this;
	--(*this);
	return temp;
}

template <workable T>
Iterator<T> Iterator<T>::operator +(const Iterator<T>::difference_type i) const noexcept
{
	Iterator<T> res(*this);
	res.index += i;
	return res;
}

template <workable T>
Iterator<T>& Iterator<T>::operator +=(const Iterator<T>::difference_type i) noexcept
{
	(*this).index += i;
	return *this;
}

template <workable T>
Iterator<T> Iterator<T>::operator -(const Iterator<T>::difference_type i) const noexcept
{
	this->index -= i;
	return *this;
}

template <workable T>
Iterator<T>& Iterator<T>::operator -=(const Iterator<T>::difference_type i) noexcept
{
	(*this).index -= i;
	return (*this);
}

template <workable T>
Iterator<T>::difference_type Iterator<T>::operator -(const Iterator<T>& iter) const noexcept
{
	Iterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
Iterator<T>::difference_type Iterator<T>::distance(const Iterator<T>& iter) const noexcept
{
	Iterator<T> res(*this);
	return res.index - iter.index;
}

template <workable T>
Iterator<T>::reference Iterator<T>::operator *()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return *(ptr_cpy.get() + (*this).index);
}

template <workable T>
Iterator<T>::pointer Iterator<T>::operator->()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return ptr_cpy.get() + (*this).index;
}

template <workable T>
const T* Iterator<T>::operator->() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return ptr_cpy.get() + (*this).index;
}

template <workable T>
const T& Iterator<T>::operator *() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
	std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
	return (*ptr_cpy.get() + (*this).index);
}/**/

template <workable T>
Iterator<T>::reference Iterator<T>::operator[](const Iterator<T>::difference_type i) const noexcept
{
	auto tmp = *this; 
	tmp += i; 
	return *tmp;
}