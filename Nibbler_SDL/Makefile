##
## Makefile for nibbler  in /home/tran_0/rendu/cpp_nibbler
## 
## Made by David Tran
## Login   <tran_0@epitech.net>
## 
## Started on  Thu Apr  2 20:49:40 2015 David Tran
## Last update Thu Apr  2 21:38:16 2015 Hugo Prenat
##

SRC		=	SDL_init.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	lib_nibbler_sdl.so

RM		=	rm -f

DEBUG		=	yes

INCLUDE 	=	../includes/

GXX		=	g++

CXXFLAGS	=	-W -Wall -Wextra -I $(INCLUDE) -fPIC

LIB		=	-lSDL -lSDLmain -lSDL_gfx -lSDL_image

ifeq ($(DEBUG),yes)

CXXFLAGS 	+= -g3

else

CXXFLAGS	+= -O3

endif

$(NAME):	$(OBJ)
		g++ -shared -o $(NAME) $(OBJ) $(LIB)
		@(cp $(NAME) ..)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
