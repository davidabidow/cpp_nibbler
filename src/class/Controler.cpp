//
// Controler.cpp for Controler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 11:47:47 2015 David Tran
// Last update Tue Mar 24 11:53:00 2015 David Tran
//

#include "nibbler.hpp"

Controler::Controler()
{}

Controler::~Controler()
{}

void		Controller::setMax(int value)
{
  max = value;
}

void		Controller::setMay(int value)
{
  may = value;
}

int		Controller::getMax(void)
{
  return (max);
}

int		Controller::getMay(void)
{
  return (may);
}
