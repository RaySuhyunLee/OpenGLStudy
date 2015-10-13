#include <GLUT/glut.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

void drawShape(){
	glColor3f(0.7f, 0.f, 0.8f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();
	glColor3f(1.0f, 0.8f, 1.0f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, -0.5f, 0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(0.0f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.0f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
}

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	//glTranslatef(0.0f, 0.0f, -2.0f)
	glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
	drawShape();
	glPopMatrix();

	glFinish();
}

void reshape(int w, int h)
{
	int temp;
	if (w < WINDOW_WIDTH || h < WINDOW_HEIGHT) {
		temp = (w > h) ? h : w;
		glViewport(0, h-temp, temp, temp);
	} else {
		glViewport(0, h-WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -0.5f, 50.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Hello World");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
