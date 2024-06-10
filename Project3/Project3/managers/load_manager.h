#pragma once
#include <memory>
#include "base_managers.h"
#include "../building_classes/loader_solution.h"

class FileLoadManager : public BaseLoadManager
{
public:
    FileLoadManager() {}
    ~FileLoadManager() = default;

    template <typename MyBuider, typename MyDirector>
    std::shared_ptr<BaseObject> load(std::string& filename, 
                                     std::shared_ptr<LoaderSolution<MyBuider, MyDirector>> solution)
    {
        solution->load(filename);
        return solution->create();
    }

    /*std::shared_ptr<BaseObject> create(std::string& filename)
    {
        solution->create();
    }*/

private:
    //std::shared_ptr<LoaderSolution> solution;
};