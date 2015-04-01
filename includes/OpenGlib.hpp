//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
// Last update Wed Apr  1 16:21:24 2015 David Tran
//

#ifndef OPENGLIB_HPP
# define OPENGLIB_HPP

# include <GL/gl.h>
# include <GL/glu.h>
# include <SFML/Window.hpp>
# include <SFML/OpenGL.hpp>
# include "ILibGraph.hpp"

# define ESC_KEY	27
# define WIN_FOVY	70
# define NEAR		1
# define FAR		1000
# define WIN_POS_X	100
# define WIN_POS_Y	100

void	drawGround(Map const &map) const;
void	drawCube(int x, int y, int z, int size);
void	drawSnake(Map const &map) const;

class OpenGlib : public ILibGraph
{
public:
  OpenGlib();
  bool		Init(int, int);
  bool		DrawMap(Map const &map);
  void		Destroy();
  bool		DrawQuadra();
  bool		DrawHUD();
  char		HandleEvent();
		~OpenGlib();

private:
  sf::Window	window;
};

#endif // OPENGLIB_HPP
