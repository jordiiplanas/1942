#pragma once

#include <iostream>
#define NORMALIZATION_THRESHOLD 0.0001f

class Vector2
{
public:
	float x;
	float y;
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}

	void Normalize()
	{
		float length = Magnitude();
		std::cout << "Length: " << length << std::endl;
		if (length < NORMALIZATION_THRESHOLD)
		{
			x = 0.0f;
			y = 0.0f;
		}
		else
		{
			x /= length;
			y /= length;
		}
		
	}
	
	float Magnitude()
	{
		return sqrt(x * x + y * y);
	}

	Vector2 operator+ (Vector2 vector)
	{
		return Vector2(this->x + vector.x, this->y + vector.y);
	}
	Vector2 operator- (Vector2 vector)
	{
		return Vector2(this->x - vector.x, this->y - vector.y);
	}
	Vector2 operator* (Vector2 vector)
	{
		return Vector2(this->x * vector.x, this->y * vector.y);
	}
	Vector2 operator* (float amount)
	{
		return Vector2(this->x * amount, this->y * amount);
	}
	bool operator== (Vector2 vector)
	{
		return x == vector.x && y == vector.y;
	}

	Vector2 operator/(int i)
	{
		return Vector2(this->x / i, this->y / i);
	}
};