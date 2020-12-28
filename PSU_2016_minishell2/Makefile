##
## Makefile for Makefile in /home/clemsx/PSU/PSU_2016_my_ls
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Thu Nov 17 17:18:21 2016 clement xia
## Last update Wed Dec 14 16:52:57 2016 clement xia
##

CC	= gcc

NAME	= mysh

SRCS	=	main.c				\
		fts/my_printf.c			\
		fts/my_putchar.c		\
		fts/my_putnbr_base.c		\
		fts/my_putstr.c			\
		fts/my_strlen.c			\
		fts/my_put_nbr.c		\
		fts/tools.c			\
		fts/get_next_line.c		\
		fts/my_strcmp.c			\
		fts/builtins.c			\
		fts/my_str_to_wordtab.c		\
		fts/my_strcat.c			\
		fts/my_strncpy.c		\
		fts/my_env.c			\
		fts/my_setenv.c			\
		fts/my_strcpy.c			\
		fts/unset_env.c			\
		fts/my_cd.c

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
