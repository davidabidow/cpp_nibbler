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

int			check_args(char **av, Controler &Nibbler)
{
  std::stringstream	ss;
  int			i;
  int			tmp;

  i = 1;
  ss << av[i++];
  ss >> tmp;
  Nibbler.setMax(tmp);
  ss << av[i++];
  ss >> tmp;
  Nibbler.setMax(tmp);
  
}

int		main(int ac, char **av)
{
  Controler	Nibbler;

  if (ac != 4)
    {
      std::cout << "USAGE : " << av[0] << " [witdh][height][lib.so]" << std::endl;
      return (EXIT_FAILURE);
    }
}
