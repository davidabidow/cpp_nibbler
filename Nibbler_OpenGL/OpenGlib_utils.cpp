//
// OpenGlib_utils.cpp for nibbler in /home/jibb/rendu/cpp_nibbler
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Tue Mar 31 01:52:17 2015 Jean-Baptiste Grégoire
// Last update Sat Apr  4 23:04:16 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

void		drawGround(int maxX, int maxY, bool const pau)
{
  glBegin(GL_QUADS);
  if (pau)
    glColor3ub(42, 42, 42);
  else
    glColor3ub(70, 125, 20);
  glVertex3d(-0.5, 0, -0.5);
  glVertex3d(-0.5, 0, maxY);
  glVertex3d(maxX, 0, maxY);
  glVertex3d(maxX, 0, -0.5);
  glEnd();
}

void		drawWall(int x, int y, bool const pau)
{
  if (pau)
    glColor3ub(200, 200, 200);
  else
    glColor3ub(0x66, 0x3E, 0x10);
  for (float i = 0; i <= x + 2.5; i += 0.5)
    {
      drawCube(i - 1.5, 0.5, -1.5, 1);
      drawCube(i - 1.5, 0.5, y + 1, 1);
    }
  for (float i = 0; i <= y + 2.5; i += 0.5)
    {
      drawCube(-1.5, 0.5, i - 1.5, 1);
      drawCube(x + 1, 0.5, i - 1.5, 1);
    }
}

void		drawCube(double x, double y, double z, double size)
{
  GLfloat	current_color[4];

  glGetFloatv(GL_CURRENT_COLOR, current_color);
  glBegin(GL_QUADS);
  // première face
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y + size, z + size);

  // seconde face
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y + size, z + size);

  // toisième face
  glVertex3d(x - size, y - size, z + size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y - size, z + size);

  // quatrième face
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y - size, z + size);

  // cinquième face
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y + size, z - size);

  // denière face
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y - size, z + size);
  glEnd();

  glColor3ub(0, 0, 0);
  glLineWidth(1.5);
  glBegin(GL_LINE_LOOP);
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y + size, z + size);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y + size, z + size);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(x - size, y - size, z + size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y - size, z + size);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y - size, z + size);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y + size, z - size);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y - size, z + size);
  glEnd();
  glLineWidth(1);
  glColor3f(current_color[0], current_color[1], current_color[2]);
}

void		drawSnake(std::string const &map, int length, int width,
			  bool const apple, bool const pau)
{
  int		i;

  for (int y = 0; y < length; ++y)
    {
      for (int x = 0; x < width; ++x)
	{
	  i = y * width + x;
	  if (map[i] == 1)
	    {
	      if (pau)
		glColor3ub(80, 80, 80);
	      else
		glColor3ub(51, 204, 51);
	      drawCube(x, 0.51, y, 0.5);
	    }
	  else if (map[i] == 2 && apple == true)
	    {
	      if (pau)
		glColor3ub(126, 126, 126);
	      else
		glColor3ub(251, 0,  0);
	      drawCube(x, 0.52, y, 0.5);
	    }
	}
    }
}
