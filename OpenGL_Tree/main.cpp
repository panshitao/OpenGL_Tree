/*  checker.c
 *  This program texture maps a checkerboard image onto
 *  two rectangles.
 *
 *  If running this program on OpenGL 1.0, texture objects are
 *  not used.
 */
#include "psBMPLoader.h" //����ͼƬ
#include "cylinder.h"  //����Բ��
#include "Leaf.h"  //����Ҷ��
#include "grasspaint.h"  //���Ʋݵ�
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef GL_VERSION_1_1
static GLuint texName;
static GLuint texName2;
static GLuint texName3;
static GLuint texName4;
#endif
static int L = 0, day = 0;
bool autorotate = 0;

void init(void)
{    
   glClearColor (0.0, 1.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);
	psBMPLoader *pl=new psBMPLoader();
	pl->psLoad("treepin3.bmp");
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	pl->psMakeTexture();

	psBMPLoader *p2 = new psBMPLoader();
	p2->psLoad("ground.bmp");
	glGenTextures(1, &texName2);
	glBindTexture(GL_TEXTURE_2D, texName2);
	p2->psMakeTexture();

	psBMPLoader *p3 = new psBMPLoader();
	p3->psLoad("grass1.bmp");
	glGenTextures(1, &texName3);
	glBindTexture(GL_TEXTURE_2D, texName3);
	p3->psMakeTexture();

	psBMPLoader *p4 = new psBMPLoader();
	p4->psLoad("leaf1.bmp");
	glGenTextures(1, &texName4);
	glBindTexture(GL_TEXTURE_2D, texName4);
	p4->psMakeTexture();
}
//���ù�Դ
void init2()
{
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };
	GLfloat white_light[] = { 1.0,1.0,1.0,0.0 };
	GLfloat light_ambient[] = { 0.0,0.0,1.0,1.0 };
	GLfloat lmodel_ambient[] = {0.2,0.2,0.2,1.0};

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

//�ж������Ǹ�����ת
void XuanZhuan(int num, double angle)
{
	switch (num)
	{
	case 1:
		glRotatef(angle, 1, 0, 0);
		break;
	case 2:
		glRotatef(angle, 0, 1, 0);
		break;
	case 3:
		glRotatef(angle, 0, 0, 1);
		break;
	default:
		printf_s("������������");
		return;
	}
}
//�ж������Ǹ���ƽ��
void PinYi(int num, double distant)
{
	switch (num)
	{
	case 1:
		glTranslatef(distant, 0, 0);
		break;
	case 2:
		glTranslatef(0, distant, 0);
		break;
	case 3:
		glTranslatef(0, 0, distant);
		break;
	default:
		printf_s("������������");
		return;
	}
}
//���ƾ�����ת��ƽ�Ʊ任�����Ҷ
void ManyLeaf(double trans, double angle,int num)
{
	GLfloat mat_specular[] = { 0.0,10.0,0.0,1.0 };
	glBindTexture(GL_TEXTURE_2D, texName4);
	glPushMatrix();
	PinYi(2, trans);
	XuanZhuan(num, angle);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	PaintLeaf(0.1);
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
}
//���ƴ�����Ҷ��֦�
void TreeAndLeaf(double h)
{
	double angle = 90;
	double step = 0.10; //��Ҷÿ������Y��ƽ�Ƶľ���
	int n1 = int(1.8 * h / step) - 1; //�ұ�Ҷ�ӵ�����
	int n2 = int(1.7 * h / step) - 1; //���Ҷ�ӵ�����
	for (int i = 0;i < n1;i++) //�ұߵ���Ҷ
	{
		ManyLeaf(-h*0.8 + i*step, -45,3);
	}
	for (int i = 0;i < n2;i++) //��ߵ���Ҷ
	{
		ManyLeaf(-h*0.7 + i*step, 30,3);
	}
	//��ת
	for (int i = 0;i < n1;i++) 
	{
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		ManyLeaf(-h*0.8 + i*step, -45, 2);
		glPopMatrix();
	}
	angle = 90;
	for (int i = 0;i < n2;i++) 
	{
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		ManyLeaf(-h*0.7 + i*step, 30, 2);
		glPopMatrix();
	}
	/*glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);*/
	glBindTexture(GL_TEXTURE_2D, texName);
	GLfloat mat_specular[] = { 20.0,10.0,0.0,1.0 };
	DrawCylinder(0.001, 0.03, 15, h);//����֦�
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);

	//glutSwapBuffers();
	//glFlush();
}
//֦������תƽ�Ƶ����ɵĺ���λ��
void Change(double h, double angle, int num)
{
	switch (num) 
	{
	   case 1: //����X����ת
		   PinYi(2, h / 2.0*sin(angle));
		   PinYi(3, h / 2.0*cos(angle));
		   break;
	   case 2: //����Y����ת
		   PinYi(1, h / 2.0*sin(angle));
		   PinYi(3, h / 2.0*cos(angle));
		   break;
	   case 3: //����Z����ת
		   PinYi(1, h / 2.0*sin(angle));
		   PinYi(2, h / 2.0*cos(angle));
		   break;
	}
}

/*����h��֦辵ĳ��ȣ�angle����ת�ĽǶȣ�trans��ƽ�ƾ���
*����num1��ʾ�����Ǹ�����ת������num2��ʾ�����Ǹ���ƽ��
*1-X�ᣬ2-Y�ᣬ3-Z��
*/
void TreeRight(double h, double angle, double distant, int num1, int num2)
{
	glPushMatrix();
	PinYi(num2, distant);
	PinYi(1, h / 2.0*sin(angle));
	PinYi(2, h / 2.0*cos(angle));
	//Change(h,angle,num1);
	XuanZhuan(num1, angle);
	//DrawCylinder(0.00, 0.03, 15, h);//����֦�
	TreeAndLeaf(h);
	glPopMatrix();

	//glutSwapBuffers();
	//glFlush();
}
/*����h��֦辵ĳ��ȣ�angle����ת�ĽǶȣ�trans��ƽ�ƾ���
*����num1��ʾ�����Ǹ�����ת������num2��ʾ�����Ǹ���ƽ��
*1-X�ᣬ2-Y�ᣬ3-Z��
*/
void TreeLeft(double h, double angle, double distant, int num1, int num2)
{
	glPushMatrix();

	PinYi(num2, distant);
	PinYi(1, -0.8*h*sin(angle));
	PinYi(2, 0.8*h *cos(angle));
	XuanZhuan(num1, angle);
	//DrawCylinder(0.0, 0.03, 15, h);//����֦�
	TreeAndLeaf(h);
	glPopMatrix();

	//glutSwapBuffers();
	//glFlush();
}
void displayTree(void)
{
	double angle = 90;
	/*glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);*/
	glBindTexture(GL_TEXTURE_2D, texName);

	GLfloat mat_ambient[] = { 0.0,10.0,1.0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	DrawCylinder(0.005, 0.15, 30, 2.0);//����֦��
    //�����ұߵ�֦�
	for (int i = 0;i <= 3;i++)
	{
		TreeRight(1.25 - i*0.30, -30, -0.3 + i*0.7, 3, 2);
	}
	//������ߵ�֦�
	for (int i = 0;i <= 3;i++)
	{
		TreeLeft(1.1 - i*0.20, 45, -0.4 + i*0.6, 3, 2);
	}
	//��ת
	for (int i = 0;i <= 3;i++)
	{
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		TreeRight(1.25 - i*0.30, -30, -0.3 + i*0.7, 3, 2);
		glPopMatrix();
	}
	angle = 90;
	for (int i = 0;i <= 3;i++)
	{
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		TreeLeft(1.1 - i*0.20, 45, -0.4 + i*0.6, 3, 2);
		glPopMatrix();
	}

	//glutSwapBuffers();
	//glFlush();
}
//����
void Background()
{
	glBindTexture(GL_TEXTURE_2D, texName2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-20, -20,-2);
	glTexCoord2f(1.0, 0.0); glVertex3f(20, -20,-2);
	glTexCoord2f(1.0, 1.0); glVertex3f(+20, +20,-2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-20, 20,-2);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glPushMatrix();
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)L, 1.0, 0.0, 0.0);
	displayTree();
	glPopMatrix();
	//displayTree();
	GLfloat mat_ambient[] = { 0.0,0.0,0.0,10.0 };
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	Background();
	glBindTexture(GL_TEXTURE_2D, texName3);
	GrassPaint(2.0);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	glDisable(GL_TEXTURE_2D);
}
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}
void timer(int value)
{
	day = (day + 1) % 360;
	glutPostRedisplay();
	if (autorotate)glutTimerFunc(20, timer, 1);//glutTimerFunc(������, �ص�����ָ��, ����ֵ)
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'a':
         L = (L + 10) % 360;
         glutPostRedisplay();
         break;
      case 'A':
         L = (L - 10) % 360;
         glutPostRedisplay();
         break;
	  case ' ':
		  if (autorotate == 0)autorotate = 1;
		  else autorotate = 0;
		  if (autorotate)glutTimerFunc(20, timer, 1);
		  break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(750, 750);
   glutInitWindowPosition( 0, 100);
   glutCreateWindow("���Ĺ���ģ��");
   init();
   init2();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0; 
}

