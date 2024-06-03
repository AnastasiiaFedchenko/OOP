#pragma once
#include <utility>
#include <vector>

class TransformMatrix
{
public:
    TransformMatrix() = default;
    TransformMatrix(std::size_t n, std::size_t m);
    TransformMatrix(const TransformMatrix& temp);
    TransformMatrix(std::vector<std::vector<double>> temp);

    TransformMatrix& operator =(std::initializer_list<std::initializer_list<double>> list);
    TransformMatrix& operator=(const TransformMatrix& temp);
    TransformMatrix& operator=(TransformMatrix&& temp);
    TransformMatrix operator *(const TransformMatrix& temp);

    double get(std::size_t i, std::size_t j) const;
    void set(std::size_t i, std::size_t j, double value);
    std::size_t get_n() const;
    std::size_t get_m() const;

    ~TransformMatrix() = default;

private:
    std::vector<std::vector<double>> matrix;
};
