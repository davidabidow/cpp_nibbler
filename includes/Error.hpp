//
// Error.hpp for Nibbler in /home/tran_0/rendu/cpp_nibbler/includes
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Thu Mar 26 16:34:32 2015 David Tran
// Last update Mon Mar 30 14:35:21 2015 Jean-Baptiste Grégoire
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <exception>
# include "Map.hpp"

class	Nibbler_Error : public std::exception
{
public:
  Nibbler_Error(std::string const &);
  ~Nibbler_Error();

private:
  std::string const message;
};

class	Nibbler_Error_Lib : public std::runtime_error
{
public:
  Nibbler_Error_Lib(std::string const &);
  ~Nibbler_Error_Lib();

private:
  std::string const message;
};

class	Nibbler_Error_Pars : public std::invalid_argument
{
public:
  Nibbler_Error_Pars(std::string const &);
  ~Nibbler_Error_Pars();

private:
  std::string const message;
};

#endif
