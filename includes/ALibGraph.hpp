//
// ALibGraph.hpp for ALibGraph in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 14:15:03 2015 David Tran
// Last update Tue Mar 31 22:34:42 2015 Jean-Baptiste Grégoire
//

#ifndef ALIBGRAPH_HPP_
# define ALIBGRAPH_HPP_

# include "Map.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720
# define UNUSED(a)  __attribute__((unused))a

class		ALibGraph
{
public:
  virtual	~ALibGraph() {}
  ALibGraph(int x, int y) : maxX(x), maxY(y) {}
  virtual bool		Init() = 0;
  virtual bool		DrawMap(Map const &) = 0;
  virtual void		Destroy() = 0;
  virtual bool		DrawQuadra(Map const &) = 0;
  virtual bool		DrawHUD() = 0;
  virtual char		HandleEvent() = 0;
  int			getMaxX() const {return (maxX);}
  int			getMaxY() const {return (maxY);}
  void			setMaxX(int a) {maxX = a;};
  void			setMaxY(int a) {maxY = a;};
protected:
  int			maxX;
  int			maxY;
};

#endif
