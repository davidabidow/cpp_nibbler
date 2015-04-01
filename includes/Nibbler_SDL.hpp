//
// Nibbler_SDL.hpp for Nibbler_SDL in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue Mar 24 21:39:31 2015 David Tran
// Last update Wed Apr  1 16:25:57 2015 David Tran
//

#ifndef NIBBLER_SDL_HPP
# define NIBBLER_SDL_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_gfxPrimitives.h>
# include "ILibGraph.hpp"
# include "Map.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

class	N_SDL : public ILibGraph
{
public:
  N_SDL();
  ~N_SDL();
  bool		Init(int x, int y);
  bool		DrawMap(Map const &);
  void		Destroy();
  bool		DrawQuadra(Map const &);
  bool		DrawHUD();
  char		HandleEvent();
  void		fill_point_rect(std::string, int, Map const &);
  void		init_pos(int, int);
private:
  SDL_Rect	pos;
  SDL_Surface	*screen;
  SDL_Event	even;
  int		maxX;
  int		maxY;
};

#endif
