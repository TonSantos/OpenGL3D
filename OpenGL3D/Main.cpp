#include "pch.h"
#include <GL\glew.h>
#include <GL\glut.h>
#include <iostream>

#include "Vector3.h"

void draw()
{
	/*lista de vertices*/
	Vector3 vertices[2] = { 
			Vector3(0.0, 0.0, 0.0),  Vector3(1.0, 1.0, 0.0)
	};

	glLineWidth(5);
	glColor3f(0, 1, 0);

	glBegin(GL_LINES);

	glVertex3f(vertices[0].getCoordX(), vertices[0].getCoordY(), vertices[0].getCoordZ());
	glVertex3f(vertices[1].getCoordX(), vertices[1].getCoordY(), vertices[1].getCoordZ());

	/*glVertex3f(3, 3, 0);
	glVertex3f(-3, -3, 0);*/
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL 3D");
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