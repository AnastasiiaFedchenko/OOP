#pragma once
#include "../../matrix/transform_matrix.h"
#include "../base_object.h"

class Composite : public BaseObject
{
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject>& element);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>>& vector);

    virtual bool add(const std::shared_ptr<BaseObject>& element) override;
    virtual bool remove(const Iterator& iter) override;

    virtual void update_center() override;

    virtual bool is_visible() override;
    virtual bool is_composite() override;

    virtual My_Point get_center() const override;
    virtual void move_elems_to_origin(const My_Point& center) override;
    virtual void move_elems_to_center(const My_Point& center) override;
    virtual void transform_elems(const TransformMatrix& mtr) override;
    virtual void transform(const TransformMatrix& mtr, const My_Point& center) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    std::vector<std::shared_ptr<BaseObject>> elements;
};
