//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.cpp"

OpenGlib::OpenGlib() : maxX(1280), maxY(720), screen()
{
	
}

bool		OpenGlib::Init(int x, int y, int argc, char **argv) : minX(x), minY(y)
{
	char	*argv[1] = {static_cast<char *>"nibbler"}
	int 	argc = 1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	if ((screen = glutCreateWindow("Nibbler -OpenGL-")) == 0)
		throw ;
	glutDisplayFunc(DrawMap);
	glutIdleFunc(DrawMap);
 	glutKeyboardFunc(ManageKeys);
	glutSpecialFunc(ManageKeys);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOVY, static_cast<double>(x / y), NEAR, FAR);

	//glEnable(GLUT_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 50, y / 2 + 10,
	0, 0, 0,
	0, 0, 1);
}

void		OpenGlib::ManageKeys(unsigned char key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
			turnLeft();
			break;
		case GLUT_KEY_RIGHT:
			throwurnRight();
			break;
		case ESC_KEY:
			Destroy();
			exit(0);
			break;
	}
}

bool		OpenGlib::DrawMap()
{
	glClear(GL_COLORBUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3ub(75, 170, 20); // vert

	glVertex3d(-1 * (m.getMaxX() / 2), 0, -1 * (m.getMaxY() / 2));
	glVertex3d(m.getMaxX() / 2, 0, -1 * (m.getMaxY() / 2));
	glVertex3d(m.getMaxX() / 2, 0, m.getMaxY() / 2);				// draw the floor of the map
	glVertex3d(-1 * (m.getMaxX() / 2), 0, m.getMaxY() / 2);

	glEnd();
}

char		OpenGlib::HandleEvent()
{
	glutMainLoopEvent();
}

void		OpenGlib::Destroy()
{
    glutDestroyWindow(screen);
}

bool		OpenGlib::DrawQuadra()
{
	return (true);
}

bool		OpenGlib::DrawHUD()
{
	return (true);
}

OpenGlib::~OpenGlib()
{

}