##
## Makefile for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
## 
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
## 
## Started on  Wed Apr  1 14:08:16 2015 Hugo Prenat
## Last update Thu Apr  2 20:50:15 2015 David Tran
##

SRC		=	LibNcurses.cpp

OBJ		=	$(SRC:.cpp=.o)

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

$(NAME):	$(OBJ)
		g++ -shared -o $(NAME) $(OBJ) $(LIB)
		@(cp $(NAME) ../)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
