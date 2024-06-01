#pragma once
#include "Error.hpp"
#include "Concepts.h"

template <workable T>
class BasicIterator
{
public:
    operator bool() const noexcept
    {
        bool valid = true;
        if (this->index < 0 || this->index > this->size)
            valid = false;
        if (!this->base.lock())
            valid = false;
        return valid;
    }
    const T& operator *() const
    {
        time_t err_time = time(nullptr);
        if (!(*this))
            throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
        std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
        return *(ptr_cpy.get() + (*this).index);
    }
    const T* operator ->() const
    {
        time_t err_time = time(nullptr);
        if (this->check_validity() == false)
            throw InvalidIterator(__FILE__, __LINE__, err_time, "Invalid iterator");
        std::shared_ptr<T[]> ptr_cpy = std::shared_ptr<T[]>(this->base.lock());
        return ptr_cpy.get() + (*this).index;
    }
    
    auto operator <=>(const BasicIterator<T>& other) const noexcept
    { return (*this).index <=> other.index; }
    bool operator ==(const BasicIterator<T>& other) const noexcept
    { return this->index == other.index; }
    bool operator !=(const BasicIterator<T>& other) const noexcept
    { return this->index != other.index; }

    bool check_validity() const noexcept
    {
        bool valid = true;
        if (this->index < 0 || this->index > this->size)
            valid = false;
        if (!this->base.lock())
            valid = false;
        return valid;
    }
    size_t get_index() const noexcept
    {
        return this->index;
    }

    virtual ~BasicIterator() = default;
protected:
    std::weak_ptr<T[]> base;
    size_t index = 0;
    size_t size = 0;

    BasicIterator() noexcept = default;
    explicit BasicIterator(const BasicIterator<T>& iter) noexcept
    {
        base = iter.base;
        size = iter.size;
        index = iter.index;
    }

    explicit BasicIterator(size_t index, size_t size) noexcept : index(index), size(size) {};
};