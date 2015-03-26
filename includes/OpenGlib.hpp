//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
// Last update Wed Mar  25 18:16:29 2015 Jean-Baptiste Grégoire
//

##ifndef OPENGLIB_HPP
#define OPENGLIB_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

# define ESC_KEY	27
# define FOVY		70
# define NEAR		1
# define FAR		1000
# define WIN_POS_X	100
# define WIN_POS_Y	100
# define WIN_WIDTH	1280
# define WIN_HEIGHT	720

class OpenGlib : public ALibGraph
{
public:
	OpenGlib();
  	bool		Init(int x, int y, int argc, char **argv);
  	bool		DrawMap();
  	void		Destroy();
  	bool		DrawQuadra();
  	bool		DrawHUD();
  	char		HandleEvent();
  	void		ManageKeys(unsigned char key, int x, int y);
	~OpenGlib();

private:
	int 			screen;
};

#endif // OPENGLIB_HPP