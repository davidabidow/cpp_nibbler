##
## Makefile for Nibbler in /home/jibb/rendu/cpp_nibbler
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Sun Apr  1 01:23:03 2015 Jean-Baptiste Grégoire
## Last update Sun Apr  5 19:35:53 2015 Jean-Baptiste Grégoire
##

SRC		=	OpenGlib.cpp		\
			OpenGlib_utils.cpp

NIBSRC		=	../src/class/Error.cpp

OBJ		=	$(SRC:.cpp=.o)

NIBOBJ		=	$(NIBSRC:.cpp=.o)

NIBOBJFILE	=	Error.o

NAME		=	lib_nibbler_opengl.so

CC		=	g++

RM		=	rm -f

DEBUG		=	no

INCLUDES 	=	-I ./SFML-2.2/include/ -I ../includes/

CPPFLAGS	=	-W -Wall -Wextra $(INCLUDES) -fPIC

LDFLAGS		=	-lGL -lGLU
LDFLAGS		+=	-L./SFML-2.2/lib
LDFLAGS		+=	-lsfml-graphics -lsfml-system -lsfml-window -lGLEW
LDFLAGS		+=	-Wl,-rpath=./Nibbler_OpenGL/SFML-2.2/lib

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ) $(NIBOBJ)
		@mv $(NIBOBJ) .
		$(CC) -shared -o $(NAME) $(OBJ) $(NIBOBJFILE) $(LDFLAGS)
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
