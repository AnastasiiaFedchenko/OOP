#pragma once

#include <string>
#include <exception>

class BaseException : public std::exception
{
public:
    explicit BaseException(std::string &msg) : msg(msg) {}

    const char *what() const noexcept override { return "Error!";}
    const std::string &get_info() const noexcept { return msg;}

protected:
    std::string msg;
};

class ObjectException : public std::exception
{
public:
    explicit ObjectException(std::string& msg) : msg(msg) {}

    const char* what() const noexcept override { return "Problem with object!"; }
    const std::string& get_info() const noexcept { return msg; }

protected:
    std::string msg;
};


class CameraException : public BaseException
{
public:
    explicit CameraException(std::string &msg) : BaseException(msg) {}
    const char *what() const noexcept override
    {
        return "Problem with camera!";
    }
};

class ModelException : public BaseException
{
public:
    explicit ModelException(std::string &msg) : BaseException(msg) {}
    const char *what() const noexcept override
    {
        return "Problem with model!";
    }
};

class LoadException : public BaseException
{
public:
    explicit LoadException(std::string &msg) : BaseException(msg) {}
    const char *what() const noexcept override
    {
        return "Fail while loading model";
    }
};
