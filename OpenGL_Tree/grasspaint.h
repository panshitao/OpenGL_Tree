#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
//测试 2
void GrassPaint(GLdouble Y) 
{
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);glVertex3f(-20,-Y, 20);
	glTexCoord2f(0.0, 1.0);glVertex3f(20, -Y, 20);
	glTexCoord2f(1.0, 1.0);glVertex3f(20, -Y, -20);
	glTexCoord2f(1.0, 0.0);glVertex3f(-20, -Y, -20);
	glEnd();
}