#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Program.h"

class Component
{
public:
	Component(std::string name);
	~Component();
	int GetId();

	virtual void Update() = 0;

	std::string name;

private:
	static int component_count;
	int component_id;
};

#endif