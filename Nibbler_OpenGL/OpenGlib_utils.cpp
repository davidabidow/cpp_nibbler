
//
// OpenGlib_utils.cpp for nibbler in /home/jibb/rendu/cpp_nibbler
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Tue Mar 31 01:52:17 2015 Jean-Baptiste Grégoire
// Last update Thu Apr  2 02:52:54 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

void		drawGround(Map const &map)
{
  glBegin(GL_QUADS);
  glColor3ub(70, 125, 20);
  glVertex3d(0, 0, 0);
  glVertex3d(0, 0, map.getMaxY());
  glVertex3d(map.getMaxX(), 0, map.getMaxY());
  glVertex3d(map.getMaxX(), 0, 0);
  glEnd();
}

void		drawCube(double x, double y, double z, double size)
{
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
	      drawCube(x, 1, y, 1);
	    }
	  else if (mapstr[i] == 2 && map.getApple() == true)
	    {
	      glColor3ub(251, 0, 0);
	      drawCube(x, 1, y, 1);
	    }
	}
    }
}
