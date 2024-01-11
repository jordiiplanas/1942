#pragma once
#include "GameObject.h"

class Lifes : public GameObject
{
public:
	Lifes(Vector2 position) : GameObject(Vector2(32, 32))
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(22, 688), Vector2(4, 15)));
		renderer = renderers["idle"];
		SetPosition(position);
		SetScale(Vector2(0.25, 0.5));
	}
};
