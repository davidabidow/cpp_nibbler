##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
##
## Made by David Tran
## Login   <tran_0@epitech.net>
##
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Fri Apr  3 21:38:42 2015 David Tran
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
		$(CC) -o $(NAME) $(OBJ) -ldl
		make -C $(SDL)
#		make -C $(NCURSES)
#		make -C $(OPENGL)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		make -C $(SDL) clean
		make -C $(NCURSES) clean
		make -C $(OPENGL) clean

fclean:		clean
		$(RM) $(NAME)
		make -C $(SDL) fclean
		make -C $(NCURSES) fclean
		make -C $(OPENGL) fclean

re:		fclean all

.PHNOY:		re fclean clean all
