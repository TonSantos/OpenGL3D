
#include "pch.h"
#include <GL\glew.h>
#include <GL\glut.h>
#include <iostream>


void draw()
{
	
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