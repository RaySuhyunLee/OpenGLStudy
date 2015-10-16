make:
	gcc -framework GLUT -framework Cocoa -framework OpenGL test.c -o run1
	gcc -framework GLUT -framework Cocoa -framework OpenGL bezier.c -o run2

