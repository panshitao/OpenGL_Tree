#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
const GLdouble PI = 3.1415926;
//���ƿɱ�����
/*����R1����Բ�İ뾶������R2����Բ�İ뾶������n�ǽǶȵķ���
*����LineY��Բ����ĸ߶ȵ�һ��
*/
void DrawCylinder(double R1, double R2, int n, double LineY)
{
	double u = 0;
	double ustep = 1.0 / n;
	//�����϶�Բ��
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
	//�����¶�Բ��
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
	//������
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
