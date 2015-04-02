##
## Makefile for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
## 
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
## 
## Started on  Wed Apr  1 14:08:16 2015 Hugo Prenat
## Last update Thu Apr  2 15:37:18 2015 David Tran
##

SRC		=	OpenGlib.cpp		\
			OpenGlib_utils.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME		=	lib_nibbler_opengl.so

RM		=	rm -f

DEBUG		=	no

INCLUDE 	=	../../includes/

CPPFLAGS	=	-W -Wall -Wextra -I $(INCLUDE) -fPIC -shared -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU

LIB		=	-lncurses

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):
		g++ $(CPPFLAGS) -c $(SRC) -fPIC
		g++ -shared -o $(NAME) $(OBJS) -lncurses
		@(cp $(NAME) ../..)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../../$(NAME)

re: 		fclean all

.PHONY: all clean fclean re
