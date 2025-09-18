#ifndef _MATHHELPER_H
#define _MATHHELPER_H

#include <math.h>

// defining pi and degrees to radius
#define PI 3.14159265
#define DEG_TO_RAD PI/180.0f

// struct for vector 2
struct Vector2
{
	// x and y variables
	float x;
	float y;

	// vector 2 func/init
	Vector2(float _x = 0.0f, float _y = 0.0f) 
		: x(_x), y(_y) {}

	// returns magsqr of vector
	// formula = https://www.geeksforgeeks.org/maths/magnitude-of-a-vector/
	float MagnitudeSqr()
	{
		return x * x + y * y;
	}

	// returns magnitude of vector
	float Magnitude() 
	{
		// this is a cast
		return (float)sqrt(x * x + y * y);
	}

	// retuns normalised vector
	// formula = vector2.(x or y)/magnitude of vector
	Vector2 Normalized() 
	{
		float mag = Magnitude();

		return Vector2(x / mag, y / mag);

	}

	Vector2& operator +=(const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	Vector2& operator -=(const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

};

// vector 2 addition operator 
inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

// vector 2 subtract operator 
inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

// vector 2 multiply-equal operator 
inline Vector2 operator *(const Vector2& lhs, const float& rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

// function to rotate a vector
inline Vector2 RotateVector(Vector2& vector, float angle)
{
	float radAngle = (float)(angle * DEG_TO_RAD);

	return Vector2((float)(vector.x * cos(radAngle) - vector.y * sin(radAngle)), 
		(float)(vector.x * sin(radAngle) + vector.y * cos(radAngle)));
}

#endif