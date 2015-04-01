//
// Ncurses.hpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:18:50 2015 Hugo Prenat
// Last update Wed Apr  1 16:59:30 2015 Hugo Prenat
//

#ifndef LIBNCURSES_HPP_
# define LIBNCURSES_HPP_

# include <curses.h>

# include "Map.hpp"

class		LibNcurses : public ILibGraph
{
public:
  LibNcurses();
  ~LibNcurses();

public:
  bool		Init(int, int);
  bool		DrawMap(Map const &);
  void		Destroy();
  bool		DrawQuadra(Map const &);
  bool		DrawHUD();
  char		HandleEvent();

private:
  int		maxX;
  int		maxY;
};

#endif /* !LIBNCURSES_HPP_ */
