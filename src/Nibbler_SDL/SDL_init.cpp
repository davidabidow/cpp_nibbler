//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Thu Mar 26 21:05:31 2015 David Tran
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

bool		N_SDL::DrawMap(MAP const &map)
{
  
}

bool		N_SDL::DrawQuadra(MAP const &map)
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
