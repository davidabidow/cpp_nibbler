//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  3 23:22:49 2015 Jean-Baptiste Grégoire
//

#ifndef OPENGLIB_HPP
# define OPENGLIB_HPP

# include <GL/gl.h>
# include <GL/glu.h>
# include <SFML/Window.hpp>
# include <SFML/OpenGL.hpp>
# include <SFML/Graphics/Text.hpp>
# include <SFML/Graphics/RenderWindow.hpp>

# include "Map.hpp"
# include "ILibGraph.hpp"

# define ESC_KEY	27
# define WIN_FOVY	70
# define NEAR		1
# define FAR		1000
# define WIN_POS_X	100
# define WIN_POS_Y	100

void	drawGround(int maxX, int maxY);
void	drawWall(int x, int y);
void	drawCube(double x, double y, double z, double size);
void	drawSnake(std::string const &map, int maxX, int maxY, bool const apple);

class OpenGlib : public ILibGraph
{
public:
  OpenGlib();
  bool		Init(int, int);
  bool		DrawMap(std::string const &map, bool const apple);
  void		Destroy();
  bool		DrawQuadra(std::string const &map);
  bool		DrawHUD(int score, double time);
  char		HandleEvent();
		~OpenGlib();

private:
  sf::RenderWindow	window;
  int		maxX;
  int		maxY;
};

#endif // OPENGLIB_HPP
