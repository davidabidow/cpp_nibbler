//
// nibbler.hpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon Mar  9 14:50:21 2015 David Tran
// Last update Tue Mar 24 11:55:13 2015 David Tran
//

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

# include <iostream>
# include <stdlib.h>
# include <sstream>

class		Controler
{
public:
  Controler(void);
  ~Controler(void);
  void		setMax(int);
  void		setMay(int);
  int		getMax(void);
  int		getMay(void);
private:
  int		max;
  int		may;
};

#endif
