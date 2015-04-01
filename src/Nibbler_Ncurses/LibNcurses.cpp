//
// LibNcurses.cpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:24:29 2015 Hugo Prenat
// Last update Wed Apr  1 16:57:46 2015 Hugo Prenat
//

#include "LibNcurses.hpp"

LibNcurses::LibNcurses()
{
}

bool	LibNcurses::Init(int x, int y)
{
  int	sizeY, sizeX;

  initscr();
  getmaxyx(stdscr, sizeY, sizeX);
  if (sizeX < (getMaxX() + 1) || sizeY < (getMaxY() + 1))
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
  for (int i = 0; i <= map.getMaxX() + 1; i++)
    {
      move(i, map.getMaxX() + 1);
      addch('x');
      move(map.getMaxX() + 1, i);
      addch('x');
    }
  for (int i = 0; i < map.getMaxY() + 1; i++)
    {
      move(0, i);
      addch('x');
      move(i, 0);
      addch('x');
    }
  for (int i = 0; i < getMaxY() * getMaxX(); i++)
    {
      move(i / getMaxY() + 1, i % getMaxX() + 1);
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
