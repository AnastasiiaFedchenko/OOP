#pragma once
#include "base_reader.h"
#include "../../objects/model/point.h"
#include "../../objects/model/edge.h"
#include <memory>
#include <fstream>
#include <vector>


class FileReader : public BaseReader
{
public:
    FileReader();
    explicit FileReader(const std::string& filename);
    ~FileReader() = default;

    void open() override;
    void close() override;

    bool is_open() override;

    std::size_t read_count();
    My_Point read_point();
    std::vector<My_Point> read_points();
    std::vector<Edge> read_edges(int amount_point);

private:
    bool opened;
    std::string filename;
    std::shared_ptr<std::ifstream> file;
};

