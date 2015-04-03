//
// Ncurses.hpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:18:50 2015 Hugo Prenat
// Last update Fri Apr  3 23:51:08 2015 Hugo Prenat
//

#ifndef LIBNCURSES_HPP_
# define LIBNCURSES_HPP_

# include <curses.h>

# include "Map.hpp"

# define WALL_CHAR			'*'
# define PLAN_CHAR			' '
# define HEAD_CHAR			'0'
# define CORP_CHAR			'o'
# define APPL_CHAR			'P'

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
  bool		DrawHUD(int, double);
  char		HandleEvent();

private:
  int		maxX;
  int		maxY;
};

#endif /* !LIBNCURSES_HPP_ */
