##
## Makefile for cpp_nibbler in /home/patoche/rendu/CPP/cpp_nibbler/src/Nibbler_Ncurses
## 
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
## 
## Started on  Wed Apr  1 14:08:16 2015 Hugo Prenat
## Last update Wed Apr  1 14:48:19 2015 Hugo Prenat
##

SRC		=	

OBJ		=	$(SRC:.c=.o)

NAME		=	lib_nibbler_ncurses.so

CC		=	gcc

RM		=	rm -f

DEBUG		=	no

INCLUDE 	=	include/

CFLAGS		=	-W -Wall -Wextra -I $(INCLUDE)

LIB		=	-lncurses

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
