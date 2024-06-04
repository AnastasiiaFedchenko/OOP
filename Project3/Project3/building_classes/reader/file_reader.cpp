#include "file_reader.h"


FileReader::FileReader() {}

FileReader::FileReader(const std::string& filename)
{
    this->filename = filename;
    file = std::make_shared<std::ifstream>();
    opened = false;
}

void FileReader::open()
{
    if (!file)
    {
        //std::string msg = "Error : File open";
        //throw SourceException(msg);
    }

    file->open(filename);

    if (!file)
    {
        opened = true;
        //std::string msg = "Error : File open";
        //throw SourceException(msg);
    }
}

void FileReader::close()
{
    if (!this->is_open())
    {
        throw std::exception();
    }

    file->close();
    this->file = nullptr;
}

bool FileReader::is_open()
{
    return this->opened;
}

std::size_t FileReader::read_count()
{
    int count;

    *file >> count;

    return count;
}

My_Point FileReader::read_point()
{
    double x, y, z;

    *file >> x >> y >> z;

    return My_Point(x, y, z);
}

std::vector<My_Point> FileReader::read_points()
{
    std::vector<My_Point> points;

    int Num_points;
    *file >> Num_points;

    if (Num_points <= 0)
    {
        std::string msg = "wrong vertex num";
        //throw SourceException(msg);
    }

    double x, y, z;

    for (int i = 0; i < Num_points; i++)
    {
       *file >> x >> y >> z;
       points.push_back(My_Point(x, y, z));
    }

    return points;
}

std::vector<Edge> FileReader::read_edges(int Num_points)
{
    std::vector<Edge> edges;

    int Num_edges;
    *file >> Num_edges;

    if (Num_edges <= 0)
    {
        std::string msg = "wrong links num";
        //throw SourceException(msg);
    }

    int i1, i2;

    for (int i = 0; i < Num_edges; i++)
    {
        *file >> i1 >> i2;

        if (i1 <= 0 || i2 <= 0 || i1 > Num_points || i2 > Num_points)
        {
            std::string msg = "wrong link data";
            //throw SourceException(msg);
        }

        edges.push_back(Edge(i1, i2));
    }

    return edges;
}