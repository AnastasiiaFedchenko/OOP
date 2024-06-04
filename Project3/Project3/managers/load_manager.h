#pragma once
#include <memory>
#include "base_managers.h"
#include "../building_classes/loader_solution.h"

class FileLoadManager : public BaseLoadManager
{
public:
    FileLoadManager()
    {
        solution = std::make_shared<LoaderSolution>(LoaderSolution());
    }
    ~FileLoadManager() = default;

    std::shared_ptr<BaseObject> load(std::string& filename)
    {
        return solution->load(filename);
    }

private:
    std::shared_ptr<LoaderSolution> solution;
};