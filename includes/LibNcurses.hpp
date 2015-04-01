//
// Ncurses.hpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:18:50 2015 Hugo Prenat
// Last update Wed Apr  1 16:37:49 2015 Hugo Prenat
//

#ifndef LIBNCURSES_HPP_
# define LIBNCURSES_HPP_

# include <curses.h>

# include "Map.hpp"

class		LibNcurses : public ALibGraph
{
public:
  LibNcurses(int, int);
  ~LibNcurses();

public:
  bool		Init();
  bool		DrawMap(Map const &);
  void		Destroy();
  bool		DrawQuadra(Map const &);
  bool		DrawHUD();
  char		HandleEvent();
};

#endif /* !LIBNCURSES_HPP_ */
