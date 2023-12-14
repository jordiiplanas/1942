#pragma once
#include <vector>
#include <iostream>

#include "Transform.h"
#include "AABB.h"

class Rigidbody
{
private:

  std::vector<AABB*> colliders;
  Transform* transform;

  Vector2 velocity;
  float angularVelocity;
  
  Vector2 acceleration;
  float angularAcceleration;

  float linearDrag;
  float angularDrag;

public:

  Rigidbody(Transform* transform)
    : transform(transform),
      velocity(Vector2()),
      angularVelocity(0.0f),
      acceleration(Vector2()),
      angularAcceleration(0.0f),
      linearDrag(0.0f),
      angularDrag(0.0f){}

  void Update (float dt)
  {

    velocity = velocity + acceleration * dt;
    angularVelocity += angularAcceleration * dt;

    //Drag OVER 0
    velocity = velocity * (1.0 / (1.0 + dt * linearDrag));
    angularVelocity = angularVelocity * (1.0 / (1.0 + dt * angularDrag));




    // other DRAG BETWEEN 0 AND 1
    // velocity = velocity * (1.0f - drag)

    transform->position = transform->position + velocity * dt;
    transform->angle += angularVelocity * dt;

    for (AABB* collider : colliders)
    {
      collider->SetTopLeft(transform->position);
      collider->SetSize(transform->size * transform->scale);
      if (transform->centered)
      {
        collider->SetTopLeft(collider->GetTopLeft()-collider->GetSize()/2);
      }
    }
  }
  
  inline void AddCollider(AABB* collider)
  {
    colliders.push_back(collider);
  }
  bool CheckCollision (const Rigidbody* other)
  {
    for (AABB* collider : colliders)
    {
      for (AABB* otherCollider : other->colliders)
      {
        if (collider->CheckOverlappingAABB(*otherCollider))
         {return true;}
      }
    }
    return false;
  }
  bool CheckOverlappingPoint(Vector2 point)
  {
    for (AABB* collider : colliders)
    {
      if (collider->CheckOverlappingPoint(point))
      {
        return true;
      }
    }
    return false;
  }
  void AddForce (Vector2 force) 
  { 
      velocity = velocity + force;
  }
  void AddTorque (float torque) { angularVelocity += torque; };
  inline Vector2 GetVelocity() { return velocity; }
  inline void SetVelocity(Vector2 velocity) { this->velocity = velocity; }
  inline void SetLinearDrag(float linearDrag) { this->linearDrag = linearDrag; }
  inline void SetAngularDrag(float angularDrag) { this->angularDrag = angularDrag; }
};