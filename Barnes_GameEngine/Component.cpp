#include "Component.h"

int Component::component_count = 0;

Component::Component(std::string name)
{
	this->name = name;
	component_id = component_count;
	component_count++;
}

Component::~Component()
{

}

int Component::GetId()
{
	return component_id;
}