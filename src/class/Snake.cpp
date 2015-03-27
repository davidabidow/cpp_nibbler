//
// Snake.cpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Fri Mar 27 00:10:35 2015 David Tran
// Last update Fri Mar 27 01:55:24 2015 David Tran
//

#include "Snake.hpp"
#include "ALibGraph.hpp"

Snake::Snake(int maxX, int maxY) : direction(WEST), nbPoint(0)
{
  int			x;
  int			y;
  int			i;
  std::pair<int, int>	coor;

  x = (WIN_WIDTH / maxX / 2);
  y = (WIN_HEIGHT / maxY / 2 - 2);
  i = 0;
  while (i < 4)
    {
      coor.first = WIN_WIDTH / maxX * (x + 1);
      coor.second = WIN_HEIGHT / maxY * (y + i);
      snake.push_back(coor);
      i++;
    }
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
  std::vector<std::pair<int, int> >::iterator	it = snake.begin();
  std::pair<int, int>				coor;
  std::pair<int, int>				last;

  last.first = *it.first;
  last.second = *it.second;
  i++;
  while (it != snake.end())
    {
      coor.first = *it.first;
      coor.second = *it.second;
      *it.first = last.first;
      *it.second = last.second;
      last.first = *it.first;
      last.second = *it.second;
      it++;
    }
  it = snake.begin();
  if (direction == NORTH)
    *it.second -= 1;
  else if (direction == WEST)
    *it.first -= 1;
  else if (direction == SOUTH)
    *it.second += 1;
  else
    *it.first += 1;
}

bool	Snake::isAlive()
{

}

Snake::~Snake()
{

}
