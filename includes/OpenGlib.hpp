//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
// Last update Fri Mar 27 19:40:53 2015 Jean-Baptiste Grégoire
//

#ifndef OPENGLIB_HPP
# define OPENGLIB_HPP

# ifdef __APPLE__
#  include <GLUT/glut.h>
# else
#  include <GL/glut.h>
# endif

# include <SFML/Window.hpp>
# include <SFML/OpenGL.hpp>
# include "ALibGraph.hpp"

# define ESC_KEY	27
# define WIN_FOVY	70
# define NEAR		1
# define FAR		1000
# define WIN_POS_X	100
# define WIN_POS_Y	100

void    manageKeys(unsigned char key, int x, int y);
void    manageSpecialKeys(int key, int x, int y);
void    displayMap(void);

class OpenGlib : public ALibGraph
{
public:
  OpenGlib();
  bool		Init(int x, int y, int *argc, char **argv);
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
