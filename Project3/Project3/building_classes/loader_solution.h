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

class LoaderSolution : public BaseSolution
{
public:
    LoaderSolution() = default;
    ~LoaderSolution() = default;

    std::shared_ptr<BaseObject> load(const std::string& filename)
    {
        std::shared_ptr<BaseDirector> myDirector;
        std::string r = filename.substr(filename.find_last_of("/") + 1, filename.size() - filename.find_last_of("/"));
        if (r.substr(0, 7) == "carcass")
        {
            std::shared_ptr<FileReader> reader = std::make_shared<FileReader>(filename);
            std::shared_ptr<CarcassModelBuilder> builder = std::make_shared<CarcassModelBuilder>(reader);
            myDirector = std::make_shared<CarcassDirector>(builder);

        }
        else if (r.substr(0, 6) == "camera")
        {
            std::shared_ptr<FileReader> reader = std::make_shared<FileReader>(filename);
            std::shared_ptr<CameraBuilder> builder = std::make_shared<CameraBuilder>(reader);
            myDirector = std::make_shared<CameraDirector>(builder);
        }
        return myDirector->create();
    }
};
