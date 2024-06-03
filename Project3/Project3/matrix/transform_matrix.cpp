#include "transform_matrix.h"

TransformMatrix::TransformMatrix(std::size_t n, std::size_t m)
{
	for (std::size_t i = 0; i < n; i++)
	{
		std::vector<double> temp(m, 0);
		this->matrix.push_back(temp);
	}
}

TransformMatrix::TransformMatrix(const TransformMatrix& temp) { (*this) = temp; }

TransformMatrix::TransformMatrix(std::vector<std::vector<double>> temp): matrix(temp){}

TransformMatrix& TransformMatrix::operator =(std::initializer_list<std::initializer_list<double>> list)
{
	for (auto iter_i = list.begin(); iter_i != list.end(); iter_i++)
	{
		std::vector<double> temp;
		for (auto iter_j = iter_i->begin(); iter_j != iter_i->end(); iter_j++)
			temp.push_back(*iter_j);
		this->matrix.push_back(temp);
	}
	return (*this);
}

TransformMatrix& TransformMatrix::operator=(const TransformMatrix& temp)
{
	(*this) = temp;
	return *this; 
}

TransformMatrix& TransformMatrix::operator=(TransformMatrix&& temp)
{
	(*this) = temp;
	return *this;
}

TransformMatrix TransformMatrix::operator *(const TransformMatrix& temp)
{
	TransformMatrix res(this->get_n(), temp.get_m());
	for (std::size_t i = 0; i < this->matrix.size(); i++)
	{
		for (size_t k = 0; k < temp.get_m(); k++)
		{
			double sum = 0;
			for (int t = 0; t < this->get_m(); t++)
				sum += (*this).get(i, t) * temp.get(t, k);
			res.set(i, k, sum);
		}
	}
	return res;
}

double TransformMatrix::get(std::size_t i, std::size_t j) const { return matrix[i][j]; }

void TransformMatrix::set(std::size_t i, std::size_t j, double value) { matrix[i][j] = value; }

std::size_t TransformMatrix::get_n() const { return matrix.size(); }

std::size_t TransformMatrix::get_m() const { return matrix[0].size(); }