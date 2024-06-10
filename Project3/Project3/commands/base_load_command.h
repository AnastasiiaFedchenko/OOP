#pragma once
#include "base_command.h"
#include <string>
#include <iostream>
#include "../building_classes/model/carcass_model_builder.h"
#include "../building_classes/model/carcass_director.h"

class BaseLoadCommand : public BaseCommand {};

class FileLoadModelCommand : public BaseLoadCommand
{
   using Action = std::shared_ptr<BaseObject>(FileLoadManager::*)(std::string& filename, 
       std::shared_ptr<LoaderSolution<CarcassModelBuilder, CarcassDirector>> solution);

public:
    FileLoadModelCommand(std::shared_ptr<BaseObject>& model, std::string& filename) : model(model)
    {
        this->filename = filename;
        solution = std::make_shared<LoaderSolution<CarcassModelBuilder, CarcassDirector>>();
        method = &FileLoadManager::load<CarcassModelBuilder, CarcassDirector>;
    }

    virtual void execute() override
    {
        model = ((*load_manager).*method)(filename, solution);
    }

private:
    std::string filename;
    std::shared_ptr<LoaderSolution<CarcassModelBuilder, CarcassDirector>> solution;
    std::shared_ptr<BaseObject>& model;
    Action method;
};

class FileLoadCameraCommand : public BaseLoadCommand
{
    using Action = std::shared_ptr<BaseObject>(FileLoadManager::*)(std::string& filename,
        std::shared_ptr<LoaderSolution<CameraBuilder, CameraDirector>> solution);

public:
    FileLoadCameraCommand(std::shared_ptr<BaseObject>& model, std::string& filename) : camera(model)
    {
        this->filename = filename;
        solution = std::make_shared<LoaderSolution<CameraBuilder, CameraDirector>>();
        method = &FileLoadManager::load<CameraBuilder, CameraDirector>;
    }

    virtual void execute() override
    {
        camera = ((*load_manager).*method)(filename, solution);
    }

private:
    std::string filename;
    std::shared_ptr<LoaderSolution<CameraBuilder, CameraDirector>> solution;
    std::shared_ptr<BaseObject>& camera;
    Action method;
};
