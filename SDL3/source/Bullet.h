#pragma once

#include "Object.h"

class Bullet : public Object
{
private:
	Vector2 direction = Vector2(0.0f, -1.0f);
public:

	Bullet(float speed, Vector2 direction,
		std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize, SDL_Renderer* sdlRenderer)
		: Object(path, size, sourceOffset, sourceSize, sdlRenderer), direction(direction)
	{
		rigidbody->SetVelocity(direction * speed);
	}
	

};