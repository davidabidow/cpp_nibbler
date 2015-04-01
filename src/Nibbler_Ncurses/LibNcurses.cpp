//
// LibNcurses.cpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:24:29 2015 Hugo Prenat
// Last update Wed Apr  1 17:01:20 2015 Hugo Prenat
//

#include "LibNcurses.hpp"

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
      std::cerr << "Error: Please enter a size that is not greater thant"
		<< " the term" << std::endl;
      return (false);
    }
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  refresh();
  return (true);
}

bool	LibNcurses::DrawMap(Map const &map)
{
  for (int i = 0; i <= maxX + 1; i++)
    {
      move(i, maxX + 1);
      addch('x');
      move(maxX + 1, i);
      addch('x');
    }
  for (int i = 0; i < maxY + 1; i++)
    {
      move(0, i);
      addch('x');
      move(i, 0);
      addch('x');
    }
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
