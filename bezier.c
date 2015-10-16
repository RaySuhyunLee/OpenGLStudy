#include <GLUT/glut.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define CONTROL_POINT_NUM 5

float cp_coord[CONTROL_POINT_NUM][2];

int button_click = 0;
int selected_cp = -1;

int screen_width;
int screen_height;

void draw() 
{
	float t;

	float div_coord[CONTROL_POINT_NUM][2];
	float x, y, x1, y1, x2, y2;
	int i, j;

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

void mouseClick(int button, int state, int x, int y)
{
	int i;
	const int threshold = 10;
	int cp_x, cp_y, diff_x, diff_y;
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			for (i=0; i<CONTROL_POINT_NUM; i++) {
				cp_x = (int)((1.0+cp_coord[i][0]) / 2 * screen_width);
				cp_y = (int)((1.0-cp_coord[i][1]) / 2 * screen_height);
				diff_x = x-cp_x;
				diff_y = y-cp_y;
				if (-threshold < diff_x && diff_x < threshold &&
						(-threshold < diff_y && diff_y < threshold)) {
					button_click = 1;
					selected_cp = i;
					break;
				}
			}
		} else if (state == GLUT_UP) {
			button_click = 0;
		}
	}
}

void mouseMove(int x, int y) {
	if (button_click) {
		cp_coord[selected_cp][0] = -1.0 + ((float)x / screen_width * 2);
		cp_coord[selected_cp][1] = 1.0 - ((float)y / screen_height * 2);
		glutPostRedisplay();
	}
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
	screen_width = w;
	screen_height = h;
}

int main(int argc, char** argv)
{
	cp_coord[0][0] = -1.0f;
	cp_coord[0][1] = 0.0f;
	cp_coord[1][0] = -0.3f;
	cp_coord[1][1] = 0.5f;
	cp_coord[2][0] = 0.6f;
	cp_coord[2][1] = -0.5f;
	cp_coord[3][0] = 0.8f;
	cp_coord[3][1] = 0.2f;
	cp_coord[4][0] = 1.0f;
	cp_coord[4][1] = 0.0f;

	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Spline");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
	glutMainLoop();
	return 0;
}
