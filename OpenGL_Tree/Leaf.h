#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
GLdouble pi = 3.1415926;
//Ҷ������Բ��
/*����a����Բ�ĳ����ᣬ����b����Բ�Ķ̰��ᣬ����n�Ƿָ�ķ���*/
//void PaintLeaf2(double a,double b,int n)
//{
//	double u = 0;
//	double ustep = 1.0 / n;
//	//������Բ��
//	for (int i = 0;i < n;i++)
//	{
//		glBegin(GL_TRIANGLES);
//		glColor3f(1, 0.0, 0.0);
//		glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0);
//		glTexCoord2f(0.0, 1.0);glVertex3f(1.0*a*cos(u * 2 * pi), 0, 1.0*b*sin(u * 2 * pi));
//		glTexCoord2f(1.0, 1.0);glVertex3f(1.0*a*cos((u + ustep) * 2 * pi), 0, 1.0*b*sin((u + ustep) * 2 * pi));
//		u += ustep;
//		glEnd();
//	}
//	
//}
//��������Ҷ��
//����y�����εĳ���
void PaintLeaf(double y)
{
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(0.0, 0.0);glVertex3f(0, y, 0);
	glTexCoord2f(0.0, 1.0);glVertex3f(y / 3.0, y / 2.0, 0);
	glTexCoord2f(1.0, 1.0);glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0);glVertex3f(-y / 3.0, y / 2.0, 0);
	glEnd();
}