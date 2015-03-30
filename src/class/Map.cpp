//
// Map.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 15:29:59 2015 David Tran
// Last update Mon Mar 30 14:36:28 2015 Jean-Baptiste Grégoire
//

#include "Map.hpp"

Map::Map(int x, int y) : maxX(x), maxY(y)
{
  std::string	newmap(x * y, 0);
  apple = false;
  pts = 0;
  time = 0;
  snake = new Snake(x, y);
  map = newmap;
}

Map::~Map()
{}

bool	Map::CheckinSnake(std::pair<int, int> t_check, std::vector<std::pair<int, int> > snake)
{
  std::vector<std::pair<int, int> >::const_iterator it = snake.begin();

  while (it != snake.end())
    {
      if (*it.first == t_check.first && *it.second == t_check.second)
	return (false);
      it++;
    }
  return (true);
}

bool	Map::genObj()
{
  int						i;
  std::pair<int, int>				to_check;

  if (apple == false)
    return (false);
  std::srand(std::time(0));
  i = std::rand() % (maxX * maxY);
  to_check.first = i % maxX;
  to_check.second = i / maxY;
  while (CheckinSnake(to_check, snake->getVector()) == false)
    {
      i = std::rand() % (maxX * maxY);
      to_check.first = i % maxX;
      to_check.second = i / maxY;
    }
  map[i] = 2;
  return (true);
}

void	Map::setPts(int const objID)
{
  pts = objID;
}

int	Map::getMaxX() const
{
  return (maxX);
}

int	Map::getMaxY() const
{
  return (maxY);
}

std::string const	&Map::getMap() const
{
  return (map);
}

int	Map::getPts() const
{
  return (pts);
}

bool	Map::getApple() const
{
  return (apple);
}

void	Map::setTime(size_t const time)
{
  this->time = time;
}

size_t	Map::getTime() const
{
  return (time);
}

Snake	*getSnake() const
{
  return (snake);
}

void	Map::fill_string()
{
  std::vector<std::pair<int, int> >	snak = snake.getVector();
  std::vector<std::pair<int, int> >::iterator	it = snak.begin();

  while (it != snak.end())
    {
      map[*it.second * maxX + *it.first] = 1;
      it++;
    }
}
