#pragma once
#include "base_reader.h"
#include <memory>
#include <fstream>


class FileReader : public BaseReader
{
public:
    FileReader();
    explicit FileReader(const std::string& filename);
    ~FileReader() = default;

    void open() override;
    void close() override;
    double read() override;

    bool is_open() override;

private:
    std::string filename;
    FILE *file = nullptr;
};

