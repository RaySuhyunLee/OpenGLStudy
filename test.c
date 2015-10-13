#include <GLUT/glut.h>

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glColor3f(0.3f, 0.7f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.0f, -0.3f);
	glEnd();
	glFinish();
}

void reshape(int w, int h)
{
	glViewport(0, h-500, 500, 500);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Hello World");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
