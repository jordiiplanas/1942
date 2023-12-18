#pragma once
#include "Object.h"
#include <unordered_map>
#include <string>
#include "ImageRenderer.h"

class GameObject : public Object
{
public:
	GameObject(Vector2 size)
		: Object("resources/1942.png", size) {
	}
protected:
	std::unordered_map<std::string, ImageRenderer*> renderers;
};