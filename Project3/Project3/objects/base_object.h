#pragma once
#include <memory>
#include <vector>
#include "../matrix/transform_matrix.h"
#include "../visitor/abstract_visitor.h"
#include "model/point.h"

class BaseObject
{
public:
    BaseObject() {
        id = next_id++;
    };
    virtual ~BaseObject() = default;

    virtual void update_center() {};

    virtual bool is_visible() { return false; };

    virtual My_Point get_center() const = 0;
    virtual void transform(Transform& mtr, const My_Point& center_p) = 0;
    virtual void accept(std::shared_ptr<AbstractVisitor> visitor)
    {
        visitor->visit(*this);
    }

    virtual std::size_t get_id() { return id; }

protected:
    std::size_t id;
    static std::size_t next_id;

    My_Point center_p;
};
