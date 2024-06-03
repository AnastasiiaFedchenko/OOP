#include "edge.h"

Edge::Edge(const std::size_t p1, const std::size_t p2)
{
	this->set_p1(p1);
	this->set_p2(p2);
}

std::size_t Edge::get_p1() const { return this->p1; }

std::size_t Edge::get_p2() const { return this->p2; }

void Edge::set_p1(const std::size_t i) { this->p1 = i; }

void Edge::set_p2(const std::size_t i) { this->p2 = i; }