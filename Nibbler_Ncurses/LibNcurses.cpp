//
// LibNcurses.cpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:24:29 2015 Hugo Prenat
// Last update Sat Apr  4 18:43:05 2015 Hugo Prenat
//

#include "LibNcurses.hpp"

void	init_screen(int x, int y)
{
  for (int i = 0; i <= x + 1; i++)
    {
      mvaddch(i, x + 1, WALL_CHAR);
      mvaddch(x + 1, i, WALL_CHAR);
    }
  for (int i = 0; i < y + 1; i++)
    {
      mvaddch(0, i, WALL_CHAR);
      mvaddch(i, 0, WALL_CHAR);
    }
  for (int i = 0; i <= 6; i++)
    {
      mvaddch(i, x + 10, ACS_DIAMOND);
      mvaddch(i, x + 30, ACS_DIAMOND);
      mvaddch(i + 8, x + 10, ACS_DIAMOND);
      mvaddch(i + 8, x + 30, ACS_DIAMOND);
    }
  for (int i = 0; i < 20; i++)
    {
      mvaddch(0, i + x + 10, ACS_DIAMOND);
      mvaddch(2, i + x + 10, ACS_DIAMOND);
      mvaddch(6, i + x + 10, ACS_DIAMOND);
      mvaddch(8, i + x + 10, ACS_DIAMOND);
      mvaddch(10, i + x + 10, ACS_DIAMOND);
      mvaddch(14, i + x + 10, ACS_DIAMOND);
    }
  mvprintw(1, x + 18, "Score");
  mvprintw(4, x + 12, "00000000000000000");
  mvprintw(9, x + 18, "Timer");
}

LibNcurses::LibNcurses()
{
}

void	LibNcurses::Init(int x, int y)
{
  int	sizeY, sizeX;

  maxY = y;
  maxX = x;
  initscr();
  getmaxyx(stdscr, sizeY, sizeX);
  if (y < 15)
    maxY = 14;
  if (sizeX < (maxX + 31) || sizeY < (maxY + 1))
    throw Nibbler_Error_Lib("Error: Please enter a size that is not"
			    " greater than the terminal size");
  maxY = y;
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  init_screen(x, y);
  refresh();
}

void	LibNcurses::DrawMap(std::string const &map, bool const apple,
			    bool const pau)
{
  if (!pau)
    {
      for (int i = 0; i < maxY * maxX; i++)
	{
	  move(i / maxY + 1, i % maxX + 1);
      if (map[i] == 1)
	addch(CORP_CHAR);
      else if (map[i] == 3)
	addch(HEAD_CHAR);
      else if (map[i] == 2 && apple == true)
	addch(APPL_CHAR);
      else
	addch(PLAN_CHAR);
	}
    }
  else
    {
      mvprintw(maxY / 2, (maxX / 2) - 4, "Game Paused");
    }
  refresh();
}

void	LibNcurses::Destroy()
{
  refresh();
  nodelay(stdscr, false);
  keypad(stdscr, false);
  endwin();
}

void	LibNcurses::DrawHUD(int const score, double const time)
{
  mvprintw(4, maxX + 12, "% 17d", score);
  mvprintw(12, maxX + 18, "% 5g", time);
}

char	LibNcurses::HandleEvent()
{
  int	tmp;
  char	button;

  tmp = getch();
  button = 0;
  if (tmp == 27)
    button = -1;
  else if (tmp == KEY_LEFT)
    button = 1;
  else if (tmp == KEY_RIGHT)
    button = 2;
  else if (tmp == KEY_PAUSE)
    button = 3;
  return (button);
}

LibNcurses::~LibNcurses()
{

}

extern "C"
{
  ILibGraph	*instanciate_lib()
  {
    return (new LibNcurses());
  }
}
