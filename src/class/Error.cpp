//
// Error.cpp for Error in /home/tran_0/rendu/cpp_nibbler/includes
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Thu Mar 26 17:30:00 2015 David Tran
// Last update Thu Mar 26 17:37:26 2015 David Tran
//

#include "Error.hpp"

Nibbler_Error::Nibbler_Error(std::string const &messa) : message(messa)
{}

Nibbler_Error::~Nibbler_Error()
{}

Nibbler_Error_Lib::Nibbler_Error_Lib(std::string const &messa) : message(messa)
{}

Nibbler_Error_Lib::~Nibbler_Error_Lib()
{}

Nibbler_Error_Pars::Nibbler_Error_Pars(std::string const &messa) : message(messa)
{}

Nibbler_Error_Pars::~Nibbler_Error_Pars()
{}
