##
## Makefile for Makefile in /home/clemsx/UPS/PSU_2016_my_printf_bootstrap
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Tue Nov  8 14:51:48 2016 clement xia
## Last update Tue Nov  8 16:35:53 2016 clement xia
##

NAME	=	libmy.a

SRCS	=	my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		sum_stdarg.c	\
		disp_stdarg.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS += -Wextra -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
