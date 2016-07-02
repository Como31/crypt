##
## Makefile for crypt in /home/meridj/Rendu/crypt
## 
## Made by Lemeh
## Login   <meridj@epitech.net>
## 
## Started on  Tue Jun  7 20:23:02 2016 Lemeh
## Last update Tue Jun  7 21:06:09 2016 Lemeh
##

NAME	= decrypt

GCC	= gcc

CFLAGS	= -Wall -Wextra -W -I./include/

SRCS	= srcs/main.c \
	  srcs/tools.c \
	  srcs/algo.c

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
