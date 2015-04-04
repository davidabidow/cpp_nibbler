##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
##
## Made by David Tran
## Login   <tran_0@epitech.net>
##
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Sun Apr  5 01:49:13 2015 Jean-Baptiste Grégoire
##

DEBUG		= 	yes

NAME		=	nibbler

SDL		=	Nibbler_SDL

OPENGL		=	Nibbler_OpenGL

NCURSES		=	Nibbler_Ncurses

SRC		=	src/main.cpp			\
			src/class/Map.cpp		\
			src/class/Error.cpp		\
			src/class/Snake.cpp		\
			src/class/Score.cpp		\

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDES	=	includes/

FOLDER_SRC	=	src/

CPPFLAGS	=	-W -Wall -Wextra -I $(INCLUDES) -ldl

ifeq ($(DEBUG),yes)

CPPFLAGS 	+= -g3

else

CPPFLAGS	+= -O3

endif

$(NAME):	$(OBJ)
		@rm -f src/class/Error.o
		make --no-print-directory -C $(SDL)
		make --no-print-directory -C $(NCURSES)
		make --no-print-directory -C $(OPENGL)
		make --no-print-directory $(OBJ)
		$(CC) -o $(NAME) $(OBJ) -ldl

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		make --no-print-directory -C $(SDL) clean
		make --no-print-directory -C $(NCURSES) clean
		make --no-print-directory -C $(OPENGL) clean

fclean:		clean
		$(RM) $(NAME)
		make --no-print-directory -C $(SDL) fclean
		make --no-print-directory -C $(NCURSES) fclean
		make --no-print-directory -C $(OPENGL) fclean

re:		fclean all

.PHNOY:		re fclean clean all
