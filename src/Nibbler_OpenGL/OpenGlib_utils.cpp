//
// OpenGlib_utils.cpp for nibbler in /home/jibb/rendu/cpp_nibbler
// 
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
// 
// Started on  Tue Mar 31 01:52:17 2015 Jean-Baptiste Grégoire
// Last update Tue Mar 31 02:27:57 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

void		drawGround(Map const &map) const
{
  glBegin(GL_QUADS);
  glColor3ub(70, 125, 20);
  glVertex3d(-1 * (map.getMaxX() / 2), 0, -1 * (map.getMaxY() / 2));
  glVertex3d(map.getMaxX() / 2, 0, -1 * (map.getMaxY() / 2));
  glVertex3d(map.getMaxX() / 2, 0, map.getMaxY() / 2);
  glVertex3d(-1 * (map.getMaxX() / 2), 0, map.getMaxY() / 2);
  glEnd();
}

void		drawCube(int x, int y, int z, size_t size)
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
	      drawCube(x, y, size, WIN_WIDTH / x);
	    }
	  else if (mapstr[i] == 2 && map.getApple() == true)
	    {
	      glColor3ub(251, 0, 0);
	      drawCube(x, y, size, WIN_WIDTH / x);
	    }
	}
    }
}
