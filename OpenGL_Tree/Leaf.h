#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
GLdouble pi = 3.1415926;
//叶子是椭圆形
/*参数a是椭圆的长半轴，参数b是椭圆的短半轴，参数n是分割的份数*/
//void PaintLeaf2(double a,double b,int n)
//{
//	double u = 0;
//	double ustep = 1.0 / n;
//	//绘制椭圆形
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
//绘制菱形叶子
//参数y是菱形的长度
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