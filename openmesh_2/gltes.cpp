//
//#include <gl/glut.h>
//#include "stdio.h"
//const GLint pickSize = 32;
//int winWidth = 400, winHeight = 300;
//void Initial(void)
//{
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//}
//void DrawRect(GLenum mode)
//{
//	if (mode == GL_SELECT) glPushName(1);//ѹ���ջ
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glRectf(60.0f, 50.0f, 150.0f, 150.0f);
//
//	if (mode == GL_SELECT) glPushName(2); //ѹ���ջ
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glRectf(230.0f, 50.0f, 330.0f, 150.0f);
//	if (mode == GL_SELECT) glPushName(3); //ѹ���ջ
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glRectf(140.0f, 140.0f, 240.0f, 240.0f);
//}
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
//	DrawRect(GL_RENDER);
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
//		gluPickMatrix(GLdouble(xMouse), GLdouble(vp[3] - yMouse), 2.0, 2.0, vp);
//		gluOrtho2D(0.0, winWidth, 0.0, winHeight);
//
//		DrawRect(GL_SELECT);
//		//�ָ�ͶӰ�任
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//		glFlush();
//		//���ѡ�񼯲����
//		nPicks = glRenderMode(GL_RENDER);
//		if(nPicks>0)
//		ProcessPicks(nPicks, pickBuffer);
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 300);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("ʰȡ����");
//	glutDisplayFunc(Display);
//	glutReshapeFunc(ChangeSize);
//	glutMouseFunc(MousePlot);
//	Initial();
//	glutMainLoop();
//	return 0;
//}
//
//
