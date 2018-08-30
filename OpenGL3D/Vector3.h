#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <sstream>

using namespace std;

class Vector3
{
	double x;
	double y;
	double z;

public:
	/*construtores*/
	Vector3();
	Vector3(double i, double j, double k);

	/*coordenadas*/
	double getCoordX();
	double getCoordY();
	double getCoordZ();
	void   setCoordX(double d);
	void   setCoordY(double d);
	void   setCoordZ(double d);

	/*vetor*/
	double *getVector();
	void	setVector(double i, double j, double k);

	/*operacoes*/
	double*  operator[](int id);
	Vector3& operator=(Vector3& v);
	Vector3  operator+(Vector3& v);
	Vector3  operator-(Vector3& v);
	Vector3  operator*(double d);
	Vector3  operator/(double d);
	bool     operator==(Vector3& v);
	bool     operator!=(Vector3& v);

	/*propriedades*/
	double  magnitude();
	Vector3 normalized();
	double  magnitudeSquared();

	/*metodos statics*/
	static Vector3 UP();
	static Vector3 DOWN();
	static Vector3 LEFT();
	static Vector3 RIGHT();
	static Vector3 BACK();
	static Vector3 FORWARD();
	static Vector3 ONE();
	static Vector3 ZERO();

	double angle(Vector3 &v);
	double DOT(Vector3 &v);
	Vector3 CROSS(Vector3 &v);
	Vector3 REFLECT(Vector3* plano);

	/*visualizar*/
	std::string toString();
};


#endif //VECTOR3_H