#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
public:
	static float deltaTime;
	static double currentTime;
	static float screenWidth;
	static float screenHeight;

	System();

	void Update();
	//void Init();
private:
	static float lastTime;
};

#endif