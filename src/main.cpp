//
// main.cpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon Mar  9 14:49:22 2015 David Tran
// Last update Tue Mar 24 11:43:45 2015 David Tran
//

#include "nibbler.hpp"

int			check_args(char **av, Map &map)
{
  std::stringstream	ss;
  int			i;
  int			tmp;

  i = 1;
  ss << av[i++];
  ss >> tmp;
  if (ss.good() == false)
    return (-1);
  map.setMax(tmp);
  ss.str(std::string()); // clear the stream
  ss << av[i++];
  ss >> tmp;
  if (ss.good() == false)
    return (-1);
  map.setMax(tmp);
  return (0);
}

int		main(int ac, char **av)
{
  Map map(0, 0);

  if (ac != 4)
    {
      std::cout << "USAGE : " << av[0] << " [witdh][height][lib.so]" << std::endl;
      return (EXIT_FAILURE);
    }
  if (check_args(av, map))
    return (-1);
  if (av[3] == "lib_nibbler_opengl.so")
  {
    OpenGlib lib;
    lib.DrawMap(map);
  }
  return (0);
}
