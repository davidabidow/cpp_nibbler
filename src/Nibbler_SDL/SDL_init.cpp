//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Wed Mar 25 14:25:02 2015 David Tran
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
