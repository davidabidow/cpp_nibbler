##
## Makefile for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
##
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
##
## Started on  Wed Apr  1 14:08:16 2015 Hugo Prenat
## Last update Fri Apr  3 23:11:08 2015 David Tran
##

SRC		=	OpenGlib.cpp		\
			OpenGlib_utils.cpp	\
			../src/class/Error.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME		=	lib_nibbler_opengl.so

RM		=	rm -f

DEBUG		=	no

INCLUDES 	=	-I ./SFML-2.2/include/ -I ../includes/

CPPFLAGS	=	-W -Wall -Wextra $(INCLUDES) -fPIC

LDFLAGS		=	-lGL -lGLU

LDFLAGS		+=	./SFML-2.2/lib/libsfml-graphics.so.2.2.0

LDFLAGS		+=	./SFML-2.2/lib/libsfml-window.so.2.2.0

LDFLAGS		+=	./SFML-2.2/lib/libsfml-system.so.2.2.0

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
		g++ -shared -o $(NAME) $(OBJ) $(LDFLAGS)
		@(cp $(NAME) ..)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
