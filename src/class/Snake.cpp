//
// Snake.cpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Fri Mar 27 00:10:35 2015 David Tran
// Last update Mon Mar 30 19:11:37 2015 David Tran
//

#include "Snake.hpp"

Snake::Snake(int maxX, int maxY) : direction(WEST), nbPoints(0)
{
  int			x;
  int			y;
  int			i;
  std::pair<int, int>	coor;

  //  x = (WIN_WIDTH / maxX) * (maxX / 2 - 2);
  //  y = (WIN_HEIGHT / maxY) * (maxY / 2);
  i = 0;
  while (i < 4)
    {
      //      coor.first = x + (WIN_WIDTH / maxX * i);
      //      coor.second = y;
      coor.first = maxX / 2 - 2 + i;
      coor.second = maxY / 2;
      snake.push_back(coor);
      i++;
    }
}

void	Snake::turnLeft()
{
  direction = (Way)((direction + 1) % 4);
}

void	Snake::turnRight()
{
  direction = (Way)((direction - 1) % 4);
}

void	Snake::moveAhead()
{
  std::vector<std::pair<int, int> >::iterator	it = snake.begin();
  std::pair<int, int>				coor;
  std::pair<int, int>				last;

  last.first = (*it).first;
  last.second = (*it).second;
  it++;
  while (it != snake.end())
    {
      coor.first = (*it).first;
      coor.second = (*it).second;
      (*it).first = last.first;
      (*it).second = last.second;
      last.first = (*it).first;
      last.second = (*it).second;
      it++;
    }
  it = snake.begin();
  if (direction == NORTH)
    (*it).second -= 1;
  else if (direction == WEST)
    (*it).first -= 1;
  else if (direction == SOUTH)
    (*it).second += 1;
  else
    (*it).first += 1;
}

bool	Snake::isAlive(int maxX, int maxY)
{
  std::vector<std::pair<int, int> >::iterator	it = snake.begin();
  std::pair<int, int>				first;

  if ((*it).first < 0 || (*it).first > maxX || (*it).second < 0 || (*it).second > maxY)
    return (false);
  first = *it;
  it++;
  while (it < snake.end())
    {
      if (first.first == (*it).first && first.second == (*it).second)
	return (false);
      it++;
    }
 return (true);
}

Snake::~Snake()
{}
