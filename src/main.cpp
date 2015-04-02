//
// main.cpp for nibbler in /home/tran_0/rendu/cpp_nibbler/src
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Mon Mar  9 14:49:22 2015 David Tran
// Last update Thu Apr  2 15:10:21 2015 David Tran
//

#include "Map.hpp"
#include "LibNcurses.hpp"
#include "OpenGlib.hpp"

int			check_args(char **av, Map **map)
{
  std::stringstream	s(av[1]);
  int			tmpx;
  int			tmpy;

  s >> tmpx;
  std::stringstream	ss(av[2]);
  ss >> tmpy;
  if (tmpx < 10 || tmpy < 10)
    return (-1);
  *map = new Map(tmpx, tmpy);
  std::cout << tmpx  << " " << tmpy << std::endl;
  // map.setMaxX(tmpx);
  // map.setMaxY(tmpy);
  return (0);
}

int		main(int ac, char **av)
{
  Map		*map;
  void		*dlHandler;
  ILibGraph	*(*external_creator)();

  if (ac != 4)
    {
      std::cout << "USAGE : " << av[0] << " [witdh][height][lib.so]" << std::endl;
      return (EXIT_FAILURE);
    }
  if (check_args(av, &map) == -1)
    return (-1);
  if (!(dlHandler = dlopen(av[3], RTLD_LAZY)))
    return (EXIT_FAILURE);
  if (!(external_creator = reinterpret_cast<ILibGraph *(*)()>(dlsym(dlHandler, "instanciate_lib"))))
    return (EXIT_FAILURE);
  if (strcmp(av[3],"lib_nibbler_opengl.so") == 0)
    {
      ILibGraph		*lib = external_creator();

      lib->Init(map->getMaxX(), map->getMaxY());
      map->fill_string();
      lib->DrawMap(*map);
      map->loop_game(lib);
    }
  if (strcmp(av[3],"lib_nibbler_sdl.so") == 0)
    {
      ILibGraph		*lib = external_creator();

      lib->Init(map->getMaxX(), map->getMaxY());
      map->fill_string();
      lib->DrawMap(*map);
      map->loop_game(lib);
    }
  if (strcmp(av[3],"lib_nibbler_ncurses.so") == 0)
    {
      ILibGraph		*lib = external_creator();

      lib->Init(map->getMaxX(), map->getMaxY());
      map->fill_string();
      lib->DrawMap(*map);
      map->loop_game(lib);
      lib->Destroy();
    }
  dlclose(dlHandler);
  return (0);
}
