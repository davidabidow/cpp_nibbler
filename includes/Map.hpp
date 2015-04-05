//
// Map.hpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 14:27:26 2015 David Tran
// Last update Sun Apr  5 22:27:16 2015 Jean-Baptiste Grégoire
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <sstream>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <unistd.h>
# include <string.h>
# include <vector>
# include <dlfcn.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_gfxPrimitives.h>
# include "Snake.hpp"
# include "Score.hpp"
# include "Error.hpp"

class	ILibGraph;

class	Map
{
public:
  Map(int const x, int const y);
  ~Map();
  bool			genObj();
  bool			CheckinSnake(std::pair<double, double> const *t_check, std::vector<std::pair<double, double> *> const &snake) const;
  int			getMaxX() const;
  int			getMaxY() const;
  std::string const	&getMap() const;
  bool			getApple() const;
  void			fill_string();
  void			make_loop();
  Snake			*getSnake() const;
  void			setMaxX(int const a) {maxX = a;};
  void			setMaxY(int const a) {maxY = a;};
  void			loop_game(ILibGraph *);
  void			eat_apple();

private:
  std::string	map;
  bool		apple;
  int		p_apple;
  Snake		*snake;
  Score		score;
  int		maxX;
  int		maxY;
  bool		pau;
};

# include "ILibGraph.hpp"

#endif
