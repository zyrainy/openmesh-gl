//#include <iostream>  
//#include <OpenMesh/Core/IO/MeshIO.hh>  
//#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>  
//#include "GL\glut.h"
//#include <math.h>
//#include <Windows.h>
//#include <string>
//
//using namespace std;
//typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;
//
//
////鼠标交互有关的
//int mousetate = 0; //鼠标当前的状态
//GLfloat Oldx = 0.0; // 点击之前的位置
//GLfloat Oldy = 0.0;
////与实现角度大小相关的参数，只需要两个就可以完成
//float xRotate = 0.0f;
//float yRotate = 0.0f;
//float tx = 0.0f;
//float ty = 0.0f;
//float scale = 1;
//
////文件读取有关的
//MyMesh mesh;
//const string file_1 = "cow.obj";
//const string file_2 = "cactus.ply";
//const string file_3 = "Armadillo.off";
//int currentfile = 1;
//
//GLuint showFaceList, showWireList;
//int showstate = 1;
//bool showFace = true;
//bool showWire = false;
//bool showFlatlines = false;
//
////初始化顶点和面   
//void initGL()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClearDepth(2.0);
//	//glShadeModel(GL_SMOOTH);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glEnable(GL_DEPTH_TEST); //用来开启深度缓冲区的功能，启动后OPengl就可以跟踪Z轴上的像素，那么它只有在前面没有东西的情况下才会绘制这个像素，在绘制3d时，最好启用，视觉效果会比较真实
//							 // ------------------- Lighting  
//	glEnable(GL_LIGHTING); // 如果enbale那么就使用当前的光照参数去推导顶点的颜色
//	glEnable(GL_LIGHT0); //第一个光源，而GL_LIGHT1表示第二个光源
//						 // ------------------- Display List  
//	showFaceList = glGenLists(1);
//	showWireList = glGenLists(1);
//	int temp = mesh.n_edges();
//
//	// 绘制 wire 
//	glNewList(showWireList, GL_COMPILE);
//	glDisable(GL_LIGHTING);
//	glLineWidth(1.0f);
//	glColor3f(0.5f, 0.5f, 0.5f);
//	glBegin(GL_LINES);
//	for (MyMesh::HalfedgeIter he_it = mesh.halfedges_begin(); he_it != mesh.halfedges_end(); ++he_it) {
//		//链接这个有向边的起点和终点
//		glVertex3fv(mesh.point(mesh.from_vertex_handle(*he_it)).data());
//		glVertex3fv(mesh.point(mesh.to_vertex_handle(*he_it)).data());
//	}
//	glEnd();
//	glEnable(GL_LIGHTING);
//	glEndList();
//
//	// 绘制flat
//	glNewList(showFaceList, GL_COMPILE);
//	int i = 0;
//	for (MyMesh::FaceIter f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it) {
//		//newcodes begin
//		//newcodes end
//		glBegin(GL_TRIANGLES);
//		for (MyMesh::FaceVertexIter fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
//			glNormal3fv(mesh.normal(*fv_it).data());
//			glVertex3fv(mesh.point(*fv_it).data());
//		}
//		glEnd();
//	}
//	glEndList();
//}
//
//// 当窗体改变大小的时候
//void myReshape(GLint w, GLint h)
//{
//	glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w > h)
//		glOrtho(-static_cast<GLdouble>(w) / h, static_cast<GLdouble>(w) / h, -1.0, 1.0, -100.0, 100.0);
//	else
//		glOrtho(-1.0, 1.0, -static_cast<GLdouble>(h) / w, static_cast<GLdouble>(h) / w, -100.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//
//// 读取文件的函数
//void readfile(string file) {
//	// 请求顶点法线 vertex normals
//	mesh.request_vertex_normals();
//	//如果不存在顶点法线，则报错 
//	if (!mesh.has_vertex_normals())
//	{
//		cout << "错误：标准定点属性 “法线”不存在" << endl;
//		return;
//	}
//	// 如果有顶点发现则读取文件 
//	OpenMesh::IO::Options opt;
//	if (!OpenMesh::IO::read_mesh(mesh, file, opt))
//	{
//		cout << "无法读取文件:" << file << endl;
//		return;
//	}
//	else cout << "成功读取文件:" << file << endl;
//	cout << endl; // 为了ui显示好看一些
//				  //如果不存在顶点法线，则计算出
//	if (!opt.check(OpenMesh::IO::Options::VertexNormal))
//	{
//		// 通过面法线计算顶点法线
//		mesh.request_face_normals();
//		// mesh计算出顶点法线
//		mesh.update_normals();
//		// 释放面法线
//		mesh.release_face_normals();
//	}
//}
//
////  键盘交互 1. 切换文件 2.切换显示
//void mySpecial(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_F1:
//		cout << "读取文件:" << file_1 << " 中......" << endl;
//		readfile(file_1);
//		scale = 1.0;
//		currentfile = 1;
//		initGL();
//		break;
//	case GLUT_KEY_F2:
//		cout << "读取文件:" << file_2 << " 中......" << endl;
//		readfile(file_2);
//		scale = 1.2;
//		currentfile = 2;
//		initGL();
//		break;
//	case GLUT_KEY_F3:
//		cout << "读取文件:" << file_3 << " 中......" << endl;
//		readfile(file_3);
//		scale = 0.01;
//		currentfile = 3;
//		initGL();
//		break;
//	case GLUT_KEY_F4:
//		if (showFace == true) {
//			showFace = false;
//			showWire = true;
//			cout << "切换显示模式为：WireFrame" << endl;
//		}
//		else if (showWire == true)
//		{
//			showWire = false;
//			showFlatlines = true;
//			cout << "切换显示模式为：Flatlines" << endl;
//		}
//		else if (showFlatlines == true) {
//			showFlatlines = false;
//			showFace = true;
//			cout << "切换显示模式为：Flat" << endl;
//		}
//		break;
//	case GLUT_KEY_LEFT:
//		tx -= 0.01;
//		break;
//	case GLUT_KEY_RIGHT:
//		tx += 0.01;
//		break;
//	case GLUT_KEY_UP:
//		ty += 0.01;
//		break;
//	case GLUT_KEY_DOWN:
//		ty -= 0.01;
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
////处理拾取信息
//void ProcessPicks(GLint nPicks, GLuint pickBuffer[])
//{
//	GLint i;
//	GLuint name, *ptr;
//	printf("选中的数目为%d个\n", nPicks);
//
//	for (i = 0; i < nPicks; i++)
//	{
//		name = pickBuffer[3 + i * 4];
//		//select_point = name;//每个选中物体有占用名字栈中4个单位，第4个是物体名字值
//		cout << "第" << name << "个点" << endl;
//	}
//	printf("\n\n");
//}
////
////void draw(GLenum mode) {
////	int i = 0;
////	for (MyMesh::FaceIter f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it) {
////		//newcodes begin
////
////		//glPushName(i++);
////		
////			//newcodes end
////		glBegin(GL_TRIANGLES);
////		for (MyMesh::FaceVertexIter fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
////			glNormal3fv(mesh.normal(*fv_it).data());
////			glVertex3fv(mesh.point(*fv_it).data());
////		}
////		glEnd();
////	}
////}
//
//// 鼠标交互
//void myMouse(int button, int state, int x, int y)
//{
//	//newcodes begin
//	//GLuint selectBuffer[6000]; //存放物体名称的栈
//	//GLint hits; //存放被选中对象个数
//	//GLint viewport[4]; //存放可视区参数
//
//	//newcodes end
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		//newcodes begin
//		//glGetIntegerv(GL_VIEWPORT, viewport); //获取当前视口坐标参数
//		//glSelectBuffer(6000, selectBuffer); //选择名称栈存放被选中的名称
//		//glRenderMode(GL_SELECT); //设置当前为选择模式
//		//glInitNames(); //初始化名称栈
//		//glPushName(0);
//		//glMatrixMode(GL_PROJECTION);
//		//glPushMatrix();
//		//glLoadIdentity();
//		//gluPickMatrix(x, viewport[3] - y, 10, 10, viewport); //创建用于选择的投影矩阵栈
//		//gluOrtho2D(0, 800, 0, 500); //设置投影方式
//		//draw(GL_SELECT); //绘制场景,选择模式
//		////恢复投影变换
//		//glMatrixMode(GL_PROJECTION);
//		//glPopMatrix();
//		//glFlush();
//		//hits = glRenderMode(GL_RENDER);
//		//glMatrixMode(GL_MODELVIEW);
//
//		////if (hits > 0)
//		//	ProcessPicks(hits, selectBuffer);
//		
//		//newcodes end
//
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//		mousetate = 0;
//	//滚轮事件
//	if (state == GLUT_UP && button == 3) {
//		if (currentfile == 3)
//			scale -= 0.002;
//		else
//			scale -= 0.1;
//	}
//	if (state == GLUT_UP && button == 4) {
//		if (currentfile == 3)
//			scale += 0.002;
//		else
//			scale += 0.1;
//	}
//	
//	glutPostRedisplay();
//}
//
//// 鼠标运动时
//void onMouseMove(int x, int y) {
//	if (mousetate) {
//		//x对应y是因为对应的是法向量
//		yRotate += x - Oldx;
//		glutPostRedisplay();
//		Oldx = x;
//		xRotate += y - Oldy;
//		glutPostRedisplay();
//		Oldy = y;
//	}
//}
//
//void myDisplay()
//{
//	//要清除之前的深度缓存
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	//与显示相关的函数
//	glRotatef(xRotate, 1.0f, 0.0f, 0.0f); // 让物体旋转的函数 第一个参数是角度大小，后面的参数是旋转的法向量
//	glRotatef(yRotate, 0.0f, 1.0f, 0.0f);
//	//glTranslatef(0.0f, 0.0f, ty);
//	glTranslatef(tx, ty, 0.0f);
//	glScalef(scale, scale, scale); // 缩放
//	//cout << 1 << endl;
//	//							   //每次display都要使用glcalllist回调函数显示想显示的顶点列表
//	//draw(GL_RENDER);
//	if (showFace)
//	{
//		glCallList(showFaceList);
//	}
//	if (showFlatlines) {
//		glCallList(showFaceList);
//		glCallList(showWireList);
//	}
//	if (showWire)
//		glCallList(showWireList);
//
//	glutSwapBuffers(); //这是Opengl中用于实现双缓存技术的一个重要函数
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // GLUT_Double 表示使用双缓存而非单缓存
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(800, 500);
//	glutCreateWindow("Mesh Viewer");
//	//一开始默认读取文件1
//	readfile(file_1);
//	initGL();
//	glutMouseFunc(myMouse);
//	glutMotionFunc(onMouseMove); // 鼠标移动的时候的函数
//	glutSpecialFunc(&mySpecial); //键盘
//	glutReshapeFunc(&myReshape);
//	glutDisplayFunc(&myDisplay);
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//// 鼠标交互+拾取三角面片
//void myMouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[SIZE]; //存放物体名称的栈
//	GLint hits; //存放被选中对象个数
//	GLint viewport[4]; //存放可视区参数
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		glGetIntegerv(GL_VIEWPORT, viewport); //获取当前视口坐标参数
//		glSelectBuffer(SIZE, selectBuffer); //选择名称栈存放被选中的名称
//		glRenderMode(GL_SELECT); //设置当前为选择模式
//		glInitNames(); //初始化名称栈
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(x, viewport[3] - y, N, N, viewport); //创建用于选择的投影矩阵栈
//		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); //设置投影方式
//		draw(GL_SELECT); //绘制场景,选择模式
//		glPopMatrix();
//
//		glFlush();
//		hits = glRenderMode(GL_RENDER);
//		glMatrixMode(GL_MODELVIEW);
//
//		if (hits > 0)
//			processHits(hits, selectBuffer);
//
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//		mousetate = 0;
//	//滚轮事件
//	if (state == GLUT_UP && button == 3) {
//		if (currentfile == 3)
//			scale -= 0.002;
//		else
//			scale -= 0.1;
//	}
//	if (state == GLUT_UP && button == 4) {
//		if (currentfile == 3)
//			scale += 0.002;
//		else
//			scale += 0.1;
//	}
//	glutPostRedisplay();
//}
//
////
//#include <iostream>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include<math.h>
//
//using namespace std;
//int SCREEN_WIDTH = 400; //屏幕尺寸
//int SCREEN_HEIGHT = 400;
//
//int select_point = 0; //1 是第一个点，2是第二个，以此类推
//
//void init()
//{
//	glClearColor(1, 1, 1, 1);
//}
//
//void draw(GLenum mode)
//{
//	glPointSize(10.0f);
//	const static GLfloat color_selected[] = { 1.0f,0.0f,0.0f };
//	const static GLfloat color_unselected[] = { 0.0f,0.0f,1.0f };
//
//	for (int i = 1; i <= 5; i++)//5个点
//	{
//		if (mode == GL_SELECT)
//			glLoadName(i);
//		glColor3fv((select_point == i) ? color_selected : color_unselected);
//		glBegin(GL_POINTS);
//		glVertex2f(i * 70, 200);
//		glEnd();
//	}
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	draw(GL_RENDER); //设置渲染模式
//	glFlush();
//}
//
//void reshape(int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
//	glMatrixMode(GL_MODELVIEW);
//
//}
//
//void processHits(GLint hits, GLuint buffer[])
//{
//	unsigned int i;
//	GLuint name;
//	for (i = 0; i < hits; i++)
//	{
//		name = buffer[3 + i * 4];
//		select_point = name;//每个选中物体有占用名字栈中4个单位，第4个是物体名字值
//		cout << "第" << name << "个点" << endl;
//	}
//}
//
//#define SIZE 500
//
//#define N 10
//
//void mouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[SIZE]; //存放物体名称的栈
//	GLint hits; //存放被选中对象个数
//	GLint viewport[4]; //存放可视区参数
//	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) //当鼠标左键按下时
//	{
//		glGetIntegerv(GL_VIEWPORT, viewport); //获取当前视口坐标参数
//		glSelectBuffer(SIZE, selectBuffer); //选择名称栈存放被选中的名称
//		glRenderMode(GL_SELECT); //设置当前为选择模式
//		glInitNames(); //初始化名称栈
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(x, viewport[3] - y, N, N, viewport); //创建用于选择的投影矩阵栈
//		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); //设置投影方式
//		draw(GL_SELECT); //绘制场景,选择模式
//		glPopMatrix();
//
//		glFlush();
//		hits = glRenderMode(GL_RENDER);
//		glMatrixMode(GL_MODELVIEW);
//
//		if (hits > 0)
//			processHits(hits, selectBuffer);
//		glutPostRedisplay();
//	}
//
//	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) //当鼠标左键抬起时
//	{
//		select_point = 0;
//		glRenderMode(GL_RENDER);
//		draw(GL_RENDER);
//		glutPostRedisplay();
//	}
//
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("图形拾取编程实例");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 1;
//}
//
//#include <GL/glut.h>
//#include<math.h>
//int xIndex, yIndex;//用于查看鼠标最近的控制点
//bool onwork = false;
//GLfloat pts[4][4][3] = {
//		{ { -5, 0, 8 }, { -2, 2, 0 }, { 2, 2, 0 }, { 5, 0, 8 } },
//		{ { -5, 3, 2 }, { -2, 3, 0 }, { 2, 3, 0 }, { 5, 3, 2 } },
//		{ { -5, 6, 8 }, { -2, 6, 3 }, { 2, 6, 3 }, { 5, 6, 8 } },
//		{ { -5, 9, 0 }, { -2, 7, 0 }, { 2, 7, 0 }, { 5, 9, 0 } }
//};
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
//	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &pts[0][0][0]);
//	glEnable(GL_MAP2_VERTEX_3);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//}
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(1.0, 0.0, 0.0);
//	int i, j;
//	for (j = 0; j <= 20; j++) {
//		glBegin(GL_LINE_STRIP);
//		for (i = 0; i <= 20; i++) {
//			glEvalCoord2f((GLfloat)i / 20.0, (GLfloat)j / 20.0);
//		}
//		glEnd();
//		glBegin(GL_LINE_STRIP);
//		for (i = 0; i <= 20; i++) {
//			glEvalCoord2f((GLfloat)j / 20, (GLfloat)i / 20.0);
//		}
//		glEnd();
//	}
//	glColor3f(0.0, 0.0, 1.0);
//	glPointSize(2.5f);
//	glBegin(GL_POINTS);
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			glVertex2fv(pts[i][j]);
//		}
//	}
//	glEnd();
//	glFlush();
//}
//void display()
//{
//	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &pts[0][0][0]);
//	glEnable(GL_MAP2_VERTEX_3);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	draw();
//}
////计算鼠标点击处与控制点之间的距离
//double distance(int x, int y, float x2, float y2)
//{
//	double dis = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
//	return dis;
//}
////将屏幕坐标转换为世界坐标
//void change(int *result)
//{
//	int x = result[0], y = result[1];
//	GLint viewport[4];
//	GLdouble modelview[16];
//	GLdouble projection[16];
//	GLfloat winx, winy, winz;
//	GLdouble posX, posY, posZ;
//	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
//	glGetDoublev(GL_PROJECTION_MATRIX, projection);
//	glGetIntegerv(GL_VIEWPORT, viewport);
//	winx = (float)x;
//	winy = (float)viewport[3] - (float)y;
//	glReadPixels(x, int(winy), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winz);
//	gluUnProject(winx, winy, winz, modelview, projection, viewport, &posX, &posY, &posZ);
//	result[0] = posX;
//	result[1] = posY;
//}
//void click(int button, int state, int winx, int winy)
//{
//	int result[] = { winx, winy };
//	change(result);
//	int x = result[0], y = result[1];
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		double dis = distance(x, y, pts[0][0][0], pts[0][0][1]);
//		double disTemp = dis;
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 4; j++) {
//				dis = distance(x, y, pts[i][j][0], pts[i][j][1]);
//				if (dis <= disTemp) {
//					xIndex = i;
//					yIndex = j;
//					disTemp = dis;
//					onwork = true;
//				}
//			}
//		}
//	}
//}
//void motion(int winx, int winy)
//{
//	int result[] = { winx, winy };
//	change(result);
//	int x = result[0], y = result[1];
//	if (onwork) {
//		pts[xIndex][yIndex][0] = x;
//		pts[xIndex][yIndex][1] = y;
//		draw();
//	}
//}
//
//void main(int argc, char * argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Bezier");
//	init();
//	glutDisplayFunc(display);
//	glutMouseFunc(click);
//	glutMotionFunc(motion);
//	glutMainLoop();
//}

