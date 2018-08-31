#include "pch.h"
#include <GL\glew.h>
#include <GL\glut.h>
#include <iostream>

#include "Vector3.h"
#include "Util.h"

void drawVertices(Vector3 vertices[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		glVertex3f(vertices[i].getCoordX(), vertices[i].getCoordY(), vertices[i].getCoordZ());
	}
}

void drawRectangle()
{
	/*RETANGULO - lista de vertices*/
	Vector3 verticesRetangulo[4] = {
			Vector3(2.0, 4.0, 0.0), Vector3(8.0, 4.0, 0.0),
			Vector3(8.0, 6.0, 0.0), Vector3(2.0, 6.0, 0.0)
	};

	glLineWidth(5);

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);

	drawVertices(verticesRetangulo, 4);
}

void drawLine()
{
	/*LINHA - lista de vertices*/
	Vector3 verticesLinha[2] = {
			Vector3(0.0, 0.0, 0.0),  Vector3(3.0, 3.0, 0.0)
	};

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);

	drawVertices(verticesLinha, 2);

}

void drawTriangle()
{

	/*TRIANGULO - lista de vertices*/
	Vector3 verticesTriangulo[3] = {
			Vector3(1.0, 1.0, 1.0),  Vector3(5.0, 1.0, 1.0), Vector3(1.0, 5.0, 1.0)
	};

	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLES);

	drawVertices(verticesTriangulo, 3);

}

void draw()
{

	//drawLine();
	//drawRectangle();
	drawTriangle();

	glEnd();

	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL 3D");

	glMatrixMode(GL_PROJECTION);              // setup viewing projection 
	glLoadIdentity();                           // start with identity matrix 

	glOrtho(0.0, 10.0, 0.0, 10.0, -5.0, 5.0);   // setup a 10x10x20 viewing world

	glutDisplayFunc(draw);

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		std::cout << "Erro ao iniciar GLEW";
	}
	else
	{
		std::cout << "Usando GLEW versao: " << glewGetString(GLEW_VERSION);
	}

	glutMainLoop();
	return 0;
}