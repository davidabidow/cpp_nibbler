//
// LibNcurses.cpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:24:29 2015 Hugo Prenat
// Last update Thu Apr  2 17:41:11 2015 Hugo Prenat
//

#include "LibNcurses.hpp"

void	init_screen(int x, int y)
{
  for (int i = 0; i <= x + 1; i++)
    {
      move(i, x + 1);
      addch(WALL_CHAR);
      move(x + 1, i);
      addch(WALL_CHAR);
    }
  for (int i = 0; i < y + 1; i++)
    {
      move(0, i);
      addch(WALL_CHAR);
      move(i, 0);
      addch(WALL_CHAR);
    }
  for (int i = 0; i <= 6; i++)
    {
      move(i, x + 10);
      addch(ACS_DIAMOND);
      move(i, x + 30);
      addch(ACS_DIAMOND);
    }
  for (int i = 0; i < 20; i++)
    {
      move(0, i + x + 10);
      addch(ACS_DIAMOND);
      move(2, i + x + 10);
      addch(ACS_DIAMOND);
      move(6, i + x + 10);
      addch(ACS_DIAMOND);
    }
  move(1, x + 18);
  printw("Score");
}

LibNcurses::LibNcurses()
{
}

bool	LibNcurses::Init(int x, int y)
{
  int	sizeY, sizeX;

  maxY = y;
  maxX = x;
  initscr();
  getmaxyx(stdscr, sizeY, sizeX);
  if (sizeX < (x + 1) || sizeY < (y + 1))
    {
      endwin();
      std::cerr << "Error: Please enter a size that is not greater than"
		<< " the terminal size" << std::endl;
      return (false);
    }
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  init_screen(x, y);
  refresh();
  return (true);
}

bool	LibNcurses::DrawMap(Map const &map)
{
  for (int i = 0; i < maxY * maxX; i++)
    {
      move(i / maxY + 1, i % maxX + 1);
      if (map.getMap()[i] == 1)
	addch('o');
      else if (map.getMap()[i] == 2 && map.getApple() == true)
	addch('P');
      else
	addch(' ');
    }
  refresh();
  return (true);
}

void	LibNcurses::Destroy()
{
  refresh();
  nodelay(stdscr, false);
  keypad(stdscr, false);
  endwin();
}

bool	LibNcurses::DrawQuadra(Map const &map)
{
  return (true);
}

bool	LibNcurses::DrawHUD()
{
  return (true);
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
