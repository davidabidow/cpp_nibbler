//
// ALibGraph.hpp for ALibGraph in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 14:15:03 2015 David Tran
// Last update Wed Mar 25 16:32:59 2015 David Tran
//

#ifndef ALIBGRAPH_HPP_
# define ALIBGRAPH_HPP_

# include "nibbler.hpp"

class		ALibGraph
{
public:
  virtual		~ALibGraph(){}
  ALibGraph(){}
  virtual bool		Init(int x, int y) = 0;
  virtual bool		DrawMap() = 0;
  virtual void		Destroy() = 0;
  virtual bool		DrawQuadra() = 0;
  virtual bool		DrawHUD() = 0;
private:
  int			maxX;
  int			maxY;
};

#endif
