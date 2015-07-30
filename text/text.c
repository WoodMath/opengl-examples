#include <GLUT/glut.h>      // (or others, depending on the system in use)
#include <string.h>

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

char* label = "Hello, World!\0";

void text (void){

	glClear (GL_COLOR_BUFFER_BIT); //  Clear display window.

	glColor3f (0.0, 0.0, 0.0);           //  Set text color to black.
	
	glRasterPos2i (2, 2);
	
	int iSize = strlen(label);
	int iInc = 0;

	for (iInc = 0; iInc < iSize; iInc++)
			glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12,(int) label [iInc]);

	glFlush ( );

}

int main (int argc, char* argv[]){
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (400, 300);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (text);       // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.

	return 0;
}
