//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Mon Mar 30 23:05:17 2015 David Tran
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
  if (!(screen = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_HWSURFACE)))
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
  SDL_Rect	tmp;

  tmp.x = WIN_WIDTH / getMaxX() * x;
  tmp.y = WIN_HEIGHT / getMaxY() * y;
  tmp.w = WIN_WIDTH / getMaxX();
  tmp.h = WIN_HEIGHT / getMaxY();
  pos = tmp;
}

void		N_SDL::fill_point_rect(std::string it, int i, Map const &map)
{
  if (it[i] == 1)
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 51, 204, 51));
  else if (it[i] == 2 && map.getApple() == true)
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 251, 0, 0));
  else
    SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 0, 0, 0));
}

bool		N_SDL::DrawMap(Map const &map)
{
  std::string	pars = map.getMap();
  int		i;
  int		x;
  int		y;

  y = 0;
  i = 0;
  while (y < map.getMaxY())
    {
      x = 0;
      while (x < map.getMaxX())
	{
	  init_pos(x, y);
	  fill_point_rect(pars, i, map);
	  x++;
	  i++;
	}
      y++;
    }
  SDL_Flip(screen);
  return (true);
}

bool		N_SDL::DrawQuadra(Map const &map)
{
  int		i;

  i = 0;
  while (i < map.getMaxX())
    {
      vlineColor(screen, (double)(WIN_WIDTH / map.getMaxX() * i), 0, WIN_HEIGHT, 0x696969);
      i++;
    }
  i = 0;
  while (i < map.getMaxY())
    {
      hlineColor(screen, 0, WIN_WIDTH, (double)(WIN_HEIGHT / map.getMaxY() * i), 0x696969);
      i++;
    }
  SDL_Flip(screen);
  return (true);
}

bool		N_SDL::DrawHUD()
{
  return (true);
}

char		N_SDL::HandleEvent()
{
  char		button;

  button = 0;
  while (SDL_PollEvent(&even))
    {
      if (even.key.keysym.sym == SDLK_ESCAPE || even.type == SDL_QUIT)
	button = -1;
      else if (even.key.keysym.sym == SDLK_LEFT)
	button = 1;
      else if (even.key.keysym.sym == SDLK_RIGHT)
	button = 2;
    }
  return (button);
}
