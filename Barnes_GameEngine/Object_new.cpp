#include <vector>
#include <string>
#include <iostream>

#include "Component.h"
#include "Object_new.h"
#include "Transform.h"

Object_new::Object_new()
{

}

Object_new::~Object_new()
{
	for(size_t i = 0; i < components.size(); i++)
	{
		delete(components[i]);
	}
}

void Object_new::AddComponent(Component* component)
{
	components.push_back(component);
}

void Object_new::Update()
{
	for(size_t i = 0; i < components.size(); i++)
	{
		components[i]->Update();
	}
}

Component* Object_new::GetComponent(std::string name)
{
	for(size_t i = 0; i < components.size(); i++)
	{
		if(components[i]->name.compare(name) == 0)
		{
			return components[i];
		}
	}

	return nullptr;
}
