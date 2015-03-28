/*
** Snake.hpp for nibbler in /home/jibb/rendu/cpp_nibbler/includes
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:11:37 2015 Jean-Baptiste Grégoire
// Last update Sat Mar 28 18:49:43 2015 David Tran
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include <iostream>
# include <string>
# include <vector>
# include <utility>
# include "Map.hpp"

typedef enum	direction
{
  NORTH, WEST, SOUTH, EAST
}		Way;

class Snake
{
public:
  Snake(int maxX, int maxY);
  bool							turnLeft();
  bool							turnRight();
  bool							moveAhead();
  bool							isAlive(int maxX, int maxY);
  std::vector<std::pair<int, int> >			getVector() {return (snake);}
  ~Snake();

private:
  Way					direction;
  size_t				nbPoints;
  std::vector<std::pair<int, int> >	snake;
};

#endif /* SNAKE_HPP_ */
