/*
** Snake.hpp for nibbler in /home/jibb/rendu/cpp_nibbler/includes
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:11:37 2015 Jean-Baptiste Grégoire
// Last update Tue Mar 24 17:09:56 2015 Jean-Baptiste Grégoire
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include <iostream>
# include <string>

enum direction
{
  NORTH, WEST, SOUTH, EAST
};

class Snake
{
public:
  Snake();
  bool turnLeft();
  bool turnRight();
  bool isAlive();
  ~Snake();

private:
  int direction;
  int nbPoints;
  std::vector<std::pair<int, int> snake;
};

#endif /* SNAKE_HPP_ */
