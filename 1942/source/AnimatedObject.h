#pragma once
#include "Object.h"
#include "AnimatedImageRenderer.h"

class AnimatedObject : public Object
{
protected:
	AnimatedImageRenderer* renderer;

public:
	//AnimatedObject(std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
	//{
	//	delete renderer;
	//	std::vector<Vector2> framesDelta = { Vector2(0, 0), Vector2(25,0), Vector2(50, 64) };
	//	// TODO
	//	//renderer = new AnimatedImageRenderer(path, size, sourceOffset, sourceSize, deltas);
	//}
	~AnimatedObject();

	void Update(float deltaTime);
};