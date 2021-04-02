#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
const GLdouble PI = 3.1415926;
//绘制可变柱体
/*参数R1是上圆的半径，参数R2是下圆的半径，参数n是角度的份数
*参数LineY是圆柱体的高度的一半
*/
void DrawCylinder(double R1, double R2, int n, double LineY)
{
	double u = 0;
	double ustep = 1.0 / n;
	//绘制上端圆形
	for (int i = 0;i < n;i++)
	{
		glBegin(GL_TRIANGLES);
		//glColor3f(1, 0.0, 0.0);
		//glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0);glVertex3f(0, LineY, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(R1*cos(u * 2 * PI), LineY, R1*sin(u * 2 * PI));
		glTexCoord2f(1.0, 1.0);glVertex3f(R1*cos((u + ustep) * 2 * PI), LineY, R1*sin((u + ustep) * 2 * PI));
		u += ustep;
		glEnd();
	}
	//绘制下端圆形
	u = 0;
	for (int i = 0;i < n;i++)
	{
		glBegin(GL_TRIANGLES);
		//glColor3f(1.0, 0.0, 0.0);
		//glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0);glVertex3f(0, -LineY, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(R2*cos(u * 2 * PI), -LineY, R2*sin(u * 2 * PI));
		glTexCoord2f(1.0, 1.0);glVertex3f(R2*cos((u + ustep) * 2 * PI), -LineY, R2*sin((u + ustep) * 2 * PI));
		u += ustep;
		glEnd();
	}
	//画侧面
	u = 0;
	for (int i = 0;i < n;i++)
	{
		glBegin(GL_QUADS);
		//glColor3f(1.0, 0.0, 0.0);
		//glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0);glVertex3f(0, LineY, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(R1*cos(u * 2 * PI), LineY, R1*sin(u * 2 * PI));
		glTexCoord2f(1.0, 1.0);glVertex3f(0, -LineY, 0);
		glTexCoord2f(1.0, 0.0);glVertex3f(R2*cos(u * 2 * PI), -LineY, R2*sin(u * 2 * PI));

		//glColor3f(1.0, 0.0, 0.0);
		glTexCoord2f(0.0, 0.0);glVertex3f(R1*cos(u * 2 * PI), LineY, R1*sin(u * 2 * PI));
		glTexCoord2f(0.0, 1.0);glVertex3f(R1*cos((u + ustep) * 2 * PI), LineY, R1*sin((u + ustep) * 2 * PI));
		glTexCoord2f(1.0, 1.0);glVertex3f(R2*cos(u * 2 * PI), -LineY, R2*sin(u * 2 * PI));
		glTexCoord2f(1.0, 0.0);glVertex3f(R1*cos((u + ustep) * 2 * PI), -LineY, R1*sin((u + ustep) * 2 * PI));

		//glColor3f(1.0, 0.0, 0.0);
		glTexCoord2f(0.0, 0.0);glVertex3f(0, LineY, 0);
		glTexCoord2f(0.0, 1.0);glVertex3f(R1*cos((u + ustep) * 2 * PI), LineY, R1*sin((u + ustep) * 2 * PI));
		glTexCoord2f(1.0, 1.0);glVertex3f(0, -LineY, 0);
		glTexCoord2f(1.0, 0.0);glVertex3f(R2*cos((u + ustep) * 2 * PI), -LineY, R2*sin((u + ustep) * 2 * PI));
		u += ustep;
		glEnd();
	}
	/*glFlush();*/
}
