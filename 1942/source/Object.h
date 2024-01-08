#pragma once
#include <SDL_render.h>
#include "Rigidbody.h"
#include "Transform.h"
#include "ImageRenderer.h"

class Object
{

protected:
	Renderer* renderer;
	// Transform
	Transform* transform;
	Rigidbody* rigidbody;
	bool isPendingDestroy = false;

public:
	Object(std::string path, Vector2 size);
	~Object();

	// Constructor
	void Render();

	// Setters
	void SetPosition(Vector2 position);
	void SetScale(Vector2 scale);
	void SetRotation(float rotation);

	// Getters
	inline Vector2 GetPosition() { return transform->position; }
	inline Vector2 GetScale() { return transform->scale; }
	inline float GetRotation() { return transform->angle; }
	inline Vector2 GetSize() { return transform->size; }
	inline Transform* GetTransform() { return transform; }

	inline Vector2 GetCenteredPosition() { return transform->position + transform->size / 2; }


	virtual void Destroy () { isPendingDestroy = true; }
	inline bool IsPendingDestroy () { return isPendingDestroy; }


	virtual void Update(float dt) 
	{ 
		if (isPendingDestroy) delete this;
		rigidbody->Update(dt); 
		renderer->Update(dt);
	}
	Rigidbody* GetRigidbody() { return rigidbody; }

	virtual void OnCollisionEnter(Object* other);


};