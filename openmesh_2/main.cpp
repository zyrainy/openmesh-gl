//#include <iostream>  
//#include <OpenMesh/Core/IO/MeshIO.hh>  
//#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>  
//#include "GL\glut.h"
//#include <math.h>
//#include <Windows.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;
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
//const string file_1 = "Armadillo.off";//文件位置
//int currentfile = 1;
//vector<double>points;
//GLuint showFaceList;
//int showstate = 1;
//bool showFace = true;
//
////初始化顶点和面   
//void initGL(GLenum mode = GL_RENDER)
//{
//	
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClearDepth(2.0);
//	glShadeModel(GL_FLAT);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glEnable(GL_DEPTH_TEST); //用来开启深度缓冲区的功能，启动后OPengl就可以跟踪Z轴上的像素，那么它只有在前面没有东西的情况下才会绘制这个像素，在绘制3d时，最好启用，视觉效果会比较真实
//	// ------------------- Lighting  
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	// ------------------- Display List  
//	showFaceList = glGenLists(1);
//	// 绘制面
//	glNewList(showFaceList, GL_COMPILE);
//	for (MyMesh::FaceIter f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it) {
//		glBegin(GL_TRIANGLES);
//		for (MyMesh::FaceVertexIter fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
//			glNormal3fv(mesh.normal(*fv_it).data());
//			glVertex3fv(mesh.point(*fv_it).data());
//			for (int j = 0; j < 3; j++) {
//				points.push_back(mesh.point(*fv_it).data()[j]);
//			}
//		}
//		glEnd();
//	}
//	glEndList();
//
//}
//
//// 当窗体改变大小的时候
//void myReshape(GLint w, GLint h)
//{
//	glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	double point = *max_element(begin(points), end(points));
//	double time = point / w;
//	/*if (w > h)
//		glOrtho(-static_cast<GLdouble>(w) / h, static_cast<GLdouble>(w) / h, -1.0, 1.0, -1000, 1000.0);
//	else
//		glOrtho(-1.0, 1.0, -static_cast<GLdouble>(h) / w, static_cast<GLdouble>(h) / w, -1000, 1000.0);*/
//
//	glOrtho(-point* static_cast<GLdouble>(w) / h, point*static_cast<GLdouble>(w) / h, -point, point, -1000, 1000);
//
//	
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
//	else cout << "成功读取文件: " << file << endl;
//	cout << "一共读取了 " << mesh.n_faces() << " 个面元." << endl;
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
////  键盘交互，上下左右的移动
//void mySpecial(int key, int x, int y) {
//	switch (key) {
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
//	int modelselect = 0; //离眼睛最近的三角面元的ID
//	int n = 0;  double minz = pickBuffer[1];
//	for (int i = 1; i < nPicks; i++)
//	{
//		if (pickBuffer[1 + i * 4] < minz) { n = i; minz = pickBuffer[1 + i * 4]; }
//	}
//	modelselect = pickBuffer[3 + n * 4];
//	cout << "选中的三角面元ID为:" << modelselect << endl;
//	printf("\n\n");
//}
//
//void draw(GLenum mode) {
//
//	int i = 0;
//	for (MyMesh::FaceIter f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it) {
//		i++;
//		if (mode == GL_SELECT) {
//			glLoadName(i);
//			//cout << i << endl;
//		}
//		glBegin(GL_TRIANGLES);
//		for (MyMesh::FaceVertexIter fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
//			glNormal3fv(mesh.normal(*fv_it).data());
//			glVertex3fv(mesh.point(*fv_it).data());
//		}
//		glEnd();
//	}
//
//}
//
//// 鼠标交互
//void myMouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[6000]; //存放物体名称的栈
//	GLint hits; //存放被选中对象个数
//	GLint viewport[4]; //存放可视区参数
//	GLint wwidth = glutGet(GLUT_WINDOW_WIDTH);//获取当前窗口宽度
//	GLint wheight = glutGet(GLUT_WINDOW_HEIGHT);
//	double point = *max_element(begin(points), end(points));
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		glGetIntegerv(GL_VIEWPORT, viewport); //获取当前视口坐标参数
//		glSelectBuffer(6000, selectBuffer); //选择名称栈存放被选中的名称
//		glRenderMode(GL_SELECT); //设置当前为选择模式
//		glInitNames(); //初始化名称栈
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(GLdouble(x), GLdouble(viewport[3] - y), 5.0, 5.0, viewport); //创建用于选择的投影矩阵栈
//		//与display中的正交投影矩阵应该相同
//		/*if (wwidth > wheight)
//			glOrtho(-static_cast<GLdouble>(wwidth) / wheight, static_cast<GLdouble>(wwidth) / wheight, -1.0, 1.0, -100, 100);
//		else
//			glOrtho(-1.0, 1.0, -static_cast<GLdouble>(wheight) / wwidth, static_cast<GLdouble>(wheight) / wwidth, -100, 100);*/
//		glOrtho(-point* static_cast<GLdouble>(wwidth) / wheight, point*static_cast<GLdouble>(wwidth) / wheight, -point, point, -1000, 1000);
//		draw(GL_SELECT); //绘制场景,选择模式
//		//恢复投影变换
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//		glFlush();
//		hits = glRenderMode(GL_RENDER);
//		glMatrixMode(GL_MODELVIEW);
//
//		if (hits > 0)
//			ProcessPicks(hits, selectBuffer);
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//		mousetate = 0;
//	//滚轮事件
//	if (state == GLUT_UP && button == 3) {
//			scale -= 0.1;
//	}
//	if (state == GLUT_UP && button == 4) {
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
//
//
//
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
//	glTranslatef(tx, ty, 0.0f);   //平移
//	
//	// 缩放
//	glScalef(scale, scale, scale);
//	//每次display都要使用glcalllist回调函数显示想显示的顶点列表
//	glCallList(showFaceList);
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
//
//	glutMouseFunc(myMouse);
//	glutMotionFunc(onMouseMove); // 鼠标移动的时候的函数
//	glutSpecialFunc(&mySpecial); //键盘
//	glutReshapeFunc(&myReshape); //窗口变换
//	glutDisplayFunc(&myDisplay); //显示
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
