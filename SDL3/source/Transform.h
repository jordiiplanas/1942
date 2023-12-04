#pragma once
#include "Vector2.h"

class Transform
{
public:
  Vector2 position;
  float angle;
  Vector2 scale;
  Vector2 size;
  bool centered;

  Transform()
    : position(Vector2()),
      centered(false),
      angle(0.0f),
      scale(Vector2(1.0f, 1.0f)),
      size(Vector2(1.0f,1.0f)){}

  Transform(Vector2 vector2, float angle, Vector2 scale, Vector2 size)
    : position(vector2),
      centered(false),
      angle(angle),
      scale(scale),
      size(size){}

  Transform(Vector2 vector2, float angle, Vector2 scale, Vector2 size, bool centered)
      : position(vector2),
      centered(centered),
      angle(angle),
      scale(scale),
      size(size) {}
  
  
};