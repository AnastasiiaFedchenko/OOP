#pragma once

class BaseReader
{
public:
    BaseReader(){}
    virtual ~BaseReader() = default;

    virtual void open() = 0;
    virtual void close() = 0;

    virtual bool is_open() = 0;
};
