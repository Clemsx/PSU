##
## Makefile for Makefile in /home/clemsx/PSU/PSU_2016_my_ls
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Thu Nov 17 17:18:21 2016 clement xia
## Last update Thu Nov 24 18:15:41 2016 clement xia
##

CC	= gcc

NAME	= my_ls

SRCS	=	main.c			\
		my_printf/my_printf.c		\
		my_printf/my_putchar.c		\
		my_printf/my_putnbr_base.c	\
		my_printf/my_putstr.c		\
		my_printf/my_strlen.c		\
		my_printf/my_put_nbr.c		\
		my_printf/tools.c			\
		my_strcmp.c		\
		my_ls.c			\
		my_ls2.c		\
		my_ls_l.c		\
		my_strncpy.c		\
		my_ls_r.c		\
		my_ls_d.c		\
		my_strcpy.c

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
