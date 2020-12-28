##
## Makefile for Makefile in /home/clemsx/PSU/PSU_2016_my_ls
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Thu Nov 17 17:18:21 2016 clement xia
## Last update Tue Nov 22 18:20:58 2016 clement xia
##

CC	= gcc

NAME	= my_exec

SRCS	=	main.c			\
		my_printf.c		\
		my_putchar.c		\
		my_putnbr_base.c	\
		my_putstr.c		\
		my_strlen.c		\
		my_put_nbr.c		\
		tools.c			\
		my_str_to_wordtab.c	\
		my_strncpy.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Werror -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
