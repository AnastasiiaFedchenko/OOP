#pragma once
#include <memory>
#include <vector>
#include "model/point.h"

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class BaseObject
{
public:
    BaseObject() {
        id = next_id++;
    };
    virtual ~BaseObject() = default;

    virtual bool add(const std::shared_ptr<BaseObject>&) { return false; };
    virtual bool remove(const Iterator&) { return false; };
    virtual void update_center() {};

    virtual bool is_visible() { return false; };
    virtual bool is_composite() { return  false; };

    virtual My_Point get_center() const = 0;
    virtual void move_elems_to_origin(const My_Point& p) { }
    virtual void move_elems_to_center(const My_Point& p) { }
    virtual void transform_elems(const TransformMatrix& temp) { }
    virtual void transform(const TransformMatrix& mtr, const My_Point& center_p) = 0;

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual std::size_t get_id() { return id; }

protected:
    std::size_t id;
    static std::size_t next_id;

    My_Point center_p;
};
