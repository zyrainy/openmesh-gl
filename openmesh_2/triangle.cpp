//#  include <GL/glew.h>  
//#  include <GL/freeglut.h>  
//
//void userInit();
//void reshape(int w, int h);
//void display(void);
//void keyboardAction(unsigned char key, int x, int y);
////VBO句柄  
//GLuint vboId;
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(512, 512);
//	glutCreateWindow("Triangle demo");
//
//	glewInit();
//	userInit();
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboardAction);
//	glutMainLoop();
//	return 0;
//}
////自定义初始化函数  
//void userInit()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glColor4f(1.0, 1.0, 0.0, 0.0);
//	//创建顶点数据  
//	GLfloat vertices[] = {
//	   -0.5,-0.5,0.0,
//	   0.5,0.0,0.0,
//	   0.0,0.5,0.0
//	};
//	//分配vbo句柄  
//	glGenBuffersARB(1, &vboId);
//	//GL_ARRAY_BUFFER_ARB表示作为顶点数组解析  
//	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);
//	//拷贝数据  
//	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(vertices),
//		vertices, GL_STATIC_DRAW_ARB);
//	glBindBufferARB(GL_VERTEX_ARRAY, 0);
//}
////调整窗口大小回调函数  
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//}
////绘制回调函数  
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);//绑定vbo  
//	glEnableClientState(GL_VERTEX_ARRAY);//启用顶点数组属性  
//	glVertexPointer(3, GL_FLOAT, 0, 0);//如何解析vbo中数据  
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);//解除绑定  
//	glFlush();
//}
////键盘按键回调函数  
//void keyboardAction(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 033:  // Escape key  
//		exit(EXIT_SUCCESS);
//		break;
//	}
//}


//#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//void init(void)
//{
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//}
//
//void drawGeometry(GLenum mode)
//{
//	glBegin(GL_LINE_STRIP);
//	glNormal3f(0.0, 0.0, 1.0);
//	glVertex3f(30.0, 30.0, 0.0);
//	glVertex3f(50.0, 60.0, 0.0);
//	glVertex3f(70.0, 40.0, 0.0);
//	glEnd();
//	if (mode == GL_FEEDBACK)
//		glPassThrough(1.0);
//	glBegin(GL_POINTS);
//	glVertex3f(-100.0, -100.0, -100.0);  /*  will be clipped  */
//	glEnd();
//	if (mode == GL_FEEDBACK)
//		glPassThrough(2.0);
//	glBegin(GL_POINTS);
//	glNormal3f(0.0, 0.0, 1.0);
//	glVertex3f(50.0, 50.0, 0.0);
//	glEnd();
//}
//
//void print3DcolorVertex(GLint size, GLint *count,
//	GLfloat *buffer)
//{
//	int i;
//
//	printf("  ");
//	for (i = 0; i < 7; i++) {
//		printf("%4.2f ", buffer[size - (*count)]);
//		*count = *count - 1;
//	}
//	printf("\n");
//}
//
//void printBuffer(GLint size, GLfloat *buffer)
//{
//	GLint count;
//	GLfloat token;
//
//	count = size;
//	while (count) {
//		token = buffer[size - count]; count--;
//		if (token == GL_PASS_THROUGH_TOKEN) {
//			printf("GL_PASS_THROUGH_TOKEN\n");
//			printf("  %4.2f\n", buffer[size - count]);
//			count--;
//		}
//		else if (token == GL_POINT_TOKEN) {
//			printf("GL_POINT_TOKEN\n");
//			print3DcolorVertex(size, &count, buffer);
//		}
//		else if (token == GL_LINE_TOKEN) {
//			printf("GL_LINE_TOKEN\n");
//			print3DcolorVertex(size, &count, buffer);
//			print3DcolorVertex(size, &count, buffer);
//		}
//		else if (token == GL_LINE_RESET_TOKEN) {
//			printf("GL_LINE_RESET_TOKEN\n");
//			print3DcolorVertex(size, &count, buffer);
//			print3DcolorVertex(size, &count, buffer);
//		}
//	}
//}
//
//void display(void)
//{
//	GLfloat feedBuffer[1024];
//	GLint size;
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 100.0, 0.0, 100.0, 0.0, 1.0);
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawGeometry(GL_RENDER);
//	glFeedbackBuffer(1024, GL_3D_COLOR, feedBuffer);
//	(void)glRenderMode(GL_FEEDBACK);
//	drawGeometry(GL_FEEDBACK);
//
//	size = glRenderMode(GL_RENDER);
//	printBuffer(size, feedBuffer);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(100, 100);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
///* Change these values for a different transformation  */
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//void mouse(int button, int state, int x, int y)
//{
//	GLint viewport[4];
//	GLdouble mvmatrix[16], projmatrix[16];
//	GLint realy;  /*  OpenGL y coordinate position  */
//	GLdouble wx, wy, wz;  /*  returned world x, y, z coords  */
//	switch (button) {
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			glGetIntegerv(GL_VIEWPORT, viewport);
//			glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
//			glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
//			/*  note viewport[3] is height of window in pixels  */
//			realy = viewport[3] - (GLint)y - 1;
//			printf("Coordinates at cursor are (%4d, %4d)\n", x, realy);
//			gluUnProject((GLdouble)x, (GLdouble)realy, 0.0,
//				mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
//			printf("World coords at z=0.0 are (%f, %f, %f)\n",
//				wx, wy, wz);
//			gluUnProject((GLdouble)x, (GLdouble)realy, 1.0,
//				mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
//			printf("World coords at z=1.0 are (%f, %f, %f)\n",
//				wx, wy, wz);
//		}
//		break;
//	case GLUT_RIGHT_BUTTON:
//		if (state == GLUT_DOWN)
//			exit(0);
//		break;
//	default:
//		break;
//	}
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 27:
//		exit(0);
//		break;
//	}
//}
///*
// *  Open window, register input callback functions
// */
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glEnable(GL_DEPTH_TEST);
//	glShadeModel(GL_FLAT);
//	glDepthRange(0.0, 1.0);  /* The default z mapping */
//}
//
//void drawRects(GLenum mode)
//{
//	if (mode == GL_SELECT)
//		glLoadName(1);
//	glBegin(GL_QUADS);
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex3i(2, 0, 0);
//	glVertex3i(2, 6, 0);
//	glVertex3i(6, 6, 0);
//	glVertex3i(6, 0, 0);
//	glEnd();
//	if (mode == GL_SELECT)
//		glLoadName(2);
//	glBegin(GL_QUADS);
//	glColor3f(0.0, 1.0, 1.0);
//	glVertex3i(3, 2, -1);
//	glVertex3i(3, 8, -1);
//	glVertex3i(8, 8, -1);
//	glVertex3i(8, 2, -1);
//	glEnd();
//	if (mode == GL_SELECT)
//		glLoadName(3);
//	glBegin(GL_QUADS);
//	glColor3f(1.0, 0.0, 1.0);
//	glVertex3i(0, 2, -2);
//	glVertex3i(0, 7, -2);
//	glVertex3i(5, 7, -2);
//	glVertex3i(5, 2, -2);
//	glEnd();
//}
//
//void processHits(GLint hits, GLuint buffer[])
//{
//	unsigned int i, j;
//	GLuint names, *ptr;
//
//	printf("hits = %d\n", hits);
//	ptr = (GLuint *)buffer;
//	for (i = 0; i < hits; i++) {  /* for each hit  */
//		names = *ptr;
//		printf(" number of names for hit = %d\n", names); ptr++;
//		printf("  z1 is %g;", (float)*ptr / 0x7fffffff); ptr++;
//		printf(" z2 is %g\n", (float)*ptr / 0x7fffffff); ptr++;
//		printf("   the name is ");
//		for (j = 0; j < names; j++) {  /* for each name */
//			printf("%d ", *ptr); ptr++;
//		}
//		printf("\n");
//	}
//}
//
//#define BUFSIZE 512
//
//void pickRects(int button, int state, int x, int y)
//{
//	GLuint selectBuf[BUFSIZE];
//	GLint hits;
//	GLint viewport[4];
//
//	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
//		return;
//	glGetIntegerv(GL_VIEWPORT, viewport);
//
//	glSelectBuffer(BUFSIZE, selectBuf);
//	(void)glRenderMode(GL_SELECT);
//
//	glInitNames();
//	glPushName(0);
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	/*  create 5x5 pixel picking region near cursor location */
//	gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y),
//		10.0, 10.0, viewport);
//	glOrtho(0, 200, 0, 200, 0, 8);
//	drawRects(GL_SELECT);
//	glPopMatrix();
//	glFlush();
//
//	hits = glRenderMode(GL_RENDER);
//	processHits(hits, selectBuf);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	drawRects(GL_RENDER);
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 200.0, 0.0, 200.0, 0, 8);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(200, 200);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutMouseFunc(pickRects);
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}



//#include <Windows.h>
//#include <GL/glut.h>
//
//#pragma comment(lib,"glut32.lib")
//#pragma comment(lib,"glu32.lib")
//#pragma comment(lib,"opengl32.lib")
//
//const int		BUFSIZE = 512;
//int				g_iWidth = 800;
//int				g_iHeight = 600;
//float			g_fAngle = 0;
//const GLfloat	red[] = { 231.0 / 255.0, 36.0 / 255.0, 46.0 / 255.0, 1.0 };
//const GLfloat	yellow[] = { 253.0 / 255.0, 208.0 / 255.0, 0.0 / 255.0, 1.0 };
//
//class Cube
//{
//public:
//	double x, y, z;
//	bool selected;
//
//	Cube()
//		: x(0), y(0), z(0)
//		, selected(false)
//	{}
//
//	void Draw()
//	{
//		glPushMatrix();
//		{
//			glTranslated(x, y, z);
//			if (selected)
//			{
//				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
//			}
//			else
//			{
//				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellow);
//			}
//			glutSolidCube(1.0);
//		}
//		glPopMatrix();
//	}
//};
//Cube	cube[4];
//
//void PaintScreen(GLenum mode)
//{
//	glPushMatrix();
//	glRotated(g_fAngle, 0.0, 1.0, 0.0);
//	for (int i = 0; i < 4; i++)
//	{
//		if (mode == GL_SELECT)
//		{
//			glLoadName(i);
//		}
//		cube[i].Draw();
//	}
//	glPopMatrix();
//}
//void Init()
//{
//	glClearColor(84.0 / 255.0, 0.0 / 255.0, 125.0 / 255.0, 0.0);
//	glClearDepth(1.0);
//	glDepthFunc(GL_LESS);
//	glEnable(GL_DEPTH_TEST);
//	glShadeModel(GL_SMOOTH);
//
//	for (int i = 0; i < 4; i++)
//	{
//		cube[i].x = i * 2 - 3;
//	}
//}
//
//void Reshape(int Width, int Height)
//{
//	if (0 == Height)
//	{
//		Height = 1;
//	}
//	glViewport(0, 0, Width, Height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(30.0, (GLfloat)Width / (GLfloat)Height, 1.0, 20.0);
//}
//
//void DrawGLScene()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(6.0, 4.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	PaintScreen(GL_RENDER);
//
//	glDisable(GL_LIGHT0);
//	glDisable(GL_LIGHTING);
//	glDisable(GL_DEPTH_TEST);
//
//	glutSwapBuffers();
//}
//
//void Idle()
//{
//	g_fAngle += 0.5;
//	if (g_fAngle >= 360)
//	{
//		g_fAngle = 0;
//	}
//	//调用DrawGLScene函数
//	glutPostRedisplay();
//}
//
//void KeyBoardCB(unsigned char key, int x, int y)
//{
//	if (key == 27)
//	{
//		exit(0);
//	}
//}
//
//void MouseCB(int button, int state, int mousex, int mousey)
//{
//	if (button != GLUT_LEFT || state != GLUT_DOWN)
//	{
//		return;
//	}
//	GLuint selectBuf[BUFSIZE];
//	GLint hits;
//	GLint viewport[4];
//	static bool IsFirst = true;
//
//	glGetIntegerv(GL_VIEWPORT, viewport);
//	glSelectBuffer(BUFSIZE, selectBuf);
//
//	glRenderMode(GL_SELECT);				// Enter the SELECT render mode
//	glInitNames();
//	glPushName(-1);
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluPickMatrix((GLdouble)mousex, (GLdouble)(viewport[3] - mousey), 5.0, 5.0, viewport);
//	gluPerspective(30.0, (GLfloat)g_iWidth / (GLfloat)g_iHeight, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//
//	PaintScreen(GL_SELECT);
//	glPopMatrix();
//	glFlush();
//
//	hits = glRenderMode(GL_RENDER);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glViewport(0, 0, g_iWidth, g_iHeight);
//	gluPerspective(30.0, (GLfloat)g_iWidth / (GLfloat)g_iHeight, 1.0, 20.0);
//
//	if (hits)
//	{
//		int n = 0;
//		double minz = selectBuf[1];
//		for (int i = 1; i < hits; i++)
//		{
//			if (selectBuf[1 + i * 4] < minz)
//			{
//				n = i;
//				minz = selectBuf[1 + i * 4];
//			}
//		}
//		//hit记录第四项为ID编号
//		cube[selectBuf[3 + n * 4]].selected = !(cube[selectBuf[3 + n * 4]].selected);
//	}
//	//glutPostRedisplay();
//}
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("OpenGL Select Obj");
//
//	Init();
//	glutDisplayFunc(DrawGLScene);
//	glutReshapeFunc(Reshape);
//
//	glutMouseFunc(MouseCB);
//	glutKeyboardFunc(KeyBoardCB);
//	glutIdleFunc(Idle);
//
//	glutMainLoop();
//
//	return 0;
//}