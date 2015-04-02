##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
##
## Made by David Tran
## Login   <tran_0@epitech.net>
##
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Wed Apr  1 17:18:51 2015 Jean-Baptiste Grégoire
##

DEBUG		= 	yes

NAME		=	nibbler

SRC		=	src/main.cpp			\
			src/class/Map.cpp		\
			src/class/Error.cpp		\
			src/class/Snake.cpp		\
			src/Nibbler_SDL/SDL_init.cpp	\
			src/Nibbler_OpenGL/OpenGlib.cpp	\
			src/Nibbler_OpenGL/OpenGlib_utils.cpp	\
			src/Nibbler_Ncurses/LibNcurses.cpp	\

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDES	=	includes/

FOLDER_SRC	=	src/

LIBS		=	-lncurses

CPPFLAGS	=	-W -Wall -Wextra -I $(INCLUDES)

ifeq ($(DEBUG),yes)
	CPPFLAGS 	+= -g3
else
	CPPFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lSDL -lSDLmain -lSDL_gfx -lSDL_image -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU $(LIBS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
