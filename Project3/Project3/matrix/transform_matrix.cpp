#include "transform_matrix.h"

Transform& Transform::operator=(const Transform& temp)
{
	this->matrix = temp.matrix;
	return *this; 
}

Transform& Transform::operator=(Transform&& temp)
{
	(*this) = temp;
	return *this;
}

std::vector<std::vector<double>> Transform::mul(const std::vector<std::vector<double>>& temp1, 
	const std::vector<std::vector<double>>& temp2)
{
	std::vector<std::vector<double>>  res;
	for (std::size_t i = 0; i < temp1.size(); i++)
	{
		std::vector<double> line;
		for (size_t k = 0; k < temp2[0].size(); k++)
		{
			double sum = 0;
			for (int t = 0; t < temp1[0].size(); t++)
				sum += temp1[i][t] * temp2[t][k];
			line.push_back(sum);
		}
		res.push_back(line);
	}
	return res;
}

void Transform::imply(My_Point& p)
{
	std::vector<std::vector<double>> cur_place = { {p.get_x(), p.get_y(), p.get_z(), 1} };
	std::vector<std::vector<double>> new_place = mul(cur_place, matrix);
	p = My_Point(new_place[0][0], new_place[0][1], new_place[0][2]);
}
