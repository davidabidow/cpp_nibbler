//
// Score.cpp for Score in /home/tran_0/rendu/cpp_nibbler/includes
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Fri Apr  3 21:14:37 2015 David Tran
// Last update Fri Apr  3 21:32:11 2015 David Tran
//

#include "Score.hpp"

Score::Score() : score(0), time(0), countit(0)
{}

Score::~Score()
{}

double		Score::getScore() const
{
  return (score);
}

double		Score::getTime() const
{
  return (time);
}

double		Score::getCountit() const
{
  return (countit);
}

void		Score::setScore(double const add)
{
  score = add;
  setCountit(countit + 1);
}

void		Score::setTime(double const add)
{
  time = add;
}

void		Score::setCountit(double const add)
{
  countit = add;
}
