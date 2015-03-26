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
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1280, 720);
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
	gluLookAt(50, 200, 200,
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
	
}

void		OpenGlib::Destroy()
{
    glutDestroyWindow(screen);
}

bool		OpenGlib::DrawQuadra()
{

}

bool		OpenGlib::DrawHUD()
{

}

OpenGlib::~OpenGlib()
{

}