#ifndef OBJECT_NEW_H
#define OBJECT_NEW_H

class Object_new
{
public:
	Object_new();
	~Object_new();

	void Update();
	void AddComponent(Component* component);
	Component* GetComponent(std::string componentName);
	static void Destroy(Object_new object);

private:
	std::vector<Component*> components;
};

#endif