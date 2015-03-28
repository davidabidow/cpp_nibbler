//
// Map.hpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 14:27:26 2015 David Tran
// Last update Sat Mar 28 19:16:53 2015 David Tran
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <cstdlib>
#include <iostream>
#include <ctime>
# include "Snake.hpp"

class	Map
{
public:
  Map(int x, int y);
  ~Map();
  bool			genObj();
  bool			CheckinSnake(std::pair<int, int> t_check, std::vector<std::pair<int, int> > snake);
  void			setPts(int const objID);
  int			getMaxX() const;
  int			getMaxY() const;
  std::string const	&getMap() const;
  int			getPts() const;
  bool			getApple() const;
  void			setTime(size_t);
  size_t		getTime() const;
  void			fill_string();
  Snake			*getSnake() const;

private:
  std::string	map;
  int		pts;
  bool		apple;
  size_t	time;
  Snake		*snake;
  int		maxX;
  int		maxY;
};

#endif
