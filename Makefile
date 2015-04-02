##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
##
## Made by David Tran
## Login   <tran_0@epitech.net>
##
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Thu Apr  2 15:48:44 2015 David Tran
##

DEBUG		= 	yes

NAME		=	nibbler

SRC		=	src/main.cpp			\
			src/class/Map.cpp		\
			src/class/Error.cpp		\
			src/class/Snake.cpp		\

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
		@(cd src/Nibbler_SDL && $(MAKE))
#		@(cd src/Nibbler_OpenGL && $(MAKE))
		@(cd src/Nibbler_Ncurses && $(MAKE))

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		@(cd src/Nibbler_SDL && $(MAKE) clean)
#		@(cd src/Nibbler_OpenGL && $(MAKE) clean)
		@(cd src/Nibbler_Ncurses && $(MAKE) clean)

fclean:		clean
		$(RM) $(NAME)
		@(cd src/Nibbler_SDL && $(MAKE) fclean)
#		@(cd src/Nibbler_OpenGL && $(MAKE) fclean)
		@(cd src/Nibbler_Ncurses && $(MAKE) fclean)

re:		fclean all

.PHNOY:		re fclean clean all
