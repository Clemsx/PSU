##
## Makefile for Makefile in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
## 
## Made by Leo Blouard
## Login   <lblouard@epitech.net>
## 
## Started on  Tue Jan 24 11:09:15 2017 Leo Blouard
## Last update Tue Feb  7 02:06:52 2017 Leo Blouard
##

CC	=	gcc

NAME	=	malloc

LIBMY	=	libmy_malloc.so

SRCS    =       malloc.c		\
		realloc.c		\
		free.c			\
		show_alloc_mem.c	\
		calloc.c

OBJS    =       $(SRCS:.c=.o)

SHARE	=	-shared

CFLAGS  +=      -Wall -Wextra -Werror

LDFLAGS +=

RM      =       rm -f

all:	$(OBJS)
	$(CC) -O0 -g -W $(CFLAGS) $(SHARE) -fPIC $(SRCS) -o $(LIBMY)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBMY)
	$(RM) *~
	$(RM) \#*#

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
