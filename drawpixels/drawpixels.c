#include <GLUT/glut.h>      // (or others, depending on the system in use)
#include <stdlib.h>

int iWidth = 512;
int iHeight = 512;
int iSize;
GLubyte *cPixels;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);

	unsigned int iInc;
	GLubyte cTemp;
	

	for(iInc = 0; iInc < iSize; iInc++){

		cTemp = (GLubyte)((iHeight - (iInc % iHeight)) >> 1);
		cPixels[iInc*3+0] = cTemp;
		cTemp = (GLubyte)((iInc % iHeight) >> 1);
		cPixels[iInc*3+2] = cTemp;

	}

}

void drawPixels (void){
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.


	glColor3i(0,0,0);

	glDrawPixels(iWidth, iHeight, GL_RGB, GL_UNSIGNED_BYTE, cPixels);


	glFlush ( );     // Process all OpenGL routines as quickly as possible.
}

int main (int argc, char* argv[]){

	iSize = iWidth * iHeight;
	cPixels = malloc(3*sizeof(GLubyte)*iSize);

	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (iWidth, iHeight);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (drawPixels);       // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.

	free(cPixels);

	return 0;
}
