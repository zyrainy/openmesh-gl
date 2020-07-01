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
//const string file_1 = "Armadillo.off";//�ļ�λ��
//int currentfile = 1;
//vector<double>points;
//GLuint showFaceList;
//int showstate = 1;
//bool showFace = true;
//
////��ʼ���������   
//void initGL(GLenum mode = GL_RENDER)
//{
//	
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClearDepth(2.0);
//	glShadeModel(GL_FLAT);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glEnable(GL_DEPTH_TEST); //����������Ȼ������Ĺ��ܣ�������OPengl�Ϳ��Ը���Z���ϵ����أ���ô��ֻ����ǰ��û�ж���������²Ż����������أ��ڻ���3dʱ��������ã��Ӿ�Ч����Ƚ���ʵ
//	// ------------------- Lighting  
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	// ------------------- Display List  
//	showFaceList = glGenLists(1);
//	// ������
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
//// ������ı��С��ʱ��
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
//	else cout << "�ɹ���ȡ�ļ�: " << file << endl;
//	cout << "һ����ȡ�� " << mesh.n_faces() << " ����Ԫ." << endl;
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
////  ���̽������������ҵ��ƶ�
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
////����ʰȡ��Ϣ
//void ProcessPicks(GLint nPicks, GLuint pickBuffer[])
//{
//	int modelselect = 0; //���۾������������Ԫ��ID
//	int n = 0;  double minz = pickBuffer[1];
//	for (int i = 1; i < nPicks; i++)
//	{
//		if (pickBuffer[1 + i * 4] < minz) { n = i; minz = pickBuffer[1 + i * 4]; }
//	}
//	modelselect = pickBuffer[3 + n * 4];
//	cout << "ѡ�е�������ԪIDΪ:" << modelselect << endl;
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
//// ��꽻��
//void myMouse(int button, int state, int x, int y)
//{
//	GLuint selectBuffer[6000]; //����������Ƶ�ջ
//	GLint hits; //��ű�ѡ�ж������
//	GLint viewport[4]; //��ſ���������
//	GLint wwidth = glutGet(GLUT_WINDOW_WIDTH);//��ȡ��ǰ���ڿ��
//	GLint wheight = glutGet(GLUT_WINDOW_HEIGHT);
//	double point = *max_element(begin(points), end(points));
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		mousetate = 1;
//		Oldx = x;
//		Oldy = y;
//		glGetIntegerv(GL_VIEWPORT, viewport); //��ȡ��ǰ�ӿ��������
//		glSelectBuffer(6000, selectBuffer); //ѡ������ջ��ű�ѡ�е�����
//		glRenderMode(GL_SELECT); //���õ�ǰΪѡ��ģʽ
//		glInitNames(); //��ʼ������ջ
//		glPushName(0);
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//		glLoadIdentity();
//		gluPickMatrix(GLdouble(x), GLdouble(viewport[3] - y), 5.0, 5.0, viewport); //��������ѡ���ͶӰ����ջ
//		//��display�е�����ͶӰ����Ӧ����ͬ
//		/*if (wwidth > wheight)
//			glOrtho(-static_cast<GLdouble>(wwidth) / wheight, static_cast<GLdouble>(wwidth) / wheight, -1.0, 1.0, -100, 100);
//		else
//			glOrtho(-1.0, 1.0, -static_cast<GLdouble>(wheight) / wwidth, static_cast<GLdouble>(wheight) / wwidth, -100, 100);*/
//		glOrtho(-point* static_cast<GLdouble>(wwidth) / wheight, point*static_cast<GLdouble>(wwidth) / wheight, -point, point, -1000, 1000);
//		draw(GL_SELECT); //���Ƴ���,ѡ��ģʽ
//		//�ָ�ͶӰ�任
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
//	//�����¼�
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
//
//
//
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
//	glTranslatef(tx, ty, 0.0f);   //ƽ��
//	
//	// ����
//	glScalef(scale, scale, scale);
//	//ÿ��display��Ҫʹ��glcalllist�ص�������ʾ����ʾ�Ķ����б�
//	glCallList(showFaceList);
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
//
//	glutMouseFunc(myMouse);
//	glutMotionFunc(onMouseMove); // ����ƶ���ʱ��ĺ���
//	glutSpecialFunc(&mySpecial); //����
//	glutReshapeFunc(&myReshape); //���ڱ任
//	glutDisplayFunc(&myDisplay); //��ʾ
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
