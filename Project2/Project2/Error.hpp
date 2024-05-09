#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <exception>
#include <string.h>
#include <stdio.h>
#include <iostream>

class BasicError : public std::exception
{
protected:
    char message[200] = "";
public:
    BasicError(const char* filename, int line, time_t time, const char* error = "basic error")
    {
        char buf1[5];
        sprintf_s(buf1, "%d", line);
        char buf2[50];
        ctime_s(buf2, 50, &time);
        int j = 0;
        for (int i = 0; i < strlen("\nFile name: "); i++, j++)
            message[j] = "\nFile name: "[i];
        for (int i = 0; i < strlen(filename); i++, j++)
            message[j] = filename[i];
        for (int i = 0; i < strlen("\nLine: "); i++, j++)
            message[j] = "\nLine: "[i];
        for (int i = 0; i < strlen(buf1); i++)
            message[j] = buf1[i];
        for (int i = 0; i < strlen("\nTime: "); i++, j++)
            message[j] = "\nTime: "[i];
        for (int i = 0; i < strlen(buf2); i++, j++)
            message[j] = buf2[i];
        for (int i = 0; i < strlen("Info: "); i++, j++)
            message[j] = "Info: "[i];
        for (int i = 0; i < strlen(error); i++, j++)
            message[j] = error[i];
    }


    virtual const char* what() const noexcept override
    {
        return message;
    }

    virtual ~BasicError() {};
};

class BasicMatrixError : public BasicError 
{
public:
        BasicMatrixError(const char* filename, int line, time_t time,
        const char* error = "Matrix error!\n") :
        BasicError(filename, line, time, error) {};
};
class BasicIteratorError : public BasicError
{
public:
    BasicIteratorError(const char* filename, int line, time_t time,
        const char* error = "Iterator error!\n") :
        BasicError(filename, line, time, error) {};
};


class MemoryError: public BasicMatrixError
{
public:
    MemoryError(const char* filename, int line, time_t time,
        const char *error = "Memory allocation error!\n") :
        BasicMatrixError(filename, line, time, error) {};
};

class InvalidObject: public BasicError
{
public:
    InvalidObject(const char* filename, int line, time_t time,
        const char* error = "Attempt to work with a invalid object!\n") :
        BasicError(filename, line, time, error) {};
};

class InvalidIterator: public BasicIteratorError
{
public:
    InvalidIterator(const char* filename, int line, time_t time,
        const char* error = "Attempt to use an invalid iterator!\n") :
        BasicIteratorError(filename, line, time, error) {};
};

class EmptyMatrixError: public BasicMatrixError
{
public:
    EmptyMatrixError(const char* filename, int line, time_t time,
        const char* error = "Matrix must not be empty!\n") :
        BasicMatrixError(filename, line, time, error) {};
};

class IndexError: public BasicMatrixError
{
public:
    IndexError(const char* filename, int line, time_t time,
        const char* error = "Index is out of range!\n") :
        BasicMatrixError(filename, line, time, error) {};
};

class ZeroDivError: public BasicMatrixError
{
public:
    ZeroDivError(const char* filename, int line, time_t time,
        const char* error = "Division by zero is not allowed!\n") :
        BasicMatrixError(filename, line, time, error) {};
};

class DifferentSizeMatrixes: public BasicMatrixError
{
public:
    DifferentSizeMatrixes(const char* filename, int line, time_t time,
        const char* error = "Matrixes are different sizes!\n") :
        BasicMatrixError(filename, line, time, error) {};
};

class NotMultipableMatrixes: public BasicMatrixError
{
public:
    NotMultipableMatrixes(const char* filename, int line, time_t time,
        const char* error = "Matrixes cannot be multiplied!\n") :
        BasicMatrixError(filename, line, time, error) {};
};
