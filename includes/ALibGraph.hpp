//
// ALibGraph.hpp for ALibGraph in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 14:15:03 2015 David Tran
// Last update Thu Mar 26 18:25:27 2015 David Tran
//

#ifndef ALIBGRAPH_HPP_
# define ALIBGRAPH_HPP_

# include "nibbler.hpp"
# include "Map.hpp"

class		ALibGraph
{
public:
  virtual	~ALibGraph(){}
  ALibGraph(int x, int y) : maxX(x), maxY(y) {}
  bool		Init() = 0;
  bool		DrawMap(Map const &map) = 0;
  void		Destroy() = 0;
  bool		DrawQuadra(Map const &map) = 0;
  bool		DrawHUD() = 0;
  char		HandleEvent() = 0;
  int		getMaxX(){return (maxX);}
  int		getMaxY(){return (maxY);}
private:
  int			maxX;
  int			maxY;
};

#endif
