//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
// Last update Wed Apr  1 17:19:21 2015 Jean-Baptiste Grégoire
//

#ifndef OPENGLIB_HPP
# define OPENGLIB_HPP

# include <GL/gl.h>
# include <GL/glu.h>
# include <SFML/Window.hpp>
# include <SFML/OpenGL.hpp>
# include "Map.hpp"
# include "ILibGraph.hpp"

# define ESC_KEY	27
# define WIN_FOVY	70
# define NEAR		1
# define FAR		1000
# define WIN_POS_X	100
# define WIN_POS_Y	100

void	drawGround(Map const &map);
void	drawCube(int x, int y, int z, int size);
void	drawSnake(Map const &map);

class OpenGlib : public ILibGraph
{
public:
  OpenGlib();
  bool		Init(int, int);
  bool		DrawMap(Map const &map);
  void		Destroy();
  bool		DrawQuadra(Map const &map);
  bool		DrawHUD();
  char		HandleEvent();
		~OpenGlib();

private:
  sf::Window	window;
};

#endif // OPENGLIB_HPP
