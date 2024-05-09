#pragma once
#include <time.h>
#include <ranges>
#include "Matrix.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include "Error.hpp"
#include "Concepts.h"

template <workable T>
class Matrix;

#pragma region all_begin_end
template <workable T>
Iterator<T> Matrix<T>::begin()
{
	Iterator<T> iter(*this);
	return iter;
}
template <workable T>
Iterator<T> Matrix<T>::end()
{
	Iterator<T> iter(*this);
	return iter + (ptrdiff_t)(this->n * this->m);
}

template <workable T>
ConstIterator<T> Matrix<T>::begin() const
{
	ConstIterator<T> iter(*this);
	return iter;
}
template <workable T>
ConstIterator<T> Matrix<T>::end() const
{
	ConstIterator<T> iter(*this);
	return iter + (ptrdiff_t)(this->n * this->m);
}

template <workable T>
ConstIterator<T> Matrix<T>::cbegin() const
{
	ConstIterator<T> iter(*this);
	return iter;
}
template <workable T>
ConstIterator<T> Matrix<T>::cend() const
{
	ConstIterator<T> iter(*this);
	return iter + (this->n * this->m);
}

template <workable T>
ReverseIterator<T> Matrix<T>::rbegin()
{
	ReverseIterator<T> iter(*this);
	return iter;
}
template <workable T>
ReverseIterator<T> Matrix<T>::rend()
{
	ReverseIterator<T> iter(*this);
	return iter + (this->n * this->m);
}

template <workable T>
ConstReverseIterator<T> Matrix<T>::rbegin() const
{
	Iterator<T> iter(*this);
	return iter;
}
template <workable T>
ConstReverseIterator<T> Matrix<T>::rend() const
{
	Iterator<T> iter(*this);
	return iter + (this->n * this->m);
}

template <workable T>
ConstReverseIterator<T> Matrix<T>::crbegin() const
{
	ConstReverseIterator<T> iter(*this);
	return iter;
}
template <workable T>
ConstReverseIterator<T> Matrix<T>::crend() const
{
	ConstReverseIterator<T> iter(*this);
	return iter + (this->n * this->m);
}
#pragma endregion

#pragma region constructors
template <workable T>
Matrix<T>::Matrix(size_t n, size_t m)
{
	time_t err_time = time(nullptr);
	if ((n <= 0) || (m <= 0))
	{
		throw IndexError(__FILE__, __LINE__, err_time, "Incorrect matrix size");
	}
	this->n = n;
	this->m = m;
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
}

template <workable T>
Matrix<T>::Matrix(size_t n, size_t m, T** matrix) : Matrix(n, m)
{
	Iterator<T> iter_to = this->begin();
	for (int i = 0; iter_to != this->end() && i < n; i++)
		for (int j = 0; iter_to != this->end() && j < m; iter_to++, j++)
			(*iter_to) = matrix[i][j];
}

template <workable T>
Matrix<T>::Matrix(const Matrix<T>& matrix) : Matrix(matrix.n, matrix.m)
{
	std::ranges::copy(matrix, this->begin());
}

template <workable T>
Matrix<T>::Matrix(Matrix<T>&& matrix) noexcept
{
	this->n = matrix.get_lines();
	this->m = matrix.get_columns();
	this->data = matrix.data;
}

template <workable T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) : Matrix(list.size(), list.begin()->size())
{
	time_t err_time = time(nullptr);
	if ((list.size() <= 0) || (list.begin()->size() <= 0))
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect matrix size");

	Iterator<T> iter_to = this->begin();
	auto iter_i = list.begin();
	for (; iter_i != list.end() && iter_to != this->end(); iter_i++)
	{
		auto iter_j = iter_i->begin();
		for (; iter_j != iter_i->end() && iter_to != this->end(); iter_j++, iter_to++)
			(*iter_to) = (*iter_j);
	}
}

template <workable T>
template <convertible<T> U>
Matrix<T>::Matrix(size_t n, size_t m, U** matrix) : Matrix(n, m)
{
	Iterator<T> iter_to = this->begin();
	for (int i = 0; iter_to != this->end() && i < n; i++)
		for (int j = 0; iter_to != this->end() && j < m; iter_to++, j++)
			(*iter_to) = (T)matrix[i][j];
}

template <workable T>
template <convertible<T> U>
Matrix<T>::Matrix(const Matrix<U>& matrix) : Matrix(matrix.get_lines, matrix.get_columns)
{
	std::ranges::copy(matrix, this->begin());
}

template <workable T>
template <convertible<T> U>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<U>> list) : Matrix(list.size(), list.begin()->size())
{
	time_t err_time = time(nullptr);
	if ((list.size() <= 0) || (list.begin()->size() <= 0))
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect matrix size");
	}
	Iterator<T> iter_to = this->begin();
	auto iter_i = list.begin();
	for (; iter_i != list.end() && iter_to != this->end(); iter_i++)
	{
		auto iter_j = iter_i->begin();
		for (; iter_j != iter_i->end() && iter_to != this->end(); iter_j++, iter_to++)
			(*iter_to) = (T)(*iter_j);
	}
}

template <workable T>
template <matrix_like_container<T> U>
Matrix<T>::Matrix(const U& container) : Matrix(container.size(), container[0].size())
{
	Iterator<T> beg = begin();

	for (auto data_iter : container)
	{
		for (auto data : data_iter)
		{
			*beg = data;
			++beg;
		}
	}
}

template <workable T>
template <container<T> U>
Matrix<T>::Matrix(size_t n, size_t m, const U& container) : Matrix(n, m)
{
	std::ranges::copy(container, this->begin());
}

template <workable T>
template <iter_type<T> I>
Matrix<T>::Matrix(size_t n, size_t m, I& iter1, I& iter2) : Matrix<T>::Matrix(n, m)
{
	time_t err_time = time(nullptr);
	if (iter1.check_validity() == false || iter2.check_validity() == false || iter2 < iter1)
		throw InvalidIterator(__FILE__, __LINE__, err_time, "Incorrect iterator");
	Iterator<T> res_iter = (*this).begin();
	for (; iter1 != iter2 && res_iter != (*this).end(); iter1++, res_iter++)
		(*res_iter) = (*iter1);
}

#pragma endregion

template <workable T>
Matrix<T>::~Matrix() noexcept
{
	if (this->data)
		data.reset();
}

#pragma region assignment
template <workable T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (matrix.check_validity() == false)
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect source matrix");
	}
	this->n = matrix.n;
	this->m = matrix.m;
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
	std::ranges::copy(matrix, this->begin());
	return *this;
}

template <workable T>
Matrix<T>& Matrix<T>::operator =(Matrix<T>&& matrix)
{

	time_t err_time = time(nullptr);
	if (matrix.check_validity() == false)
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect source matrix");
	}
	this->n = matrix.n;
	this->m = matrix.m;
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
	this->data = matrix.data;
	matrix.data = nullptr;
	return *this;
}

template <workable T>
Matrix<T>& Matrix<T>::operator =(std::initializer_list<std::initializer_list<T>> list)
{
	time_t err_time = time(nullptr);
	if ((list.size() <= 0) || (list.begin()->size() <= 0))
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect matrix size");
	}
	this->n = list.size();
	this->m = list.begin()->size();
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
	Iterator<T> iter_to = this->begin();
	auto iter_i = list.begin();
	for ( ; iter_i != list.end() && iter_to != this->end(); iter_i++)
	{
		auto iter_j = iter_i->begin();
		for ( ; iter_j != iter_i->end() && iter_to != this->end(); iter_j++, iter_to++)
			(*iter_to) = *iter_j;
	}
	return *this;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator =(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (matrix.check_validity() == false)
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect source matrix");
	}
	this->n = matrix.get_lines();
	this->m = matrix.get_columns();
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
	std::ranges::copy(matrix, this->begin());
	return *this;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator =(std::initializer_list<std::initializer_list<U>> list)
{
	time_t err_time = time(nullptr);
	if ((list.size() <= 0) || (list.begin()->size() <= 0))
	{
		throw InvalidObject(__FILE__, __LINE__, err_time, "Incorrect matrix size");
	}
	this->n = list.size();
	this->m = list.begin()->size();
	try
	{
		this->data = std::make_shared<T[]>(this->n * this->m);
	}
	catch (std::bad_alloc)
	{
		throw MemoryError(__FILE__, __LINE__, err_time, "Allocation error");
	}
	Iterator<T> iter_to = this->begin();
	auto iter_i = list.begin();
	for (; iter_i != list.end() && iter_to != this->end(); iter_i++)
	{
		auto iter_j = iter_i->begin();
		for (; iter_j != iter_i->end() && iter_to != this->end(); iter_j++, iter_to++)
			(*iter_to) = (T)(*iter_j);
	}
	return *this;
}
#pragma endregion

#pragma region characteristics
template <workable T>
bool Matrix<T>::isEmpty() const
{
	return (this->n == 0 || this->m == 0) ? true : false;
}

template <workable T>
bool Matrix<T>::isIdentity() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	bool is_identity = true;
	for (ConstIterator<T> iter = this->begin(); iter != this->end() && is_identity; iter++)
	{
		if ((int)(iter.get_index() / this->n) == (int)(iter.get_index() % n) && (*iter) != 1)
			is_identity = false;
		if ((int)(iter.get_index() / this->n) != (int)(iter.get_index() % n) && (*iter) != 0)
			is_identity = false;
	}
	return is_identity;
}

template <workable T>
bool Matrix<T>::isZero() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	return (std::ranges::all_of(*this, [](const T& x) { return x == 0; })) ? true : false;
}

template <workable T>
bool Matrix<T>::isSquare() const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	return (this->n == this->m) ? true : false;
}
#pragma endregion

#pragma region checks
template <workable T>
bool Matrix<T>::check_validity() const noexcept
{
	bool valid = true;
	if (this->n <= 0 || this->m <= 0)
		valid = false;
	return valid;
}

template <workable T>
template <convertible<T> U>
bool Matrix<T>::check_addability(const Matrix<U>& matrix) const noexcept
{
	bool addable = true;
	if (this->n != matrix.get_lines() || this->m != matrix.get_columns())
		addable = false;
	return addable;
}

template <workable T>
template <convertible<T> U>
bool Matrix<T>::check_multiplicability(const Matrix<U>& matrix) const noexcept
{
	bool multipliable = true;
	if (this->m != matrix.get_lines())
		multipliable = false;
	return multipliable;
}
#pragma endregion

#pragma region special_matrix_funcs

// Получение матрицы без i-й строки и j-го столбца
template <workable T>
Matrix<T>& Matrix<T>::GetMatr(int row, int col) {
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	if (row < 0 || col < 0 || row >= this->n || col >= this->m)
		throw IndexError(__FILE__, __LINE__, err_time, "Invalid index of row or column");
	int di, dj;
	Matrix<T> p(this->n - 1, this->m - 1);
	di = 0;
	for (int i = 0; i < this->n - 1; i++)
	{
		if (i == row)
			di = 1;
		dj = 0;
		for (int j = 0; j < this->m - 1; j++) 
		{
			if (j == col)
				dj = 1;
			p.set_value(i, j) = (*this)[i + di][j + dj];
		}
	}
	return p;
}

template <workable T>
decltype(auto) Matrix<T>::Determinant()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	if (this->n != this->m)
		throw InvalidObject(__FILE__, __LINE__, err_time, "it should be square");

	if (n == 2)
		return data[0] * data[3] - data[2] * data[1];
	if (n == 1)
		return (*this)[0][0];

	Matrix<T> tmp(n - 1, m - 1);
	T res = 0;

	for (size_t i = 0; i < n; i++)
	{
		T minor = tmp.GetMatr(0, i).Determinant;

		if (i % 2 == 1)
			minor = -minor;

		res += minor * data[i];
	}

	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::Mreverse()
{

	Matrix<T> res(n, m);
	Matrix<T> tmp(n - 1, m - 1);
	T value = 0;

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			T minor = tmp.GetMatr(0, i).Determinant;

			if ((i + j) % 2 == 1)
				value = -value;

			res.data[j * m + i] = value;
		}

	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::Transposition()
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	Matrix<T> res(this->m, this->n);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[j][i] = (*this)[i][j];
	(*this) = res;
	return (*this);
}

#pragma endregion

template <workable T>
Matrix<T>& Matrix<T>::operator +(void)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	return *this;
}

template <workable T>
Matrix<T> Matrix<T>::operator -(void)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Empty or invalid matrix");
	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [](const T& x) { return -x; });
	return res;
}

#pragma region add
template <workable T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<T> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] + matrix[i][j];
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) + (*iter_2);
	return *this;
}

template <workable T>
Matrix<T>& Matrix<T>::add(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) + (*iter_2);
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator +(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<decltype((*this)[0][0] + matrix[0][0])> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] + matrix[i][j];
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator +=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<U> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) + (T)(*iter_2);
	return *this;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::add(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) + (T)(*iter_2);
	return (*this);
}
#pragma endregion

#pragma region add_num
template <workable T>
Matrix<T> Matrix<T>::operator +(const T& num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x + num; });
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator +=(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x + num; });
	return (*this);
}

template <workable T>
Matrix<T>& Matrix<T>::add_num(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x + num; });
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator +(const U num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<decltype((*this)[0][0] + num)> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x + num; });
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator +=(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Matrix<decltype((*this)[0][0] + num)> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x + num; });
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::add_num(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Matrix<decltype((*this)[0][0] + num)> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x + num; });
	(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region sub
template <workable T>
Matrix<T> Matrix<T>::operator -(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<T> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] - matrix[i][j];
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) - (*iter_2);
	return *this;
}

template <workable T>
Matrix<T>& Matrix<T>::sub(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) - (*iter_2);
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator -(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot subtract matrixes of different sizes");
	Matrix<decltype((*this)[0][0] - matrix[0][0])> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] - matrix[i][j];
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator -=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot subtract matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<U> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) - (T)(*iter_2);
	return *this;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::sub(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot subtract matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) - (T)(*iter_2);
	return (*this);
}
#pragma endregion 

#pragma region sub_num
template <workable T>
Matrix<T> Matrix<T>::operator -(const T& num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();
	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator -=(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();
	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	(*this) = res;
	return (*this);
}

template <workable T>
Matrix<T>& Matrix<T>::sub_num(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();
	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator -(const U num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();

	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator -=(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();
	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::sub_num(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	Iterator<T> iter_1 = this->begin();
	Matrix<decltype((*iter_1) - num)> res(this->n, this->m);
	Iterator<decltype((*iter_1) - num)> iter_res = res.begin();
	for (; iter_1 != this->end() && iter_res != res.end(); iter_1++, iter_res++)
		(*iter_res) = (*iter_1) - num;
	(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region mul_matrix

template <workable T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res(this->n, matrix.get_columns());

	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0;
			for (int t = 0; t < this->get_columns(); t++)
				sum += (*this)[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}
	}
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res(this->n, matrix.get_columns());

	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0; 
			for (int t = 0; t < this->get_columns(); t++)
				sum += (*this)[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}
	}
	(*this) = res;
	return (*this);
}

template <workable T>
Matrix<T> Matrix<T>::mul_matrix(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res(this->n, matrix.get_columns());

	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0;
			for (int t = 0; t < this->get_columns(); t++)
				sum += this[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}
	}
	(*this) = res;
	return *this;
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator *(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<decltype((*this)[0][0] * matrix[0][0])> res(this->n, matrix.get_columns());
		
	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0;
			for (int t = 0; t < this->get_columns(); t++)
				sum += (*this)[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}	
	}
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator *=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res(this->n, matrix.get_columns());

	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0;
			for (int t = 0; t < this->get_columns(); t++)
				sum += (*this)[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}
	}
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::mul_matrix(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res(this->n, matrix.get_columns());

	for (int i = 0; i < this->get_lines(); i++)
	{
		for (int k = 0; k < matrix.get_columns(); k++)
		{
			T sum = 0;
			for (int t = 0; t < this->get_columns(); t++)
				sum += (*this)[i][t] * matrix[t][k];
			res.set_value(i, k, sum);
		}
	}
	(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region mul_num
template <workable T>
Matrix<T> Matrix<T>::operator *(const T num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x * num; });
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator *=(const T num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	return (*this);
}

template <workable T>
Matrix<T>& Matrix<T>::mul_num(const T num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator *(U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<decltype((*this)[0][0] * num)> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x * num; });
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator *=(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	//Matrix<decltype((*this)[0][0] * num)> res(this->n, this->m);
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	//(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::mul_num(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	
	//Matrix<decltype((*this)[0][0] * num)> res(this->n, this->m);
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	//(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region mul_by_elems
template <workable T>
Matrix<T> Matrix<T>::operator ^(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<T> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] * matrix[i][j];
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator ^=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) * (*iter_2);
	return *this;
}

template <workable T>
Matrix<T>& Matrix<T>::mul_by_elems(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) * (*iter_2);
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator ^(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<decltype((*this)[0][0] + matrix[0][0])> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			res[i][j] = (*this)[i][j] * matrix[i][j];
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator ^=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<U> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) * (T)(*iter_2);
	return *this;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::mul_by_elems(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		(*iter_1) = (*iter_1) * (T)(*iter_2);
	return (*this);
}
#pragma endregion

#pragma region div_num
template <workable T>
Matrix<T> Matrix<T>::operator /(const T& num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x / num; });
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator /=(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	
	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x / num; });
	(*this) = res;
	return (*this);
}

template <workable T>
Matrix<T>& Matrix<T>::div_num(const T& num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	
	Matrix<T> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x / num; });
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator /(const U num) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (num == 0)
		throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");

	Matrix<decltype((*this)[0][0] / num)> res(this->n, this->m);
	std::ranges::transform(*this, res.begin(), [&num](const T& x) { return x / num; });
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator /=(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (num == 0)
		throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");

	//Matrix<decltype((*this)[0][0] * num)> res(this->n, this->m);
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	//(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::div_num(const U num)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (num == 0)
		throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
	
	//Matrix<decltype((*this)[0][0] * num)> res(this->n, this->m);
	std::ranges::transform(*this, this->begin(), [&num](const T& x) { return x * num; });
	//(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region div_matrix

template <workable T>
Matrix<T> Matrix<T>::operator /(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res = (*this) * matrix.Mreverse(matrix.m);
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator /=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res = (*this) * matrix.Mreverse(matrix.m);
	(*this) = res;
	return res;
}

template <workable T>
Matrix<T> Matrix<T>::div_matrix(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<T> res = (*this) * matrix.Mreverse(matrix.m);
	(*this) = res;
	return res;
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator /(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<decltype((*this)[0][0] * matrix[0][0])> res = (*this) * matrix.Mreverse(matrix.m);
	return res;
}

template <workable T>
template <convertible<T> U>
decltype(auto) Matrix<T>::operator /=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<decltype((*this)[0][0] * matrix[0][0])> res = (*this) * matrix.Mreverse(matrix.m);
	(*this) = res;
	return (*this);
}

template <workable T>
template <convertible<T> U>
decltype(auto) Matrix<T>::div_matrix(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_multiplicability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot multiply matrixes of such sizes");
	Matrix<decltype((*this)[0][0] * matrix[0][0])> res = (*this) * matrix.Mreverse(matrix.m);
	(*this) = res;
	return (*this);
}
#pragma endregion

#pragma region div_by_elems
template <workable T>
Matrix<T> Matrix<T>::operator |(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<T> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if (matrix[i][j] == 0) 
				throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
			else
				res[i][j] = (*this)[i][j] / matrix[i][j];
	return res;
}

template <workable T>
Matrix<T>& Matrix<T>::operator |=(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		if ((*iter_2) == 0)
			throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
		else
			(*iter_1) = (*iter_1) / (*iter_2);
	return *this;
}

template <workable T>
decltype(auto) Matrix<T>::div_by_elems(const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		if ((*iter_2) == 0)
			throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
		else
			(*iter_1) = (*iter_1) / (*iter_2);
	return (*this);
}

template <workable T>
template <convertible_in_any_direction <T> U>
decltype(auto) Matrix<T>::operator |(const Matrix<U>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Matrix<decltype((*this)[0][0] + matrix[0][0])> res(this->n, this->m);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if (matrix[i][j] == 0)
				throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
			else
				res[i][j] = (*this)[i][j] / matrix[i][j];
	return res;
}

template <workable T>
template <convertible<T> U>
Matrix<T>& Matrix<T>::operator |=(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<U> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		if ((*iter_2) == 0)
			throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
		else
			(*iter_1) = (T)((*iter_1) / (*iter_2));
	return *this;
}

template <workable T>
template <convertible<T> U>
decltype(auto) Matrix<T>::div_by_elems(const Matrix<U>& matrix)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (this->check_addability(matrix) == false)
		throw DifferentSizeMatrixes(__FILE__, __LINE__, err_time, "Cannot add matrixes of different sizes");
	Iterator<T> iter_1 = this->begin();
	Iterator<T> iter_2 = matrix.begin();
	for (; iter_1 != this->end() && iter_2 != matrix.end(); iter_1++, iter_2++)
		if ((*iter_2) == 0)
			throw ZeroDivError(__FILE__, __LINE__, err_time, "Cannot divide by zero");
		else
			(*iter_1) = (T)((*iter_1) / (*iter_2));
	return (*this);
}
#pragma endregion

template <workable T>
bool Matrix<T>::operator ==(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	return (std::ranges::equal(*this, matrix)) ? true : false;
}
template <workable T>
bool Matrix<T>::operator !=(const Matrix<T>& matrix) const
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false || matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	return (std::ranges::equal(*this, matrix)) ? false : true;
}

template <workable T>
T& Matrix<T>::get_value(int i, int j)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (i < 0 || j < 0 || i >= this->n || j >= this->m)
		throw IndexError(__FILE__, __LINE__, err_time, "Invalid index");
	Iterator<T> iter_1 = this->begin();
	iter_1 += (i * this->m + j);
	return (*iter_1);
}

template <workable T>
template <convertible<T> U>
void Matrix<T>::set_value(int i, int j, const U& value)
{
	time_t err_time = time(nullptr);
	if (this->check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	if (i < 0 || j < 0 || i >= this->n || j >= this->m)
		throw IndexError(__FILE__, __LINE__, err_time, "Invalid index");
	Iterator<T> iter_1 = this->begin();
	iter_1 += (i * this->m + j);
	(*iter_1) = (T)value;
}
