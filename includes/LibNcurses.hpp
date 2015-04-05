//
// Ncurses.hpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:18:50 2015 Hugo Prenat
// Last update Sun Apr  5 22:03:03 2015 David Tran
//

#ifndef LIBNCURSES_HPP_
# define LIBNCURSES_HPP_

# include <curses.h>

# include "Error.hpp"
# include "Map.hpp"

# define WALL_CHAR			'*'
# define PLAN_CHAR			' '
# define HEAD_CHAR			'0'
# define CORP_CHAR			'o'
# define APPL_CHAR			'P'

# define KEY_PAUSE			'p'
# define KEY_ESC			27

class		LibNcurses : public ILibGraph
{
public:
  LibNcurses();
  ~LibNcurses();

public:
  void		Init(int, int);
  void		DrawMap(std::string const &, bool const, bool const);
  void		Destroy();
  void		DrawHUD(int, double);
  char		HandleEvent();

private:
  int		maxX;
  int		maxY;
};

#endif /* !LIBNCURSES_HPP_ */
