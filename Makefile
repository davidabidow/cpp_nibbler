##
## Makefile for nibbler in /home/tran_0/rendu/cpp_nibbler
## 
## Made by David Tran
## Login   <tran_0@epitech.net>
## 
## Started on  Mon Mar  9 14:56:07 2015 David Tran
## Last update Mon Mar  9 14:56:57 2015 David Tran
##

DEBUG		= 	yes

NAME		=	nibbler

SRC		=	src/main.cpp		\

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDES	=	includes/

FOLDER_SRC	=	src/

CPPFLAGS		=	-W -Wall -Wextra -I $(INCLUDES)

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
