##
## Makefile for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Mon May 15 12:28:12 2017 clement xia
## Last update Sat May 20 16:08:05 2017 clement xia
##

NAME	=	server

CC	=	gcc

SRCS	=	main.c		\
		server.c	\
		client.c	\
		manager.c	\
		cmd.c		\
		tool.c		\
		parsing.c	\
		cmd2.c		\
		cmd3.c		\
		port.c		\
		retr.c		\
		stor.c		\
		get_next_line.c	\
		list.c

RM      =	rm -f

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
