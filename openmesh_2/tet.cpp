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
////��꽻���йص�
//int mousetate = 0; //��굱ǰ��״̬
//GLfloat Oldx = 0.0; // ���֮ǰ��λ��
//GLfloat Oldy = 0.0;
////��ʵ�ֽǶȴ�С��صĲ�����ֻ��Ҫ�����Ϳ������
//float xRotate = 0.0f;
//float yRotate = 0.0f;
//float tx = 0.0f;
//float ty = 0.0f;
//float scale = 1;
//
////�ļ���ȡ�йص�
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
////��ʼ���������   
//void initGL()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClearDepth(2.0);
//	//glShadeModel(GL_SMOOTH);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glEnable(GL_DEPTH_TEST); //����������Ȼ������Ĺ��ܣ�������OPengl�Ϳ��Ը���Z���ϵ����أ���ô��ֻ����ǰ��û�ж���������²Ż����������أ��ڻ���3dʱ��������ã��Ӿ�Ч����Ƚ���ʵ
//							 // ------------------- Lighting  
//	glEnable(GL_LIGHTING); // ���enbale��ô��ʹ�õ�ǰ�Ĺ��ղ���ȥ�Ƶ��������ɫ
//	glEnable(GL_LIGHT0); //��һ����Դ����GL_LIGHT1��ʾ�ڶ�����Դ
//						 // ------------------- Display List  
//	showFaceList = glGenLists(1);
//	showWireList = glGenLists(1);
//	int temp = mesh.n_edges();
//
//	// ���� wire 
//	glNewList(showWireList, GL_COMPILE);
//	glDisable(GL_LIGHTING);
//	glLineWidth(1.0f);
//	glColor3f(0.5f, 0.5f, 0.5f);
//	glBegin(GL_LINES);
//	for (MyMesh::HalfedgeIter he_it = mesh.halfedges_begin(); he_it != mesh.halfedges_end(); ++he_it) {
//		//�����������ߵ������յ�
//		glVertex3fv(mesh.point(mesh.from_vertex_handle(*he_it)).data());
//		glVertex3fv(mesh.point(mesh.to_vertex_handle(*he_it)).data());
//	}
//	glEnd();
//	glEnable(GL_LIGHTING);
//	glEndList();
//
//	// ����flat
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
//// ������ı��С��ʱ��
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
//// ��ȡ�ļ��ĺ���
//void readfile(string file) {
//	// ���󶥵㷨�� vertex normals
//	mesh.request_vertex_normals();
//	//��������ڶ��㷨�ߣ��򱨴� 
//	if (!mesh.has_vertex_normals())
//	{
//		cout << "���󣺱�׼�������� �����ߡ�������" << endl;
//		return;
//	}
//	// ����ж��㷢�����ȡ�ļ� 
//	OpenMesh::IO::Options opt;
//	if (!OpenMesh::IO::read_mesh(mesh, file, opt))
//	{
//		cout << "�޷���ȡ�ļ�:" << file << endl;
//		return;
//	}
//	else cout << "�ɹ���ȡ�ļ�:" << file << endl;
//	cout << endl; // Ϊ��ui��ʾ�ÿ�һЩ
//				  //��������ڶ��㷨�ߣ�������
//	if (!opt.check(OpenMesh::IO::Options::VertexNormal))
//	{
//		// ͨ���淨�߼��㶥�㷨��
//		mesh.request_face_normals();
//		// mesh��������㷨��
//		mesh.update_normals();
//		// �ͷ��淨��
//		mesh.release_face_normals();
//	}
//}
//
////  ���̽��� 1. �л��ļ� 2.�л���ʾ
//void mySpecial(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_F1:
//		cout << "��ȡ�ļ�:" << file_1 << " ��......" << endl;
//		readfile(file_1);
//		scale = 1.0;
//		currentfile = 1;
//		initGL();
//		break;
//	case GLUT_KEY_F2:
//		cout << "��ȡ�ļ�:" << file_2 << " ��......" << endl;
//		readfile(file_2);
//		scale = 1.2;
//		currentfile = 2;
//		initGL();
//		break;
//	case GLUT_KEY_F3:
//		cout << "��ȡ�ļ�:" << file_3 << " ��......" << endl;
//		readfile(file_3);
//		scale = 0.01;
//		currentfile = 3;
//		initGL();
//		break;
//	case GLUT_KEY_F4:
//		if (showFace == true) {
//			showFace = false;
//			showWire = true;
//			cout << "�л���ʾģʽΪ��WireFrame" << endl;
//		}
//		else if (showWire == true)
//		{
//			showWire = false;
//			showFlatlines = true;
//			cout << "�л���ʾģʽΪ��Flatlines" << endl;
//		}
//		else if (showFlatlines == true) {
//			showFlatlines = false;
//			showFace = true;
//			cout << "�л���ʾģʽΪ��Flat" << endl;
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
////����ʰȡ��Ϣ
//void ProcessPicks(GLint nPicks, GLuint pickBuffer[])
//{
//	GLint i;
//	GLuint name, *ptr;
//	printf("ѡ�е���ĿΪ%d��\n", nPicks);
//
//	for (i = 0; i < nPicks; i++)
//	{
//		name = pickBuffer[3 + i * 4];
//		//select_point = name;//ÿ��ѡ��������ռ������ջ��4����λ����4������������ֵ
//		cout << "��" << name << "����" << endl;
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
//// ��꽻��
//void myMouse(int button, int state, int x, int y)
//{
//	//newcodes begin
//	//GLuint selectBuffer[6000]; //����������Ƶ�ջ
//	//GLint hits; //��ű�ѡ�ж������
//	//GLint viewport[4]; //��ſ���������
//
//	//newcodes end
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		//newcodes begin
//		//glGetIntegerv(GL_VIEWPORT, viewport); //��ȡ��ǰ�ӿ��������
//		//glSelectBuffer(6000, selectBuffer); //ѡ������ջ��ű�ѡ�е�����
//		//glRenderMode(GL_SELECT); //���õ�ǰΪѡ��ģʽ
//		//glInitNames(); //��ʼ������ջ
//		//glPushName(0);
//		//glMatrixMode(GL_PROJECTION);
//		//glPushMatrix();
//		//glLoadIdentity();
//		//gluPickMatrix(x, viewport[3] - y, 10, 10, viewport); //��������ѡ���ͶӰ����ջ
//		//gluOrtho2D(0, 800, 0, 500); //����ͶӰ��ʽ
//		//draw(GL_SELECT); //���Ƴ���,ѡ��ģʽ
//		////�ָ�ͶӰ�任
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
//	//�����¼�
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
//// ����˶�ʱ
//void onMouseMove(int x, int y) {
//	if (mousetate) {
//		//x��Ӧy����Ϊ��Ӧ���Ƿ�����
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
//	//Ҫ���֮ǰ����Ȼ���
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	//����ʾ��صĺ���
//	glRotatef(xRotate, 1.0f, 0.0f, 0.0f); // ��������ת�ĺ��� ��һ�������ǽǶȴ�С������Ĳ�������ת�ķ�����
//	glRotatef(yRotate, 0.0f, 1.0f, 0.0f);
//	//glTranslatef(0.0f, 0.0f, ty);
//	glTranslatef(tx, ty, 0.0f);
//	glScalef(scale, scale, scale); // ����
//	//cout << 1 << endl;
//	//							   //ÿ��display��Ҫʹ��glcalllist�ص�������ʾ����ʾ�Ķ����б�
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
//	glutSwapBuffers(); //����Opengl������ʵ��˫���漼����һ����Ҫ����
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // GLUT_Double ��ʾʹ��˫������ǵ�����
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(800, 500);
//	glutCreateWindow("Mesh Viewer");
//	//һ��ʼĬ�϶�ȡ�ļ�1
//	readfile(file_1);
//	initGL();
//	glutMouseFunc(myMouse);
//	glutMotionFunc(onMouseMove); // ����ƶ���ʱ��ĺ���
//	glutSpecialFunc(&mySpecial); //����
//	glutReshapeFunc(&myReshape);
//	glutDisplayFunc(&myDisplay);
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//// ��꽻��+ʰȡ������Ƭ
//void myMouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[SIZE]; //����������Ƶ�ջ
//	GLint hits; //��ű�ѡ�ж������
//	GLint viewport[4]; //��ſ���������
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		glGetIntegerv(GL_VIEWPORT, viewport); //��ȡ��ǰ�ӿ��������
//		glSelectBuffer(SIZE, selectBuffer); //ѡ������ջ��ű�ѡ�е�����
//		glRenderMode(GL_SELECT); //���õ�ǰΪѡ��ģʽ
//		glInitNames(); //��ʼ������ջ
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(x, viewport[3] - y, N, N, viewport); //��������ѡ���ͶӰ����ջ
//		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); //����ͶӰ��ʽ
//		draw(GL_SELECT); //���Ƴ���,ѡ��ģʽ
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
//	//�����¼�
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
//int SCREEN_WIDTH = 400; //��Ļ�ߴ�
//int SCREEN_HEIGHT = 400;
//
//int select_point = 0; //1 �ǵ�һ���㣬2�ǵڶ������Դ�����
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
//	for (int i = 1; i <= 5; i++)//5����
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
//	draw(GL_RENDER); //������Ⱦģʽ
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
//		select_point = name;//ÿ��ѡ��������ռ������ջ��4����λ����4������������ֵ
//		cout << "��" << name << "����" << endl;
//	}
//}
//
//#define SIZE 500
//
//#define N 10
//
//void mouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[SIZE]; //����������Ƶ�ջ
//	GLint hits; //��ű�ѡ�ж������
//	GLint viewport[4]; //��ſ���������
//	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) //������������ʱ
//	{
//		glGetIntegerv(GL_VIEWPORT, viewport); //��ȡ��ǰ�ӿ��������
//		glSelectBuffer(SIZE, selectBuffer); //ѡ������ջ��ű�ѡ�е�����
//		glRenderMode(GL_SELECT); //���õ�ǰΪѡ��ģʽ
//		glInitNames(); //��ʼ������ջ
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(x, viewport[3] - y, N, N, viewport); //��������ѡ���ͶӰ����ջ
//		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); //����ͶӰ��ʽ
//		draw(GL_SELECT); //���Ƴ���,ѡ��ģʽ
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
//	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) //��������̧��ʱ
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
//	glutCreateWindow("ͼ��ʰȡ���ʵ��");
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
//int xIndex, yIndex;//���ڲ鿴�������Ŀ��Ƶ�
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
////���������������Ƶ�֮��ľ���
//double distance(int x, int y, float x2, float y2)
//{
//	double dis = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
//	return dis;
//}
////����Ļ����ת��Ϊ��������
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

