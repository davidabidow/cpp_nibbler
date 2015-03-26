/*
** Snake.hpp for nibbler in /home/jibb/rendu/cpp_nibbler/includes
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:11:37 2015 Jean-Baptiste Grégoire
// Last update Thu Mar 26 23:58:49 2015 David Tran
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include <iostream>
# include <string>

typedef enum	direction
{
  NORTH, WEST, SOUTH, EAST
}		Way;

class Snake
{
public:
  Snake(int maxX, int maxY);
  bool	turnLeft();
  bool	turnRight();
  bool	moveAhead();
  bool	isDead();
  ~Snake();

private:
  Way					direction;
  size_t				nbPoints;
  std::vector< std::pair<int, int> >	snake;
};

#endif /* SNAKE_HPP_ */
