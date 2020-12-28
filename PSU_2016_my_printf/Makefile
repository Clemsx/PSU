##
## Makefile for Makefile in /home/clemsx/UPS/PSU_2016_my_printf
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Thu Nov 10 13:47:26 2016 clement xia
## Last update Sat Nov 12 10:43:25 2016 clement xia
##

SRCS	=	my_putchar.c		\
		my_put_nbr.c		\
		my_strlen.c		\
		my_printf.c		\
		my_putnbr_base.c	\
		my_putstr.c		\
		tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Werror -Wall -Wextra

NAME	= libmy.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
