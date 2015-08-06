#include <GLUT/glut.h>      // (or others, depending on the system in use)

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void bitPattern (void){
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.


	glColor3i(0,0,0);
	GLubyte bitShape [20] = {
		0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00,
		0xff, 0x80, 0x7f, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x08, 0x00};

	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);  // Set pixel storage mode.

	glRasterPos2i (10, 10);
	glBitmap (9, 10, 0.0, 0.0, 20.0, 15.0, bitShape);


	glEnd ( );

	glFlush ( );     // Process all OpenGL routines as quickly as possible.
}

int main (int argc, char* argv[]){
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (400, 300);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (bitPattern);       // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.

	return 0;
}
