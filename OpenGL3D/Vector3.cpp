#include "pch.h"
#include <math.h>

#include "Util.h"
#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3::Vector3(double i, double j, double k)
{
	x = i;
	y = j;
	z = k;
}

double Vector3::getCoordX()
{
	return x;
}

double Vector3::getCoordY()
{
	return y;
}

double Vector3::getCoordZ()
{
	return z;
}

void Vector3::setCoordX(double d)
{
	x = d;
}

void Vector3::setCoordY(double d)
{
	y = d;
}

void Vector3::setCoordZ(double d)
{
	z = d;
}

double* Vector3::getVector()
{
	double v[3] = { x, y, z };

	return v;
}

void Vector3::setVector(double i, double j, double k)
{
	x = i;
	y = j;
	z = k;
}

double* Vector3::operator[](int id)
{
	switch (id)
	{
	case 0:
		return &x;
	case 1:
		return &y;
	case 2:
		return &z;
	}
}

Vector3& Vector3::operator=(Vector3& v)
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	return v;
}

Vector3 Vector3::operator+(Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(double d)
{
	return Vector3(x * d, y * d, z * d);
}

Vector3 Vector3::operator/(double d)
{
	return Vector3(x / d, y / d, z / d);
}

bool Vector3::operator==(Vector3& v)
{
	if ((*this - v).magnitudeSquared() < 9.99999944E-11f)
	{
		return true;
	}

	return false;
}

bool Vector3::operator!=(Vector3& v)
{
	if ((*this - v).magnitudeSquared() < 9.99999944E-11f)
	{
		return false;
	}

	return true;
}

double Vector3::magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::normalized()
{
	double mag = this->magnitude();

	return Vector3(x / mag, y / mag, z / mag);
}

double Vector3::magnitudeSquared()
{
	return (x * x) + (y * y) + (z * z);
}


Vector3 Vector3::UP()
{
	return Vector3(0, 1, 0);
}

Vector3 Vector3::DOWN()
{
	return Vector3(0, -1, 0);
}

Vector3 Vector3::LEFT()
{
	return Vector3(-1, 0, 0);
}

Vector3 Vector3::RIGHT()
{
	return Vector3(1, 0, 0);
}

Vector3 Vector3::FORWARD()
{
	return Vector3(0, 0, 1);
}

Vector3 Vector3::BACK()
{
	return Vector3(0, 0, -1);
}

Vector3 Vector3::ONE()
{
	return Vector3(1, 1, 1);
}

Vector3 Vector3::ZERO()
{
	return Vector3(0, 0, 0);
}

double Vector3::angle(Vector3& v)
{
	return acos(this->DOT(v) / (this->magnitude() * v.magnitude())) * RADIANOS_PARA_GRAUS;
}

double Vector3::DOT(Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::CROSS(Vector3& v)
{
	return Vector3((y * v.z) - (z * v.y),
				   (z * v.x) - (x * v.z),
				   (x * v.y) - (y * v.x));
}

Vector3 Vector3::REFLECT(Vector3* plano)
{
	Vector3 v = plano[1] - plano[0];
	Vector3 w = plano[2] - plano[0];

	Vector3 normal = v.CROSS(w).normalized();
	double scale = 2.0f * this->DOT(normal);
	Vector3 vn = normal * scale;

	return *this - vn;
}

std::string Vector3::toString()
{
	stringstream  s;
	s << "|" << x << "|" << y << "|" << z << "|\n";

	return s.str();
}