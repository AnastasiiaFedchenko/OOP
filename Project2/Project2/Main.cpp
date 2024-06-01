#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <string>
#include <ranges>
#include "Iterator.h"
#include "ConstIterator.h"
#include "ReverseIterator.h"
#include "Matrix.h"

template <std::random_access_iterator I>
void f(I &)
{
	std::cout << "It is std::random_access_iterator!" << std::endl;
}

int main()
{
	//Matrix<int> m0{};
	Matrix <double> m13{};
	double** d0{ new double* [4] { new double [3] {1.1, 7.7, 3.3}, new double [3] {4.4, 2.2, 3.3},
							 new double [3] {1.1, 0, 2.2}, new double [3] {3.3, 6.6, 4.4} } };
	int** d1{ new int* [4] { new int [3] {1, 7, 3}, new int [3] {4, 2, 3}, 
							 new int [3] {1, 0, 2}, new int [3] {3, 6, 4} } };
	int** d3{ new int* [3] { new int [5] {1, 6, 8, 4, 2}, new int [5] {5, 7, 2, 9, 3},
							 new int [5] {8, 9, 4, 1, 4} } };
	double** d2{ new double* [2] { new double [3] {6.1, 5.2, 4.3}, new double [3] {3.4, 2.5, 1.6} } };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << d1[i][j] << " ";
		std::cout << std::endl;
	}
	Matrix<double> m0(4, 3, d0);
	Matrix<int> m1(4, 3, d1);
	Matrix<int> m3(3, 5, d3);

	m13 = m0;
	std::cout << "m13 == m0\n" << (m13 == m0) << std::endl;
	std::cout << "m13\n" << m13;
	m13 += 1;
	std::cout << "m13 + 1\n" << m13;
	std::cout << "m13 is zero? " << (bool)m13.isZero() << std::endl;
	std::cout << "- m13\n" << -m13 << std::endl;

	std::cout << "wow\n" << m0 + m1;
	std::cout << std::endl; 
	std::cout << "m1:\n" << m1 << std::endl;
	std::cout << std::endl;
	m1 *= m3;
	//m1.Transposition();
	std::cout << std::endl;
	std::cout << "m1 T:\n" << m1 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "m3:\n" << m3 * 3.3 << std::endl;
	std::cout << std::endl;
	
	std::vector<std::vector<int>> array = { {1, 2, 3}, {4, 5, 6} };
	std::vector<int> array1 = { 1, 2, 3, 4, 5, 6 };
	std::deque<std::deque<int>> array2 = { {4, 5, 6}, {1, 2, 3}, {6, 6, 6}, {3, 2, 7} };

	Matrix<int> m14(3, 2, array1);

	std::cout << std::endl;
	std::cout << "m14\n" << m14 << std::endl;

	Matrix<double> m8(array2);
	Iterator b(m8.begin());
	ConstIterator cb(m8);
	ReverseIterator rb(m8);
	ConstReverseIterator crb(m8);
	if (b)
		b += 3;
	Iterator<double> e(b);
	e += 6;
	Matrix<double> m9(3, 2, b, e);/**/

	for (auto data : m8)
		printf("%lf ", data);

	std::cout << std::endl;	
	std::cout << "m8\n" << m8 << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "m9\n" << m9 << std::endl;
	std::cout << std::endl;

	std::cout << "b == true?" << (bool)b << std::endl;
	ptrdiff_t a = 0;
	std::cout << (typeid(e - b).name() == typeid(a).name()) << std::endl;
	auto iter = array.begin();
	f(b);
	f(cb);
	f(rb);
	f(crb);
	std::cout << (2 | m8) << std::endl;

	const Iterator i(m8.begin());
	std::cout << (*i) << std::endl;
	//const Matrix<int> m_const(4, 3, d1);
	//Iterator<int> iter = m_const.begin();
	//std::cout << (*iter) << std::endl;
	//m1 /= 0;
	/*m1 += m3;
	std::cout << std::endl;
	std::cout << "m1 += m3:\n" << m1 << std::endl;
	std::cout << std::endl;*/

	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << m1[i][j] << " ";
		std::cout << std::endl;
	}*/
	/*m0 = m1;
	std::cout << "m0 == m1 " << (m0 == m1) << std::endl;
	std::cout << "i = 0 j = 2 " << m0.get_value(0, 2) << std::endl;
	m0.set_value(0, 2, 9);
	std::cout << "m0: " << std::endl;
	std::cout << m0 << std::endl;*/

	/*Matrix<double> m2(2, 3, d2);
	std::cout << "m0 == m1 " << (m0 == m1) << std::endl;*/
	/*std::cout << "m1 / 3 :" << std::endl;
	std::cout << m1 / 2 << std::endl;
	std::cout << "m1 / 0.5 :" << std::endl;
	std::cout << m1 / 0.5 << std::endl*/;
	/*std::cout << "m1 :" << std::endl;
	std::cout << m1 << std::endl;
	std::cout << "m2 :" << std::endl;
	std::cout << m2 << std::endl;
	m1 += m2;
	std::cout << "m1 += m2 :" << std::endl;
	std::cout << m1 << std::endl;
	m2 += m0;
	std::cout << "m2 += m0 :" << std::endl;
	std::cout << m2 << std::endl;*/
	/*std::cout << "m1 :" << std::endl;
	std::cout << m1;
	std::cout << "Empty " << m1.isEmpty() << std::endl;
	std::cout << "Identity " << m1.isIdentity() << std::endl;
	std::cout << "Zero " << m1.isZero() << std::endl;
	m0 = m1;
	std::cout << "m0 :" << std::endl;
	std::cout << m0;
	m0 -= m1;
	m0 -= m1;
	std::cout << "m0 -= m1 -= m1 :" << std::endl;
	std::cout << m0;
	std::cout << "sum -m0 - m1:" << std::endl;
	std::cout << -m0 - m2;*/
}

