//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Tue Mar 31 02:29:11 2015 Jean-Baptiste Grégoire
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
  gluPerspective(WIN_FOVY, static_cast<double>(maxX / maxY), NEAR, FAR);
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
  drawGround(map);
  drawSnake(map);
  glFlush();
  window.display();
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

char		OpenGlibL::HandleEvent()
{
  char		input;
  sf::Event	event;

  input = 0;
  while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	  input = -1;
      if (event.type ==  sf::Event::KeyReleased)
	{
	  if (event.key.code == sf::Keyboard::Escape)
	    input = -1;
	  else if (event.key.code == sf::Keyboard::Left)
	    input = 1;
	  else if (event.key.code == sf::Keyboard::Right)
	    input = 2;
	  else
	    input = 0;
	}
    }
  return (input);
}

OpenGlib::~OpenGlib()
{

}
