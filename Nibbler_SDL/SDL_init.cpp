//
// SDL_init.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Tue Mar 24 21:56:30 2015 David Tran
// Last update Sun Apr  5 22:17:01 2015 Jean-Baptiste Grégoire
//

# include "Nibbler_SDL.hpp"

extern "C"
{
  ILibGraph	*instanciate_lib()
  {
    return (new N_SDL());
  }
}

N_SDL::N_SDL()
{
  maxX = maxY = 0;
}

N_SDL::~N_SDL()
{}

void		N_SDL::Init(int x, int y)
{
  if (x > 190 || y > 90)
    throw Nibbler_Error_Lib("Sizes are too high [x <= 190 && y <= 90]");
  maxX = x * 10;
  maxY = y * 10;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    throw Nibbler_Error_Lib("Unable to launch Library SDL");
  if (!(screen = SDL_SetVideoMode(maxX, maxY + 50, 32, SDL_HWSURFACE)))
    {
      SDL_Quit();
      throw Nibbler_Error_Lib("Unable to set VideoMode for SDL");
    }
  SDL_WM_SetCaption("cpp_Nibbler", NULL);
  if (TTF_Init() == -1)
    throw Nibbler_Error_Lib("Unable to set Font for SDL");
  color.r = 255;
  color.g = 255;
  color.b = 255;
  if (x < 50)
    {
      if (!(police = TTF_OpenFont("./gomarice_the_past.ttf", 20)))
	throw Nibbler_Error_Lib("Unable to Open Font for SDL");
    }
  else
    if (!(police = TTF_OpenFont("./gomarice_the_past.ttf", 40)))
      throw Nibbler_Error_Lib("Unable to Open Font for SDL");
}

void		N_SDL::Destroy()
{
  TTF_Quit();
  SDL_Quit();
}

void		N_SDL::init_pos(int x, int y)
{
  SDL_Rect	tmp;

  tmp.x = 10 * x;
  tmp.y = 10 * y;
  tmp.w = 10;
  tmp.h = 10;
  pos = tmp;
}

void		N_SDL::fill_point_rect(std::string const &it, int i,
				       bool const apple, bool const pau)
{
  int		minus;

  if (pau == false)
    minus = 0;
  else
    minus = 50;
  if (it[i] == 1)
    {
      if (SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 51 - minus, 204 - minus, 51 - minus)) != 0)
	throw Nibbler_Error_Lib("Cannot Fill Map for SDL : fill_point_rect l.76");
    }
  else if (it[i] == 2 && apple == true)
    {
      if (SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 251 - minus, 0, 0)) != 0)
	throw Nibbler_Error_Lib("Cannot Fill Map for SDL : fill_point_rect l.81");
    }
  else if (it[i] == 3)
    {
      if (SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 0, 0, 204 - minus)) != 0)
	throw Nibbler_Error_Lib("Cannot Fill Map for SDL : fill_point_rect l.86");
    }
  else
    {
      if (SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 69 - minus, 69 - minus, 69 - minus)) != 0)
	throw Nibbler_Error_Lib("Cannot Fill Map for SDL : fill_point_rect l.91");
    }
}

void		N_SDL::DrawMap(std::string const &pars, bool const apple,
			       bool const pau)
{
  int		i;
  int		x;
  int		y;

  y = 0;
  i = 0;
  while (y < maxY / 10)
    {
      x = 0;
      while (x < maxX / 10)
	{
	  init_pos(x, y);
	  fill_point_rect(pars, i, apple, pau);
	  x++;
	  i++;
	}
      y++;
    }
}

void			N_SDL::DrawHUD(int const score, double const time)
{
  std::ostringstream	os;

  pos.x = 0;
  pos.y = maxY;
  pos.w = maxX;
  pos.h = 100;
  color.r = 255;
  color.g = 255;
  color.b = 255;
  if (SDL_FillRect(screen, &pos, SDL_MapRGB(screen->format, 69, 69, 69)) != 0)
    throw Nibbler_Error_Lib("Cannot Fill Map for SDL : DrawHUD l.127");
  os << "score: ";
  os << score;
  pos.x = 0;
  pos.y = maxY + 5;
  if (maxX / 10 < 50)
    {
      std::string		contain_l(os.str());
      if (!(text = TTF_RenderText_Blended(police, contain_l.c_str(), color)))
	throw Nibbler_Error_Lib("Cannot Write Text on Map for SDL : DrawHUD l.139");
      SDL_BlitSurface(text, NULL, screen, &pos);
      std::ostringstream	oss;
      oss << "time : ";
      oss << time;
      std::string		contain_li(oss.str());
      pos.x = 0;
      pos.y = maxY + 25;
      if (!(text = TTF_RenderText_Blended(police, contain_li.c_str(), color)))
	throw Nibbler_Error_Lib("Cannot Write Text on Map for SDL : DrawHUD l.139");
    }
  else
    {
      os << "  time : ";
      os << time;
      std::string		contain(os.str());
      if (!(text = TTF_RenderText_Blended(police, contain.c_str(), color)))
	throw Nibbler_Error_Lib("Cannot Write Text on Map for SDL : DrawHUD l.139");
    }
  SDL_BlitSurface(text, NULL, screen, &pos);
  hlineColor(screen, 0, maxX, maxY, 0xFFFFFF);
  SDL_Flip(screen);
  SDL_FreeSurface(text);
}

char		N_SDL::HandleEvent()
{
  char		button;

  button = 0;
  while (SDL_PollEvent(&even))
    {
      if (even.type == SDL_QUIT)
	button = -1;
      if (even.type == SDL_KEYDOWN)
	{
	  if (even.key.keysym.sym == SDLK_ESCAPE)
	    button = -1;
	  else if (even.key.keysym.sym == SDLK_LEFT)
	    button = 1;
	  else if (even.key.keysym.sym == SDLK_RIGHT)
	    button = 2;
	  else if (even.key.keysym.sym == SDLK_p)
	    button = 3;
	}
    }
  return (button);
}
