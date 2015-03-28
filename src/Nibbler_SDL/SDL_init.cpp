//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Sat Mar 28 20:06:38 2015 David Tran
//

#include "Nibbler_SDL.hpp"

N_SDL::N_SDL(int x, int y) : ALibGraph(x, y)
{}

N_SDL::~N_SDL()
{}

bool		N_SDL::Init()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (false);
  if (!(screen = SDL_SetVideoMode(x, y, 32, SDL_HWSURFACE)))
    {
      SDL_Quit();
      return (false);
    }
  SDL_WM_SetCaption("cpp_Nibbler", NULL);
  return (true);
}

void		N_SDL::Destroy()
{
  SDL_Quit();
}

void		N_SDL::init_pos(int x, int y)
{
  pos.x = WIN_LEN / maxX * x;
  pos.y = WIN_LEN / maxY * y;
  pos.w = WIN_LEN / maxX;
  pos.h = WIN_LEN / maxY;
}

void		N_SDL::fill_point_rect(int x, int y, std::string::const_iterator it)
{
  if (*it == 1)
      SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 51, 204, 51));
  else if (*it == 2)
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 251, 0, 0));
}

bool		N_SDL::DrawMap(MAP const &map) const
{
  std::string::const_iterator	pars = map.getMap().begin();
  int		x;
  int		y;

  y = 0;
  while (y < maxY)
    {
      x = 0;
      while (x < maxX)
	{
	  init_pos(x, y);
	  fill_point_rect(x, y, pars);
	  x++;
	  it++;
	}
      y++;
    }
}

bool		N_SDL::DrawQuadra(MAP const &map) const
{
  int		i;

  i = 0;
  while (i < map.getMaxX())
    {
      vlineColor(screen, map.getMaxX() / MAX_WIN * i, 0, MAX_WIN, 0x696969);
      i++;
    }
  i = 0;
  while (i < map.getMaxY())
    {
      hlineColor(screen, 0, MAX_WIN, MAX_WIN / map.getMaxY() * i, 0x696969);
      i++;
    }
  pos.x = 0;
  pos.y = 0;
  SDL_Flip(screen);
}

bool		N_SDL::DrawHUD()
{

}

char		N_SDL::HandleEvent()
{

}
