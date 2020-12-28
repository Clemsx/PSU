##
## Makefile for philo in /home/clemsx/Tek2/PSU/PSU_2016_philo
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Mon Mar 13 18:10:27 2017 clement xia
## Last update Fri Mar 17 17:55:47 2017 clement xia
##

CC	=	gcc

RM	=	rm -rf

SRCS	=	main.c		\
		error.c		\
		check.c		\
		action.c	\
		philo.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	philo

CFLAGS	+=	-Wall -Werror -Wextra
CFLAGS	+=	-I.
#CFLAGS	+=	-ansi -pedantic
LDFLAGS	=	-L./ -lriceferee -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(NAME)
	$(RM) *~
	$(RM) \#*#

fclean: clean
	rm -rf $(OBJS)

re: fclean all

.PHONY: clean fclean re all
