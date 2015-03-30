//
// Error.cpp for Error in /home/tran_0/rendu/cpp_nibbler/includes
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Thu Mar 26 17:30:00 2015 David Tran
// Last update Mon Mar 30 14:33:39 2015 Jean-Baptiste Grégoire
//

#include "Error.hpp"

Nibbler_Error::Nibbler_Error(std::string const &messa) : message(messa)
{

}

std::string const	&what()
{
  return (message);
}

Nibbler_Error::~Nibbler_Error()
{

}

Nibbler_Error_Lib::Nibbler_Error_Lib(std::string const &messa) : message(messa)
{

}

std::string const	&what()
{
  return (message);
}

Nibbler_Error_Lib::~Nibbler_Error_Lib()
{

}

Nibbler_Error_Pars::Nibbler_Error_Pars(std::string const &messa) : message(messa)
{

}

std::string const	&what()
{
  return (message);
}

Nibbler_Error_Pars::~Nibbler_Error_Pars()
{

}
