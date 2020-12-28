##
## Makefile for strace in /home/clemsx/Tek2/PSU/PSU_2016_strace
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Tue Apr 11 07:55:03 2017 clement xia
## Last update Thu Apr 13 21:34:31 2017 Leo Blouard
##

CC	=	gcc

RM	=	rm -rf

NAME	=	strace

SRCS	=	main.c			\
		src/check.c		\
		src/flags.c		\
		src/spill.c		\
		src/functions.c		\
		src/strace.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror

all:		$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) *~
		$(RM) src/*~
		$(RM) \#*#
		$(RM) src/\#*#

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
