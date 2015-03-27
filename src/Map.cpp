//
// Map.cpp for Nibbler in /home/tran_0/rendu/cpp_nibbler
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed Mar 25 15:29:59 2015 David Tran
// Last update Wed Mar 25 18:32:29 2015 David Tran
//

#include "Map.hpp"

Map Map::_instance = Map();

Map::Map()
{}

Map 	&Map::getInstance()
{
	return (_instance);
}

Map::~Map()
{}

bool	Map::genObj()
{
  
}

void	Map::setPts()
{

}

void	Map::setCoord()
{

}

int		Map::getMaxX() const
{
  return (maxX);
}

int		Map::getMaxY() const
{
  return (maxY);
}
