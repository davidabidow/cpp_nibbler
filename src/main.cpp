//
// main.cpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Mon Mar  9 14:49:22 2015 David Tran
// Last update Sat Apr  4 15:40:00 2015 David Tran
//

#include "Map.hpp"

void			check_args(char **av, Map **map)
{
  std::stringstream	s(av[1]);
  int			tmpx;
  int			tmpy;

  s >> tmpx;
  std::stringstream	ss(av[2]);
  ss >> tmpy;
  if (tmpx < 10 || tmpy < 10)
    throw Nibbler_Error_Pars("Invalid Size for Map");
  *map = new Map(tmpx, tmpy);
}

int		check_invalid_arg(char **av, Map **map,
				  ILibGraph **lib, void **dlHandler)
{
  ILibGraph	*(*external_creator)();

  try
    {
      check_args(av, map);
      if (!(*dlHandler = dlopen(av[3], RTLD_LAZY)))
	throw Nibbler_Error_Pars(dlerror());
      if (!(external_creator = reinterpret_cast<ILibGraph *(*)()>(dlsym(*dlHandler, "instanciate_lib"))))
	throw Nibbler_Error_Pars(dlerror());
      *lib = external_creator();
    }
  catch (Nibbler_Error_Pars	const &e)
    {
      std::cout << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

void		launch_game(Map *map, ILibGraph *lib)
{
  try
    {
      lib->Init(map->getMaxX(), map->getMaxY());
      map->loop_game(lib);
      lib->Destroy();
    }
  catch (Nibbler_Error_Lib const &e)
    {
      std::cout << e.what() << std::endl;
    }
}

int		main(int ac, char **av)
{
  Map		*map;
  ILibGraph	*lib;
  void		*dlHandler;

  if (ac != 4)
    {
      std::cout << "USAGE : " << av[0] << " [witdh][height][lib.so]" << std::endl;
      return (EXIT_FAILURE);
    }
  if (check_invalid_arg(av, &map, &lib, &dlHandler) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  launch_game(map, lib);
  dlclose(dlHandler);
  return (0);
}
