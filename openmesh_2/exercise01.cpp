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
////	if (mode == GL_SELECT) glPushName(1);//压入堆栈
////	glColor3f(1.0f, 0.0f, 0.0f);
////	glRectf(60.0f, 50.0f, 150.0f, 150.0f);
////
////	if (mode == GL_SELECT) glPushName(2); //压入堆栈
////	glColor3f(0.0f, 1.0f, 0.0f);
////	glRectf(230.0f, 50.0f, 330.0f, 150.0f);
////	if (mode == GL_SELECT) glPushName(3); //压入堆栈
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
//	printf("选中的数目为%d个\n", nPicks);
//	ptr = pickBuffer;
//	for (i = 0; i < nPicks; i++) {
//		name = *ptr;   //选中图元在堆栈中的位置
//		ptr += 3;      //跳过名字和深度信息
//		ptr += name - 1; //根据位置信息获得选中的图元名字
//		if (*ptr == 1) printf("你选择了红色图元\n");
//		if (*ptr == 2) printf("你选择了绿色图元\n");
//		if (*ptr == 3) printf("你选择了蓝色图元\n");
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
//		glSelectBuffer(pickSize, pickBuffer);//设置选择缓冲区
//		glRenderMode(GL_SELECT); //激活选择模式
//		glInitNames();  //初始化名字堆栈
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		glGetIntegerv(GL_VIEWPORT, vp);
//		//定义一个10×10的选择区域
//		gluPickMatrix(GLdouble(xMouse), GLdouble(vp[3] - yMouse), 10.0, 10.0, vp);
//		gluOrtho2D(0.0, winWidth, 0.0, winHeight);
//
//		draw(GL_SELECT);
//		//恢复投影变换
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//		glFlush();
//		//获得选择集并输出
//		nPicks = glRenderMode(GL_RENDER);
//		if (nPicks > 0)
//			ProcessPicks(nPicks, pickBuffer);
//		glutPostRedisplay();
//	}
//}

//void SelectObject(GLint button, GLint action, GLint x, GLint y)
//{
//	GLuint selectBuff[32] = { 0 };//创建一个保存选择结果的数组
//	GLint hits, viewport[4];
//	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
//		glGetIntegerv(GL_VIEWPORT, viewport); //获得viewport
//		glSelectBuffer(64, selectBuff); //告诉OpenGL初始化 selectbuffer
//		glRenderMode(GL_SELECT); //进入选择模式
//		glInitNames(); //初始化名字栈
//		glPushName(0); //在名字栈中放入一个初始化名字，这里为‘0’
//		glMatrixMode(GL_PROJECTION); //进入投影阶段准备拾取
//		glPushMatrix(); //保存以前的投影矩阵
//		glLoadIdentity(); //载入单位矩阵
//		float m[16];
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		gluPickMatrix(x, // 设定我们选择框的大小，建立拾取矩阵，就是上面的公式 
//			viewport[3] - y, // viewport[3]保存的是窗口的高度，窗口坐标转换为OpenGL坐标
//			2, 2, // 选择框的大小为2，2
//			viewport // 视口信息，包括视口的起始位置和大小
//		);
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		glOrtho(-10, 10, -10, 10, -10, 10); //拾取矩阵乘以投影矩阵，这样就可以让选择框放大为和视体一样大
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		draw(GL_SELECT); // 该函数中渲染物体，并且给物体设定名字
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix(); // 返回正常的投影变换
//		glGetFloatv(GL_PROJECTION_MATRIX, m);
//		hits = glRenderMode(GL_RENDER); // 从选择模式返回正常模式,该函数返回选择到对象的个数
//		if (hits > 0)
//			ProcessPicks(hits, selectBuff); // 选择结果处理
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
//	glutCreateWindow("拾取操作");
//	glutDisplayFunc(Display);
//	glutReshapeFunc(ChangeSize);
//	glutMouseFunc(SelectObject);
//	Initial();
//	glutMainLoop();
//	return 0;
//}






