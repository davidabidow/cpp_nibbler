//
// LibNcurses.cpp for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr  1 14:24:29 2015 Hugo Prenat
// Last update Wed Apr  1 16:25:44 2015 David Tran
//

#include "LibNcurses.hpp"

LibNcurses::LibNcurses()
{

}

bool		LibNcurses::Init(int x, int y)
{
  initscr();
  start_color();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  refresh();
  return (true);
}

bool		LibNcurses::DrawMap(Map const &map)
{
  for (int i = 0; i < map.getMaxX(); i++)
    {
      move(i, map.getMaxX() - 1);
      addch('x');
    }
  for (int i = 0; i < map.getMaxX(); i++)
    {
      move(map.getMaxX() - 1, i);
      addch('x');
    }
  for (int i = 0; i < map.getMaxY(); i++)
    {
      move(0, i);
      addch('x');
    }
  for (int i = 0; i < map.getMaxY() - 1; i++)
    {
      move(i, 0);
      addch('x');
    }
  for (int i = 0; i < map.getMaxY() * map.getMaxX(); i++)
    {
      if (map.getMap()[i] == 1)
	{
	  move(i / map.getMaxY(), i % map.getMaxX());
	  addch('o');
	}
      else if (map.getMap()[i] == 2 && map.getApple() == true)
	{
	  move(i / map.getMaxY(), i % map.getMaxX());
	  addch('P');
	}
    }
  refresh();
  return (true);
}

void		LibNcurses::Destroy()
{
  refresh();
  nodelay(stdscr, false);
  keypad(stdscr, false);
  getch();
  endwin();
}

bool		LibNcurses::DrawQuadra(Map const &map)
{
  return (true);
}

bool		LibNcurses::DrawHUD()
{
  return (true);
}

char		LibNcurses::HandleEvent()
{
  return (0);
}

LibNcurses::~LibNcurses()
{

}
