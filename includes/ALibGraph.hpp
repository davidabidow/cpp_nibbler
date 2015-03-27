//
// ALibGraph.hpp for ALibGraph in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 14:15:03 2015 David Tran
// Last update Fri Mar 27 00:43:52 2015 David Tran
//

#ifndef ALIBGRAPH_HPP_
# define ALIBGRAPH_HPP_

# include "nibbler.hpp"
# include "Map.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

class		ALibGraph
{
public:
  virtual	~ALibGraph(){}
  ALibGraph(int x, int y) : maxX(x), maxY(y) {}
  virtual bool		Init() = 0;
  virtual bool		DrawMap(Map const &map) = 0;
  virtual void		Destroy() = 0;
  virtual bool		DrawQuadra(Map const &map) = 0;
  virtual bool		DrawHUD() = 0;
  virtual char		HandleEvent() = 0;
  int			getMaxX() const {return (maxX);}
  int			getMaxY() const {return (maxY);}
private:
  int			maxX;
  int			maxY;
};

#endif
