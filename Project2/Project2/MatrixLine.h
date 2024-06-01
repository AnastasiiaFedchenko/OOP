#pragma once
#include "Matrix.h"
#include "Error.hpp"
#include "Concepts.h"
#include <time.h>
#include <concepts>

template <workable T>
class Matrix;

/*template <workable T>
class MatrixLine
{
	friend Matrix<T>;
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
};*/