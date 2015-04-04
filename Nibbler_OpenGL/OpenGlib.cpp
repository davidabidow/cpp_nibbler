//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Sat Apr  4 23:25:22 2015 Jean-Baptiste Grégoire
//

#include "OpenGlib.hpp"

extern "C"
{
  ILibGraph	*instanciate_lib()
  {
    return (new OpenGlib());
  }
}

OpenGlib::OpenGlib()
{
  maxX = maxY = 0;
}

void		OpenGlib::Init(int x, int y)
{
  float		midx = static_cast<float>(x / 2.0);
  float		midy = static_cast<float>(y / 2.0);

  if (x > 200 || y > 200 || x < 20 || y < 20)
    throw Nibbler_Error_Lib("Init: Please set a size between 20 and 200");
  maxX = x;
  maxY = y;
  window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Nibbler -OpenGL-",
		sf::Style::Default, sf::ContextSettings(32));
  if (window.isOpen() == false)
    throw Nibbler_Error_Lib("SFML: Unable to create window");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOVY, static_cast<double>(WIN_WIDTH / WIN_HEIGHT), NEAR, FAR);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(midx, 30, y * 1.4,
	    midx, 0.5, midy + midy * 0.2,
	    0, 1, 0);
  if (!font.loadFromFile("gomarice_the_past.ttf"))
    noHUD = true;
  else
    {
      noHUD = false;
      text.setFont(font);
      text.setCharacterSize(18);
      text.setStyle(sf::Text::Bold);
      text.setColor(sf::Color::White);
    }
}

void		OpenGlib::DrawMap(std::string const &map, bool const apple,
				  bool const pau)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawWall(maxX, maxY, pau);
  drawGround(maxX, maxY, pau);
  drawSnake(map, maxX, maxY, apple, pau);
  if (noHUD)
    {
      glFlush();
      window.display();
    }
}

void		OpenGlib::Destroy()
{
  window.close();
}

void		OpenGlib::DrawHUD(int score, double time)
{
  std::stringstream	ss;

  window.pushGLStates();
  ss << "score: " << score;
  text.setPosition(15, 15);
  text.setString(ss.str());
  window.draw(text);
  ss.str(std::string());
  ss << "time: " << time;
  text.setPosition(WIN_WIDTH - 120, 15);
  text.setString(ss.str());
  window.draw(text);
  window.display();
  window.popGLStates();
  glFlush();
}

char		OpenGlib::HandleEvent()
{
  char		input;
  sf::Event	event;

  input = 0;
  while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	  input = -1;
      if (event.type ==  sf::Event::KeyPressed)
	{
	  if (event.key.code == sf::Keyboard::Escape)
	    input = -1;
	  else if (event.key.code == sf::Keyboard::Left)
	    input = 1;
	  else if (event.key.code == sf::Keyboard::Right)
	    input = 2;
	  else if (event.key.code == sf::Keyboard::P)
	    input = 3;
	  else
	    input = 0;
	}
    }
  return (input);
}

OpenGlib::~OpenGlib()
{

}
