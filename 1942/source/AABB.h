#pragma once
#include "Vector2.h"

class AABB
{
protected:
  Vector2 topLeft;
  Vector2 size;
public:
  AABB (Vector2 topLeft, Vector2 size)
    : topLeft(topLeft),
      size(size){}
  bool CheckOverlappingAABB(AABB other)
  {
    float width1 = size.x;
    float width2 = other.GetSize().x;
    float height1 = size.y;
    float height2 = other.GetSize().y;
    
    float distanceX = topLeft.x + size.x - other.topLeft.x;
    if (topLeft.x > other.topLeft.x)
    {
      distanceX = other.topLeft.x + other.size.x - topLeft.x;
    }
    bool intersectionX = distanceX < width1 + width2;

    float distanceY = topLeft.y + size.y - other.topLeft.y;
    if (topLeft.y < other.topLeft.y)
    {
      distanceY = other.topLeft.y + other.size.y - topLeft.y;
    }
    bool intersectionY = distanceY < height1 + height2;

    return intersectionX && intersectionY;
  }
  bool CheckOverlappingPoint(Vector2 point)
  {
    if (point.x > topLeft.x &&
        point.x < topLeft.x + size.x &&
        point.y > topLeft.y &&
        point.y < topLeft.y + size.y)
    {
      return true;
    }
    return false;
  }
  inline Vector2 GetTopLeft(){
    return topLeft;
  }
  Vector2 GetSize()
  {
    return size;
  }
  void SetTopLeft(Vector2 topLeft)
  {
    this->topLeft = topLeft;
  }
  void SetSize(Vector2 size)
  {
    this->size = size;
  }
};