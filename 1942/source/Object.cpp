#include "Object.h"

Object::Object(std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
{

	transform = new Transform();
	transform->size = size;
	renderer = new ImageRenderer(transform, sourceOffset, sourceSize);
	isPendingDestroy = false;

	rigidbody = new Rigidbody(transform);
	rigidbody->AddCollider(new AABB(transform->position, Vector2(64, 64)));

}

void Object::Render(SDL_Renderer* renderer)
{
	this->renderer->Render(renderer);
}

void Object::SetPosition(Vector2 position)
{
	this->transform->position = position;
	renderer->SetPosition(position);
}

void Object::SetScale(Vector2 _scale)
{
	this->transform->scale = _scale;
}

void Object::SetRotation(float rotation)
{
	this->transform->angle = rotation;
}

void Object::OnCollisionEnter(Object* other)
{
}



Object::~Object()
{
	delete renderer;
	delete transform;
}
