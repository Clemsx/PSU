##
## Makefile for Makefile in /home/lblouard/delivery/Annee2/PSU/PSU_2016_ftrace
## 
## Made by Leo Blouard
## Login   <lblouard@epitech.net>
## 
## Started on  Mon May  1 16:14:39 2017 Leo Blouard
## Last update Sun May  7 18:46:39 2017 Kirill Elizarov
##

CC	=	gcc

RM	=	rm -rf

NAME	=	ftrace

SRCS	=	srcs/main.c		\
		srcs/function.c		\
		srcs/ftrace.c		\
		srcs/spill.c		\
		srcs/check.c		\
		srcs/elf64.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-Iinclude/
LDFLAGS	+=

all:		$(OBJS)
		$(CC) -o $(NAME) $(SRCS) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) *~
		$(RM) \#*#

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
