##
## Makefile for nibbler  in /home/tran_0/rendu/cpp_nibbler
##
## Made by David Tran
## Login   <tran_0@epitech.net>
##
## Started on  Thu Apr  2 20:49:40 2015 David Tran
## Last update Sun Apr  5 01:40:47 2015 Jean-Baptiste Grégoire
##

SRC		=	SDL_init.cpp

NIBSRC		=	../src/class/Error.cpp

OBJ		=	$(SRC:.cpp=.o)

NIBOBJ		=	$(NIBSRC:.cpp=.o)

NIBOBJFILE	=	Error.o

NAME		=	lib_nibbler_sdl.so

RM		=	rm -f

DEBUG		=	no

INCLUDE 	=	../includes/

GXX		=	g++

CXXFLAGS	=	-W -Wall -Wextra -I $(INCLUDE) -fPIC

LIB		=	-lSDL -lSDLmain -lSDL_gfx -lSDL_image -lSDL_ttf

ifeq ($(DEBUG),yes)

CXXFLAGS 	+= -g3

else

CXXFLAGS	+= -O3

endif

$(NAME):	$(OBJ) $(NIBOBJ)
		@mv $(NIBOBJ) .
		g++ -shared -o $(NAME) $(OBJ) $(NIBOBJFILE) $(LIB)
		@(cp $(NAME) ..)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(NIBOBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
