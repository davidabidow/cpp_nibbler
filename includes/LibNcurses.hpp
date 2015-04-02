//
// Ncurses.hpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:18:50 2015 Hugo Prenat
// Last update Thu Apr  2 22:29:15 2015 Jean-Baptiste Grégoire
//

#ifndef LIBNCURSES_HPP_
# define LIBNCURSES_HPP_

# include <curses.h>

# include "Map.hpp"

# define WALL_CHAR			'*'

class		LibNcurses : public ILibGraph
{
public:
  LibNcurses();
  ~LibNcurses();

public:
  bool		Init(int, int);
  bool		DrawMap(std::string const &, bool const);
  void		Destroy();
  bool		DrawQuadra(std::string const &);
  bool		DrawHUD();
  char		HandleEvent();

private:
  int		maxX;
  int		maxY;
};

#endif /* !LIBNCURSES_HPP_ */
