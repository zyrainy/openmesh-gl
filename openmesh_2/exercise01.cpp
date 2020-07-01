//#include <GL/glut.h>
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//static void RenderSceneCB()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glutSwapBuffers();
//}
//
//
//int main(int argc, char *argv[]) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(1024, 768);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Tutorial 01");
//	glutDisplayFunc(RenderSceneCB);
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-10, 10, -10, 10, -10, 10);
//	GLfloat m[16];
//	glGetFloatv(GL_PROJECTION_MATRIX, m);
//	glutMainLoop();
//	
//}

//
//#include <gl/glut.h>
//#include "stdio.h"
//const GLint pickSize = 32;
//int winWidth = 400, winHeight = 300;
//void Initial(void)
//{
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//}
////void draw(GLenum mode)
////{
////	if (mode == GL_SELECT) glPushName(1);//ѹ���ջ
////	glColor3f(1.0f, 0.0f, 0.0f);
////	glRectf(60.0f, 50.0f, 150.0f, 150.0f);
////
////	if (mode == GL_SELECT) glPushName(2); //ѹ���ջ
////	glColor3f(0.0f, 1.0f, 0.0f);
////	glRectf(230.0f, 50.0f, 330.0f, 150.0f);
////	if (mode == GL_SELECT) glPushName(3); //ѹ���ջ
////	glColor3f(0.0f, 0.0f, 1.0f);
////	glRectf(140.0f, 140.0f, 240.0f, 240.0f);
////}
//
//void draw(GLenum model)
//{
//	if (model == GL_SELECT)
//	{
//		glColor3f(1.0, 0.0, 0.0);
//		glLoadName(100);
//		glPushMatrix();
//		glTranslatef(-5, 0.0, 10.0);
//		glBegin(GL_QUADS);
//		glVertex3f(-1, -1, 0);
//		glVertex3f(1, -1, 0);
//		glVertex3f(1, 1, 0);
//		glVertex3f(-1, 1, 0);
//		glEnd();
//		glPopMatrix();
//		glColor3f(0.0, 0.0, 1.0);
//		glLoadName(101);
//		glPushMatrix();
//		glTranslatef(5, 0.0, -10.0);
//		glBegin(GL_QUADS);
//		glVertex3f(-1, -1, 0);
//		glVertex3f(1, -1, 0);
//		glVertex3f(1, 1, 0);
//		glVertex3f(-1, 1, 0);
//		glEnd();
//		glPopMatrix();
//	}
//	else
//	{
//		glColor3f(1.0, 0.0, 0.0);
//		glPushMatrix();
//		glTranslatef(-5, 0.0, -5.0);
//		glBegin(GL_QUADS);
//		glVertex3f(-1, -1, 0);
//		glVertex3f(1, -1, 0);
//		glVertex3f(1, 1, 0);
//		glVertex3f(-1, 1, 0);
//		glEnd();
//		glPopMatrix();
//		glColor3f(0.0, 0.0, 1.0);
//		glPushMatrix();
//		glTranslatef(5, 0.0, -10.0);
//		glBegin(GL_QUADS);
//		glVertex3f(-1, -1, 0);
//		glVertex3f(1, -1, 0);
//		glVertex3f(1, 1, 0);
//		glVertex3f(-1, 1, 0);
//		glEnd();
//		glPopMatrix();
//	}
//}
//
//void ProcessPicks(GLint nPicks, GLuint pickBuffer[])
//{
//	GLint i;
//	GLuint name, *ptr;
//	printf("ѡ�е���ĿΪ%d��\n", nPicks);
//	ptr = pickBuffer;
//	for (i = 0; i < nPicks; i++) {
//		name = *ptr;   //ѡ��ͼԪ�ڶ�ջ�е�λ��
//		ptr += 3;      //�������ֺ������Ϣ
//		ptr += name - 1; //����λ����Ϣ���ѡ�е�ͼԪ����
//		if (*ptr == 1) printf("��ѡ���˺�ɫͼԪ\n");
//		if (*ptr == 2) printf("��ѡ������ɫͼԪ\n");
//		if (*ptr == 3) printf("��ѡ������ɫͼԪ\n");
//		ptr++;
//	}
//	printf("\n\n");
//}
//void ChangeSize(int w, int h)
//{
//	winWidth = w;
//	winHeight = h;
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
//}
//void Display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	draw(GL_RENDER);
//	glFlush();
//}
//void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
//{
//	GLuint pickBuffer[pickSize];
//	GLint nPicks, vp[4];
//	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
//		glSelectBuffer(pickSize, pickBuffer);//����ѡ�񻺳���
//		glRenderMode(GL_SELECT); //����ѡ��ģʽ
//		glInitNames();  //��ʼ�����ֶ�ջ
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		glGetIntegerv(GL_VIEWPORT, vp);
//		//����һ��10��10��ѡ������
//		gluPickMatrix(GLdouble(xMouse), GLdouble(vp[3] - yMouse), 10.0, 10.0, vp);
//		gluOrtho2D(0.0, winWidth, 0.0, winHeight);
//
//		draw(GL_SELECT);
//		//�ָ�ͶӰ�任
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//		glFlush();
//		//���ѡ�񼯲����
//		nPicks = glRenderMode(GL_RENDER);
//		if (nPicks > 0)
//			ProcessPicks(nPicks, pickBuffer);
//		glutPostRedisplay();
//	}
//}

//void SelectObject(GLint button, GLint action, GLint x, GLint y)
//{
//	GLuint selectBuff[32] = { 0 };//����һ������ѡ����������
//	GLint hits, viewport[4];
//	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
//		glGetIntegerv(GL_VIEWPORT, viewport); //���viewport
//		glSelectBuffer(64, selectBuff); //����OpenGL��ʼ�� selectbuffer
//		glRenderMode(GL_SELECT); //����ѡ��ģʽ
//		glInitNames(); //��ʼ������ջ
//		glPushName(0); //������ջ�з���һ����ʼ�����֣�����Ϊ��0��
//		glMatrixMode(GL_PROJECTION); //����ͶӰ�׶�׼��ʰȡ
//		glPushMatrix(); //������ǰ��ͶӰ����
//		glLoadIdentity(); //���뵥λ����
//		float m[16];
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		gluPickMatrix(x, // �趨����ѡ���Ĵ�С������ʰȡ���󣬾�������Ĺ�ʽ 
//			viewport[3] - y, // viewport[3]������Ǵ��ڵĸ߶ȣ���������ת��ΪOpenGL����
//			2, 2, // ѡ���Ĵ�СΪ2��2
//			viewport // �ӿ���Ϣ�������ӿڵ���ʼλ�úʹ�С
//		);
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		glOrtho(-10, 10, -10, 10, -10, 10); //ʰȡ�������ͶӰ���������Ϳ�����ѡ���Ŵ�Ϊ������һ����
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		draw(GL_SELECT); // �ú�������Ⱦ���壬���Ҹ������趨����
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix(); // ����������ͶӰ�任
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		hits = glRenderMode(GL_RENDER); // ��ѡ��ģʽ��������ģʽ,�ú�������ѡ�񵽶���ĸ���
//		if (hits > 0)
//			ProcessPicks(hits, selectBuff); // ѡ��������
//	}
//	glutPostRedisplay();
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("ʰȡ����");
//	glutDisplayFunc(Display);
//	glutReshapeFunc(ChangeSize);
//	glutMouseFunc(SelectObject);
//	Initial();
//	glutMainLoop();
//	return 0;
//}






