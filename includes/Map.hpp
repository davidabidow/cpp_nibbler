//
// Map.hpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 14:27:26 2015 David Tran
// Last update Tue Mar 31 22:30:13 2015 Jean-Baptiste Grégoire
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <sstream>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <unistd.h>
# include "Snake.hpp"

class	ALibGraph;

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
  void			make_loop();
  Snake			*getSnake() const;
  void			setMaxX(int a) {maxX = a;};
  void			setMaxY(int a) {maxY = a;};
  void			loop_game(ALibGraph *);
  void			eat_apple();

private:
  std::string	map;
  int		pts;
  bool		apple;
  int		p_apple;
  size_t	time;
  Snake		*snake;
  int		maxX;
  int		maxY;
};

# include "Nibbler_SDL.hpp"

#endif
