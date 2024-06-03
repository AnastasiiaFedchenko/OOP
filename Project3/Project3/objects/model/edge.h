#pragma once
#include <cstddef>

class Edge 
{
public:
	Edge() = default;
    Edge(const std::size_t p1, const std::size_t p2);
    Edge(const Edge& edge) = default;

    ~Edge() = default;

    std::size_t get_p1() const;
    std::size_t get_p2() const;

    void set_p1(const std::size_t i);
    void set_p2(const std::size_t i);

private:
    std::size_t p1;
    std::size_t p2;
};
