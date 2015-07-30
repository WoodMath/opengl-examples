#include <GLUT/glut.h>      // (or others, depending on the system in use)

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void rect (void){

	glClear (GL_COLOR_BUFFER_BIT); //  Clear display window.

	int iInc = 0;

	glColor3f (1.0, 0.0, 0.0);     //  Set bar color to red.
	for (iInc = 0; iInc < 10; iInc++)
		glRecti (5 + iInc*15, 10, 15 + iInc*15, 15+iInc*10);

	glFlush ( );

}

int main (int argc, char* argv[]){
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (512, 512);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (rect);		     // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.

	return 0;
}
