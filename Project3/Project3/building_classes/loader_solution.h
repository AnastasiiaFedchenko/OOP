#pragma once
#include "reader/base_reader.h"
#include "reader/file_reader.h"
#include "../base_solution.h"
#include "../objects/base_object.h"
#include "model/carcass_model_builder.h"
#include "base_director.h"
#include "model/carcass_director.h"
#include <string>

class SolutionLoader : public BaseSolution
{
public:
    SolutionLoader();
    // explicit SolutionLoader(const std::shared_ptr<Loader>& loader) noexcept;
    ~SolutionLoader() = default;

    std::shared_ptr<BaseObject> load_from_simple_file(const std::string& filename)
    {

        std::shared_ptr<BaseReader> reader = std::make_shared<FileReader>(filename);
        std::shared_ptr<CarcassModelBuilder> builder = std::make_shared<CarcassModelBuilder>(reader);

        std::shared_ptr<BaseDirector> myDirector = std::make_shared<>(builder);
        // std::shared_ptr<AbstractObject> obj = SolutionLoader::load<CarcasDirector>(builder);

        return myDirector->create();
    }
};
