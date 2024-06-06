#pragma once
#include "../base_object.h"
#include "../../visitor/abstract_visitor.h"

class BaseModel : public BaseObject 
{
	/*virtual void accept(std::shared_ptr<AbstractVisitor> visitor)
	{
		visitor->visit(*this);
	}*/
};
