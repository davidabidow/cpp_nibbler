//
// Map.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 15:29:59 2015 David Tran
// Last update Thu Apr  2 20:45:59 2015 David Tran
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

bool	Map::CheckinSnake(std::pair<double, double> *t_check, std::vector<std::pair<double, double> *> snake)
{
  std::vector<std::pair<double, double> *>::const_iterator it = snake.begin();

  while (it != snake.end())
    {
      if ((*it)->first == t_check->first && (*it)->second == t_check->second)
	return (false);
      it++;
    }
  return (true);
}

bool	Map::genObj()
{
  int			i;
  std::pair<double, double>	*to_check = new std::pair<double, double>;

  std::srand(std::time(0));
  i = std::rand() % (maxX * maxY);
  to_check->first = i % maxX;
  to_check->second = i / maxY;
  while (CheckinSnake(to_check, snake->getVector()) == false)
    {
      i = std::rand() % (maxX * maxY);
      to_check->first = i % maxX;
      to_check->second = i / maxY;
    }
  p_apple = i;
  apple = true;
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

Snake	*Map::getSnake() const
{
  return (snake);
}

void	Map::fill_string()
{
  std::vector<std::pair<double, double> *>	snak = snake->getVector();
  std::vector<std::pair<double, double> *>::iterator	it = snak.begin();

  std::string newone(maxX * maxY, 0);
  map = newone;
  map[p_apple] = 2;
  while (it != snak.end())
    {
      // std::cout << "write toto" << std::endl;
      // std::cout << (*it)->second * maxY + (*it)->first << std::endl;
      // std::cout << (*it)->first  << ";" << (*it)->second << std::endl;
      map[(*it)->second * maxY + (*it)->first] = 1;
      it++;
    }
  //  std::cout << "out" << std::endl;
}

void	Map::eat_apple()
{
  std::vector<std::pair<double, double> *>	snak = snake->getVector();
  std::vector<std::pair<double, double> *>::iterator	it = snak.begin();

  while (it != snak.end())
    {
      if (p_apple == ((*it)->second * maxY + (*it)->first))
	{
	  apple = false;
	  snake->addQueue();
	  return ;
	}
      it++;
    }
}

void	Map::loop_game(ILibGraph *lib)
{
  char	press;

  while (42)
    {
      fill_string();
      if (apple == false)
	genObj();
      if ((press = lib->HandleEvent()) == -1)
	{
	  lib->Destroy();
	  return ;
	}
      else if (press == 1)
	snake->turnLeft();
      else if (press == 2)
	snake->turnRight();
      if (snake->isAlive(maxX, maxY) == false)
	return ;
      snake->moveAhead();
      lib->DrawMap(map, apple);
      //     lib->DrawQuadra(*this);
      eat_apple();
      usleep(100000);
      time += 0.1;
    }
}
