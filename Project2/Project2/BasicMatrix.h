#pragma once

class BasicMatrix
{
public:
	explicit BasicMatrix() : n(0), m(0) {};
	// базовый конструктор копирования (лекция 7)
	explicit BasicMatrix(const BasicMatrix& old) : n(0), m(0) {};
	virtual ~BasicMatrix() = default;
	
	int get_lines() const { return n; }
	int get_columns() const { return m; }
	virtual bool isEmpty() const = 0;
	virtual bool isZero() const = 0;
	virtual bool isIdentity() const = 0;
	
protected:
	int n;
	int m;
};
