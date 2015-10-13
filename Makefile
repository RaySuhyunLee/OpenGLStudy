make:
	gcc -framework GLUT -framework Cocoa -framework OpenGL test.c
	./a.out
