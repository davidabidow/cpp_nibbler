/*
** Snake.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
**
** Made by Jean-Baptiste Grégoire
** Login   <gregoi_j@epitech.net>
**
** Started on  Tue Mar  24 16:43:11 2015 Jean-Baptiste Grégoire
// Last update Tue Mar 24 17:10:08 2015 Jean-Baptiste Grégoire
*/

#include "Snake.cpp"

Snake::Snake() : direction(NORTH), nbPoint(0)
{

}

bool	Snake::turnLeft()
{
  direction = (direction + 1) % 4
}

bool	Snake::turnRight()
{
  direction = (direction - 1) % 4
}

bool	Snake::isAlive()
{

}

Snake::~Snake()
{

}
