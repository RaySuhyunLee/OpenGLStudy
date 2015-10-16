#include <GLUT/glut.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define CONTROL_POINT_NUM 4

void draw() 
{
	float t;
	float cp_coord[CONTROL_POINT_NUM][2];
	float div_coord[CONTROL_POINT_NUM][2];
	float x, y, x1, y1, x2, y2;
	int i, j;
	cp_coord[0][0] = -1.0f;
	cp_coord[0][1] = 0.0f;
	cp_coord[1][0] = -0.3f;
	cp_coord[1][1] = 0.5f;
	cp_coord[2][0] = 0.7f;
	cp_coord[2][1] = -0.5f;
	cp_coord[3][0] = 1.0f;
	cp_coord[3][1] = 0.0f;

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_STRIP);
	for(t=0.0; t<=1.0; t+=0.01) {
		for(i=0; i<CONTROL_POINT_NUM-1; i++) {
			div_coord[i][0] = (cp_coord[i+1][0]-cp_coord[i][0])*t + cp_coord[i][0];
			div_coord[i][1] = (cp_coord[i+1][1]-cp_coord[i][1])*t + cp_coord[i][1];
		}
		for(i=CONTROL_POINT_NUM-2; i>0; i--) {
			for(j=0; j<i; j++) {
				div_coord[j][0] = (div_coord[j+1][0]-div_coord[j][0])*t + div_coord[j][0];
				div_coord[j][1] = (div_coord[j+1][1]-div_coord[j][1])*t + div_coord[j][1];
			}
		}
		glVertex2f(div_coord[0][0], div_coord[0][1]);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	for(i=0; i<CONTROL_POINT_NUM; i++) {
		glVertex2fv(cp_coord[i]);
	}
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	for(i=0; i<CONTROL_POINT_NUM; i++) {
		glVertex2fv(cp_coord[i]);
	}
	glEnd();

}

void display() 
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	draw();

	glFinish();
}

void reshape(int w, int h) 
{
	int smaller = w > h ? h : w;
	glViewport(0, h-smaller, smaller, smaller);	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Spline");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
