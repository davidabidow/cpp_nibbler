//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Mon Mar 30 22:09:04 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

OpenGlib::OpenGlib(int x, int y) : ALibGraph(x, y)
{

}

bool		OpenGlib::Init()
{
  window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Nibbler -OpenGL-");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOVY, static_cast<double>(x / y), NEAR, FAR);
  glEnable(GLUT_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(50, 200, 200,
	    0, 0, 0,
	    0, 0, 1);
  return (true);
}

bool		OpenGlib::DrawMap(Map const &map)
{
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
  return (true);
}

void		OpenGlib::Destroy()
{
  window.close();
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
