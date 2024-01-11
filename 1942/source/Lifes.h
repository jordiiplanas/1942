#pragma once
#include "GameObject.h"

class Lifes : public GameObject
{
public:
	Lifes(Vector2 position) : GameObject(Vector2(32, 32))
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(0, 0), Vector2(32, 32)));
		renderer = renderers["idle"];
		SetPosition(position);
		SetScale(Vector2(1.5, 1.5));
	}
};
