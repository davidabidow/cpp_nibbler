//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Fri Mar 27 02:00:57 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

OpenGlib::OpenGlib() : ALibGraph(0, 0), screen()
{

}

bool		OpenGlib::Init(int x, int y, int *argc, char **argv)
{
  maxX = x;
  maxY = y;
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1280, 720);
  if ((screen = glutCreateWindow("Nibbler -OpenGL-")) == 0)
    throw ;

  glutDisplayFunc(displayMap);
  glutIdleFunc(displayMap);
  glutKeyboardFunc(manageKeys);
  glutSpecialFunc(manageSpecialKeys);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOVY, static_cast<double>(x / y), NEAR, FAR);

  //glEnable(GLUT_DEPTH_TEST);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(50, 200, 200,
	    0, 0, 0,
	    0, 0, 1);
  return (true);
}

void		manageKeys(unsigned char key, UNUSED(int x), UNUSED(int y))
{
  switch(key)
    {
    case ESC_KEY: //leak memory baaaaah ...
      exit(0);
      break;
    default:
      break;
    }
}

void		manageSpecialKeys(int key, UNUSED(int x), UNUSED(int y))
{
  switch (key)
    {
    case GLUT_KEY_LEFT:
      turnLeft();
      break;
    case GLUT_KEY_RIGHT:
      turnRight();
      break;
    default:
      break;
    }
}

void    	displayMap(void)
{
  Map 	map = Map::getInstance();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_QUADS);
  glColor3ub(70, 125, 20);
  glVertex3d(-1 * (map.getMaxX() / 2), 0, -1 * (map.getMaxY() / 2));
  glVertex3d(map.getMaxX() / 2, 0, -1 * (map.getMaxY() / 2));
  glVertex3d(map.getMaxX() / 2, 0, map.getMaxY() / 2);
  glVertex3d(-1 * (map.getMaxX() / 2), 0, map.getMaxY() / 2);
  glEnd();
  glFlush();
}

bool		OpenGlib::DrawMap(__attribute__((unused))Map const &map)
{
  displayMap();
  return (true);
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
