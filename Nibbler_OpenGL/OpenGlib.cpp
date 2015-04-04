//
// OpenGlib.cpp for nibbler in /home/jibb/rendu/cpp_nibbler/src/class
//
// Made by Jean-Baptiste Grégoire
// Login   <gregoi_j@epitech.net>
//
// Started on  Wed Mar  25 18:29:42 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  3 23:40:55 2015 Jean-Baptiste Grégoire
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

bool		OpenGlib::Init(int x, int y)
{
  float		midx = static_cast<float>(x / 2.0);
  float		midy = static_cast<float>(y / 2.0);

  maxX = x;
  maxY = y;
  window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Nibbler -OpenGL-", sf::Style::Default, sf::ContextSettings(32));
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOVY, static_cast<double>(WIN_WIDTH / WIN_HEIGHT), NEAR, FAR);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(midx, 30, 70,
	    midx, 0.5, midy + 20,
	    0, 1, 0);
  return (true);
}

bool		OpenGlib::DrawMap(std::string const &map, bool const apple)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawWall(maxX, maxY);
  drawGround(maxX, maxY);
  drawSnake(map, maxX, maxY, apple);
  // glFlush();
  // window.display();
  return (true);
}

void		OpenGlib::Destroy()
{
  window.close();
}

bool		OpenGlib::DrawQuadra(std::string const &map)
{
  return (true);
}

bool		OpenGlib::DrawHUD(int score, double time)
{
  std::stringstream	ss;
  sf::Font		font;
  sf::Text		text;

  window.pushGLStates();
  if (!font.loadFromFile("gomarice_the_past.ttf"))
    return (false);
  text.setFont(font);
  text.setCharacterSize(18);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::White);
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
  return (true);
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
	  else
	    input = 0;
	}
    }
  return (input);
}

OpenGlib::~OpenGlib()
{

}
