##
## Makefile for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
##
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
##
## Started on  Wed Apr  1 14:08:16 2015 Hugo Prenat
## Last update Sun Apr  5 22:07:04 2015 David Tran
##

SRC		=	LibNcurses.cpp

NIBSRC		=	../src/class/Error.cpp

OBJ		=	$(SRC:.cpp=.o)

NIBOBJ		=	$(NIBSRC:.cpp=.o)

NIBOBJFILE	=	Error.o

NAME		=	lib_nibbler_ncurses.so

RM		=	rm -f

DEBUG		=	no

INCLUDE 	=	../includes/

CXX		=	g++

LIB		=	-lncurses

CXXFLAGS	=	-W -Wall -Wextra -I $(INCLUDE) $(LIB) -fPIC

ifeq ($(DEBUG),yes)
	CXXFLAGS 	+= -g3
else
	CXXFLAGS	+= -O3
endif

$(NAME):	$(OBJ) $(NIBOBJ)
		@mv $(NIBOBJ) .
		g++ -shared -o $(NAME) $(OBJ) $(NIBOBJFILE) $(LIB)
		@(cp $(NAME) ../)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(NIBOBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
