//
// Nibbler_SDL.hpp for Nibbler_SDL in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:39:31 2015 David Tran
// Last update Wed Mar 25 14:24:49 2015 David Tran
//

#ifndef NIBBLER_SDL_HPP
# define NIBBLER_SDL_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_gfxPrimitives.h>
# include "ALibGraph.hpp"

class	N_SDL : public ALibGraph
{
public:
  N_SDL();
  virtual ~N_SDL();
  bool		Init(int x, int y);
  bool		DrawMap(Snake const &s);
  void		Destroy();
  bool		DrawQuadra();
  bool		DrawHUD();
private:
  SQL_Rect	pos;
  SDL_Surface	*screen;
  SDL_Event	even;
};

#endif
