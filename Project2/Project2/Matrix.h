#pragma once
#include <initializer_list>
#include <memory>
#include <ranges>
#include <algorithm>
#include "BasicMatrix.h"
#include "MatrixLine.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "Concepts.h"

template <workable T>
class Matrix : public BasicMatrix
{
	friend class Iterator<T>;
	friend class ConstIterator<T>;
	friend class ReverseIterator<T>;
	friend class ConstReverseIterator<T>;

public:
	using value_type = T;
	using iterator = Iterator<T>;
	using const_iterator = ConstIterator<T>;
	using size_type = size_t;
#pragma region constructors
	Matrix() : data(nullptr) {};
	Matrix(size_t n, size_t m);
	Matrix(size_t n, size_t m, T** matrix);
	explicit Matrix(const Matrix<T>& matrix);
	Matrix(Matrix<T>&& matrix) noexcept;
	Matrix(std::initializer_list<std::initializer_list<T>> list);

	template <convertible<T> U>
	Matrix(size_t n, size_t m, U** matrix);
	template <convertible<T> U>
	explicit Matrix(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix(std::initializer_list<std::initializer_list<U>> list);

	template <matrix_like_container<T> U>
	explicit Matrix(const U& container);
	template <container<T> U>
	Matrix(size_t n, size_t m, const U& container);

	template <iter_type<T> I>
	Matrix(size_t n, size_t m, I& iter1, I& iter2);
#pragma endregion 

	~Matrix() noexcept override;

#pragma region assignment
	Matrix<T>& operator =(const Matrix<T>& matrix);
	Matrix<T>& operator =(Matrix<T>&& matrix);
	Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> list);

	template <convertible<T> U>
	Matrix<T>& operator =(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix<T>& operator =(std::initializer_list<std::initializer_list<U>> list);
#pragma endregion 

#pragma region characteristics
	bool isEmpty() const;
	bool isZero() const;
	bool isIdentity() const;
	bool isSquare() const;
#pragma endregion

#pragma region special_matrix_funcs
	Matrix<T>& GetMatr(int row, int col);
	decltype(auto) Determinant();
	Matrix<T>& Mreverse();
	Matrix<T>& Transposition();
#pragma endregion	
	
	Matrix<T>& operator +(void);
	Matrix<T> operator -(void);

#pragma region add
	Matrix<T> operator +(const Matrix<T>& matrix) const;

	Matrix<T>& operator +=(const Matrix<T>& matrix);
	Matrix<T>& add(const Matrix<T>& matrix);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator +(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	Matrix<T>& operator +=(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix<T>& add(const Matrix<U>& matrix);
#pragma endregion

#pragma region add_num
	Matrix<T> operator +(const T& num) const;

	Matrix<T>& operator +=(const T& num);
	Matrix<T>& add_num(const T& num);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator +(const U num) const;

	template <convertible<T> U>
	Matrix<T>& operator +=(const U num);
	template <convertible<T> U>
	Matrix<T>& add_num(const U num);
#pragma endregion 

#pragma region sub
	Matrix<T> operator -(const Matrix<T>& matrix) const;

	Matrix<T>& operator -=(const Matrix<T>& matrix);
	Matrix<T>& sub(const Matrix<T>& matrix);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator -(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	Matrix<T>& operator -=(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix<T>& sub(const Matrix<U>& matrix);
#pragma endregion 

#pragma region sub_num
	Matrix<T> operator -(const T& num) const;

	Matrix<T>& operator -=(const T& num);
	Matrix<T>& sub_num(const T& num);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator -(const U num) const;

	template <convertible<T> U>
	Matrix<T>& operator -=(const U num);
	template <convertible<T> U>
	Matrix<T>& sub_num(const U num);
#pragma endregion 

#pragma region mul_matrix
	Matrix<T> operator *(const Matrix<T>& matrix);

	Matrix<T>& operator *=(const Matrix<T>& matrix);
	Matrix<T> mul_matrix(const Matrix<T>& matrix);
	
	template <convertible_in_any_direction <T> U>
	decltype(auto) operator *(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	Matrix<T>& operator *=(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix<T>& mul_matrix(const Matrix<U>& matrix);
#pragma endregion 

#pragma region mul_num
	Matrix<T> operator *(const T num) const;

	Matrix<T>& operator *=(const T num);
	Matrix<T>& mul_num(const T num);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator *(U num);

	template <convertible<T> U>
	Matrix<T>& operator *=(const U num);
	template <convertible<T> U>
	Matrix<T>& mul_num(const U num);
#pragma endregion 
	
#pragma region mul_by_elems
	Matrix<T> operator ^(const Matrix<T>& matrix) const;

	Matrix<T>& operator ^=(const Matrix<T>& matrix);
	Matrix<T>& mul_by_elems(const Matrix<T>& matrix);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator ^(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	Matrix<T>& operator ^=(const Matrix<U>& matrix);
	template <convertible<T> U>
	Matrix<T>& mul_by_elems(const Matrix<U>& matrix);
#pragma endregion 

#pragma region div_matrix
	Matrix<T> operator /(const Matrix<T>& matrix);

	Matrix<T>& operator /=(const Matrix<T>& matrix);
	Matrix<T> div_matrix(const Matrix<T>& matrix);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator /(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	decltype(auto) operator /=(const Matrix<U>& matrix);
	template <convertible<T> U>
	decltype(auto) div_matrix(const Matrix<U>& matrix);
#pragma endregion 

#pragma region div_num
	Matrix<T> operator /(const T& num) const;

	Matrix<T>& operator /=(const T& num);
	Matrix<T>& div_num(const T& num);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator /(const U num) const;

	template <convertible<T> U>
	Matrix<T>& operator /=(const U num);
	template <convertible<T> U>
	Matrix<T>& div_num(const U num);
#pragma endregion

#pragma region div_by_elems
	Matrix<T> operator |(const Matrix<T>& matrix) const;

	Matrix<T>& operator |=(const Matrix<T>& matrix);
	decltype(auto) div_by_elems(const Matrix<T>& matrix);

	template <convertible_in_any_direction <T> U>
	decltype(auto) operator |(const Matrix<U>& matrix) const;

	template <convertible<T> U>
	Matrix<T>& operator |=(const Matrix<U>& matrix);
	template <convertible<T> U>
	decltype(auto) div_by_elems(const Matrix<U>& matrix);
#pragma endregion 
	
	bool operator ==(const Matrix<T>& matrix) const;
	bool operator !=(const Matrix<T>& matrix) const;

	class MatrixLine
	{
		friend Matrix;
	private:
		MatrixLine(const Matrix<T>& parent, int row) : parent(parent), line(row) {  }
		const Matrix<T>& parent;
		int line;
	public:
		const T& operator [](int column) const
		{
			time_t err_time = time(nullptr);
			if (column >= this->parent.get_columns())
			{
				throw IndexError(__FILE__, __LINE__, err_time, "Index out of range");
			}
			return parent.data.get()[line * parent.get_columns() + column];
		}

		T& operator [](int column)
		{
			time_t err_time = time(nullptr);
			if (column >= this->parent.get_columns())
			{
				throw IndexError(__FILE__, __LINE__, err_time, "Index out of range");
			}
			return parent.data.get()[line * parent.get_columns() + column];
		}
	};
	const MatrixLine operator [](int row) const
	{
		time_t err_time = time(nullptr);
		if (this->check_validity() == false)
			throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
		if (row < 0 || row >= this->n)
			throw IndexError(__FILE__, __LINE__, err_time, "Invalid row index");
		return MatrixLine(*this, row);
	}

	MatrixLine operator [](int row)
	{
		time_t err_time = time(nullptr);
		if (this->check_validity() == false)
			throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
		if (row < 0 || row >= this->n)
			throw IndexError(__FILE__, __LINE__, err_time, "Invalid row index");
		return MatrixLine(*this, row);
	}

	T& get_value(int i, int j);
	template <convertible<T> U>
	void set_value(int i, int j, const U& value);
	bool check_validity() const noexcept;

#pragma region all_begin_end
	Iterator<T> begin();
	ConstIterator<T> begin() const;
	Iterator<T> end();
	ConstIterator<T> end() const;

	ConstIterator<T> cbegin() const;
	ConstIterator<T> cend() const;

	ReverseIterator<T> rbegin();
	ConstReverseIterator<T> rbegin() const;
	ReverseIterator<T> rend();
	ConstReverseIterator<T> rend() const;

	ConstReverseIterator<T> crbegin() const;
	ConstReverseIterator<T> crend() const;
#pragma endregion

private:
	std::shared_ptr<T[]> data;
#pragma region checks

	template <convertible<T> U>
	bool check_addability(const Matrix<U>& matrix) const  noexcept;
	template <convertible<T> U>
	bool check_multiplicability(const Matrix<U>& matrix) const noexcept;
#pragma endregion

};

template <workable T, convertible<T> U>
decltype(auto) operator * (const U& num, const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");

	Matrix<decltype(matrix[0][0] * num)> res(matrix.get_lines(), matrix.get_columns());
	std::ranges::transform(matrix, res.begin(), [&num](const T& x) { return x * num; });

	return res;
}

template <workable T, convertible<T> U>
decltype(auto) operator | (const U& num, const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	if (matrix.check_validity() == false)
		throw InvalidObject(__FILE__, __LINE__, err_time, "Invalid matrix");
	
	Matrix<decltype(matrix[0][0] / num)> res(matrix.get_lines(), matrix.get_columns());
	std::ranges::transform(matrix, res.begin(), [&num](const T& x) { return x / num; });

	return res;
}

template <workable T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
{
	time_t err_time = time(nullptr);
	int i = 0;
	for (auto const x : matrix)
	{
		if (i % matrix.get_columns() == 0 && i != 0)
			stream << std::endl;
		stream << x << " ";
		i++;
	};
	stream << std::endl;
	return stream;
}

#include "Matrix.hpp"