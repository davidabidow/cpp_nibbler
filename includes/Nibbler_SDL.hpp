//
// Nibbler_SDL.hpp for Nibbler_SDL in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:39:31 2015 David Tran
// Last update Sat Mar 28 20:07:34 2015 David Tran
//

#ifndef NIBBLER_SDL_HPP
# define NIBBLER_SDL_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_gfxPrimitives.h>
# include "ALibGraph.hpp"
# include "Map.hpp"

class	N_SDL : public ALibGraph
{
public:
  N_SDL();
  virtual ~N_SDL();
  bool		Init(int x, int y);
  bool		DrawMap(MAP const &s);
  void		Destroy();
  bool		DrawQuadra(MAP const &s);
  bool		DrawHUD();
  char		HandleEvent();
  void		fill_point_rect(int, int, std::string::const_iterator);
  void		init_pos(int, int);
private:
  SQL_Rect	pos;
  SDL_Surface	*screen;
  SDL_Event	even;
};

#endif
