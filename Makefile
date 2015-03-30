##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
## 
## Made by David Tran
## Login   <tran_0@epitech.net>
## 
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Mon Mar 30 16:57:29 2015 David Tran
##

DEBUG		= 	yes

NAME		=	nibbler

SRC		=	src/main.cpp			\
			src/class/Map.cpp		\
			src/class/Error.cpp		\
			src/class/Snake.cpp		\
			src/Nibbler_SDL/SDL_init.cpp	\

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDES	=	includes/

FOLDER_SRC	=	src/

CPPFLAGS	=	-W -Wall -Wextra -I $(INCLUDES)

ifeq ($(DEBUG),yes)
	CPPFLAGS 	+= -g3
else
	CPPFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lSDL -lSDLmain -lSDL_gfx -lSDL_image

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
