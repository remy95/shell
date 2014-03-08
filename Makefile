##
## Makefile for makefile in /home/macmil_r/rendu/102chiffrement
## 
## Made by a
## Login   <macmil_r@epitech.net>
## 
## Started on  Sun Dec  1 19:52:05 2013 a
## Last update Sat Mar  8 21:35:42 2014 a
##

CC	= gcc

NAME	= mysh

SRC	= minishell.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_strcat.c \
	  my_str_to_wordtab.c \
	  my_strncmp.c \
	  my_strcmp.c \
	  my_strlen.c \
	  epure.c \
	  sep.c \
	  pipe.c \
	  signal.c \
	  main.c \
	  malloc_wordtab.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
