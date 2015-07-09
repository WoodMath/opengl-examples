#include <GLUT/glut.h>      // (or others, depending on the system in use)

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}


int xRaster = 0, yRaster = 0;
int dataValue[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//char* label[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char label[] = {'J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D'};

void barChart (void){
	GLint month, k;

	glClear (GL_COLOR_BUFFER_BIT); //  Clear display window.

	glColor3f (1.0, 0.0, 0.0);     //  Set bar color to red.
	for (k = 0; k < 12; k++)
		glRecti (20 + k*50, 165, 40 + k*50, dataValue [k]);

	glColor3f (0.0, 0.0, 0.0);           //  Set text color to black.
	xRaster = 20;                   //  Display chart labels.
	for (month = 0; month < 12; month++) {
		glRasterPos2i (xRaster, yRaster);
		for (k = 3*month; k < 3*month + 3; k++)
			glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12,(int) label [k]);
		xRaster += 50;
	}
	glFlush ( );

}

int main (int argc, char* argv[]){
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (400, 300);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (barChart);       // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.

	return 0;
}
