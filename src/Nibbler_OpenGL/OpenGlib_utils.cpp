
//
// OpenGlib_utils.cpp for nibbler in /home/jibb/rendu/cpp_nibbler
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Tue Mar 31 01:52:17 2015 Jean-Baptiste Grégoire
// Last update Wed Apr  1 22:45:41 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

void		drawGround(Map const &map)
{
  glBegin(GL_QUADS);
  glColor3ub(70, 125, 20);
  glVertex3d(-1.0 * (static_cast<double>(map.getMaxX()) / 2.0), -1.0 * (static_cast<double>(map.getMaxY()) / 2.0), 0);
  glVertex3d(static_cast<double>(map.getMaxX()) / 2.0, -1.0 * (static_cast<double>(map.getMaxY()) / 2.0), 0);
  glVertex3d(static_cast<double>(map.getMaxX()) / 2.0, static_cast<double>(map.getMaxY()) / 2.0, 0);
  glVertex3d(-1.0 * (static_cast<double>(map.getMaxX()) / 2.0), static_cast<double>(map.getMaxY()) / 2.0, 0);
  glEnd();
}

void		drawCube(int x, int y, int z, int size)
{
  glBegin(GL_QUADS);
  // première face
  glColor3ub(70, 125, 20);
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y + size, z + size);

  // seconde face
  glColor3ub(240, 125, 220);
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y + size, z + size);

  // toisième face
  glColor3ub(72, 2, 24);
  glVertex3d(x - size, y - size, z + size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x + size, y - size, z + size);

  // quatrième face
  glColor3ub(27, 200, 27);
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y + size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y - size, z + size);

  // cinquième face
  glColor3ub(20, 125, 240);
  glVertex3d(x + size, y + size, z - size);
  glVertex3d(x + size, y - size, z - size);
  glVertex3d(x - size, y - size, z - size);
  glVertex3d(x - size, y + size, z - size);

  // denière face
  glColor3ub(15, 25, 42);
  glVertex3d(x + size, y - size, z + size);
  glVertex3d(x + size, y + size, z + size);
  glVertex3d(x - size, y + size, z + size);
  glVertex3d(x - size, y - size, z + size);
  glEnd();
}

void		drawSnake(Map const &map)
{
  std::string	mapstr = map.getMap();
  int		length = map.getMaxX(), width = map.getMaxY();
  int		i;

  for (int y = 0; y < length; ++y)
    {
      for (int x = 0; x < width; ++x)
	{
	  i = y * width + x;
	  if (mapstr[i] == 1)
	    {
	      glColor3ub(51, 204, 51);
	      drawCube(x, y, 0, 1);
	    }
	  else if (mapstr[i] == 2 && map.getApple() == true)
	    {
	      glColor3ub(251, 0, 0);
	      drawCube(x, y, 0, 1);
	    }
	}
    }
}
