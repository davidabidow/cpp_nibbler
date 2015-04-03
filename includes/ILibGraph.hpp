//
// ALibGraph.hpp for ALibGraph in /home/tran_0/rendu/cpp_nibbler
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed Mar 25 14:15:03 2015 David Tran
// Last update Fri Apr  3 18:59:41 2015 David Tran
//

#ifndef ILIBGRAPH_HPP_
# define ILIBGRAPH_HPP_

# include "Map.hpp"

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720
# define UNUSED(a)  __attribute__((unused))a

class		ILibGraph
{
public:
  virtual	~ILibGraph() {}
  ILibGraph(){}
  virtual bool		Init(int, int) = 0;
  virtual bool		DrawMap(std::string const &, bool const) = 0;
  virtual void		Destroy() = 0;
  virtual bool		DrawQuadra(std::string const &) = 0;
  virtual bool		DrawHUD(int, double) = 0;
  virtual char		HandleEvent() = 0;
};

#endif
