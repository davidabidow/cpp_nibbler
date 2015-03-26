/*
** Snake.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:43:11 2015 Jean-Baptiste Grégoire
// Last update Fri Mar 27 00:05:32 2015 David Tran
*/

#include "Snake.cpp"

Snake::Snake(int maxX, int maxY) : direction(WEST), nbPoint(0)
{
  int		i;
  std::pair	coor;

  i = maxX / ;
  
}

bool	Snake::turnLeft()
{
  direction = (direction + 1) % 4;
}

bool	Snake::turnRight()
{
  direction = (direction - 1) % 4;
}

bool	Snake::moveAhead()
{
  
}

bool	Snake::isAlive()
{

}

Snake::~Snake()
{

}
