//
// Map.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 15:29:59 2015 David Tran
// Last update Fri Apr  3 22:56:03 2015 David Tran
//

#include "Map.hpp"

Map::Map(int const x, int const y) : maxX(x), maxY(y)
{
  std::string	newmap(x * y, 0);
  apple = false;
  snake = new Snake(x, y);
  map = newmap;
}

Map::~Map()
{}

bool	Map::CheckinSnake(std::pair<double, double> const *t_check, std::vector<std::pair<double, double> *> const snake)
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
  int				i;
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

bool	Map::getApple() const
{
  return (apple);
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
  if (apple == true)
    map[p_apple] = 2;
  while (it != snak.end())
    {
      // std::cout << "write toto" << std::endl;
      // std::cout << (*it)->second * maxY + (*it)->first << std::endl;
      // std::cout << (*it)->first  << ";" << (*it)->second << std::endl;
      map[(*it)->second * maxX + (*it)->first] = 1;
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
      if (p_apple == ((*it)->second * maxX + (*it)->first))
	{
	  score.setScore(score.getScore() + 1 + score.getCountit());
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
      lib->DrawHUD(score.getScore(), score.getTime());
      //     lib->DrawQuadra(*this);
      eat_apple();
      usleep(100000);
      score.setTime(score.getTime() + 0.1);
    }
}
