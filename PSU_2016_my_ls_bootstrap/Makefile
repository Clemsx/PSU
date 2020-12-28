##
## Makefile for Makefimle in /home/clemsx/PSU/PSU_2016_my_ls_bootstrap
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Thu Nov 17 14:40:47 2016 clement xia
## Last update Thu Nov 17 15:20:06 2016 clement xia
##

CC	= gcc

NAME	= info_file

SRCS	=	main.c			\
		my_printf.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putnbr_base.c	\
		my_putstr.c		\
		my_strlen.c		\
		tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
