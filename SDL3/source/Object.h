#pragma once
#include <SDL_render.h>
#include "Rigidbody.h"
#include "Transform.h"
#include "ImageRenderer.h"

class Object
{

protected:
	ImageRenderer* renderer;

	// Transform
	Transform* transform;
	Rigidbody* rigidbody;
	bool isPendingDestroy;

public:
	Object(std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize, SDL_Renderer* sdlRenderer);
	~Object();

	// Constructor
	void Render(SDL_Renderer* renderer);

	// Setters
	void SetPosition(Vector2 position);
	void SetScale(Vector2 scale);
	void SetRotation(float rotation);

	// Getters
	inline Vector2 GetPosition() { return transform->position; }
	inline Vector2 GetScale() { return transform->scale; }
	inline float GetRotation() { return transform->angle; }
	inline Vector2 GetSize() { return transform->size; }

	inline Vector2 GetCenteredPosition() { return transform->position + transform->size / 2; }


	virtual void Destroy () { isPendingDestroy = true; }
	inline bool IsPendingDestroy () { return isPendingDestroy; }

	virtual void Update(float dt) { rigidbody->Update(dt); }
	Rigidbody* GetRigidbody() { return rigidbody; }


};