#pragma once
#include "reader/base_reader.h"
#include "reader/file_reader.h"
#include "../base_solution.h"
#include "../objects/base_object.h"
#include "model/carcass_model_builder.h"
#include "camera/camera_builder.h"
#include "base_director.h"
#include "model/carcass_director.h"
#include "camera/camera_director.h"
#include <string>

template <typename MyBuilder, typename MyDirector>
class LoaderSolution : public BaseSolution
{
public:
    LoaderSolution() = default;
    ~LoaderSolution() = default;

    void load(const std::string& filename)
    {
        std::shared_ptr<FileReader> reader = std::make_shared<FileReader>(filename);
        std::shared_ptr<MyBuilder> builder = std::make_shared<MyBuilder>(reader);
        myDirector = std::make_shared<MyDirector>(builder);
    }
    std::shared_ptr<BaseObject> create()
    {
        return myDirector->create();
    }
private:
    std::shared_ptr<BaseDirector> myDirector;
};
