//
// Error.cpp for Error in /home/tran_0/rendu/cpp_nibbler/includes
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Thu Mar 26 17:30:00 2015 David Tran
// Last update Sun Mar 29 22:33:11 2015 David Tran
//

#include "Error.hpp"

Nibbler_Error::Nibbler_Error(std::string const &messa) : std::exception(), _message(messa)
{}

Nibbler_Error_Lib::Nibbler_Error_Lib(std::string const &messa) : std::runtime_error(messa), _message(messa)
{}

Nibbler_Error_Pars::Nibbler_Error_Pars(std::string const &messa) : std::invalid_argument(messa), _message(messa)
{}
