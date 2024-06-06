#pragma once
#include "base_command.h"
#include <string>
#include <iostream>

class BaseLoadCommand : public BaseCommand {};

class FileLoadModelCommand : public BaseLoadCommand
{
    using Action = std::shared_ptr<BaseObject>(FileLoadManager::*)(std::string& filename);

public:
    FileLoadModelCommand(std::shared_ptr<BaseObject>& model, std::string& filename) : model(model)
    {
        this->filename = filename;
        method = &FileLoadManager::load;
    }

    virtual void execute() override
    {
        model = ((*load_manager).*method)(filename);
    }

private:
    std::string filename;
    std::shared_ptr<BaseObject>& model;
    Action method;
};
