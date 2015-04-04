//
// Nibbler_SDL.hpp for Nibbler_SDL in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Tue Mar 24 21:39:31 2015 David Tran
// Last update Sat Apr  4 16:26:15 2015 David Tran
//

#ifndef NIBBLER_SDL_HPP
# define NIBBLER_SDL_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_gfxPrimitives.h>
# include <SDL/SDL_ttf.h>
# include "ILibGraph.hpp"
# include "Map.hpp"
# include "Error.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720
# define WRITE_HUD "./gomarice_the_past.ttf"

class	N_SDL : public ILibGraph
{
public:
  N_SDL();
  virtual ~N_SDL();
  void		Init(int x, int y);
  void		DrawMap(std::string const &, bool const, bool const);
  void		Destroy();
  void		DrawHUD(int const, double const);
  char		HandleEvent();
  void		fill_point_rect(std::string const &, int, bool const, bool const);
  void		init_pos(int, int);
private:
  SDL_Rect	pos;
  SDL_Surface	*screen;
  SDL_Event	even;
  SDL_Surface	*text;
  TTF_Font	*police;
  SDL_Color	color;
  int		maxX;
  int		maxY;
};

#endif
