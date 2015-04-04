/*
** Snake.hpp for nibbler in /home/jibb/rendu/cpp_nibbler/includes
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:11:37 2015 Jean-Baptiste Grégoire
// Last update Sat Apr  4 15:13:59 2015 David Tran
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include <iostream>
# include <string>
# include <vector>
# include <utility>
# include "Error.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

typedef enum	direction
{
  NORTH, WEST, SOUTH, EAST
}		Way;

class Snake
{
public:
  Snake(int maxX, int maxY);
  void							turnLeft();
  void							turnRight();
  void							moveAhead();
  void							isAlive(int maxX, int maxY);
  std::vector<std::pair<double, double> *>		getVector() {return (snake);}
  Way							getDirection() const;
  void							addQueue();
  ~Snake();

private:
  Way					direction;
  size_t				nbPoints;
  std::vector<std::pair<double, double> *>	snake;
};

#endif /* SNAKE_HPP_ */
