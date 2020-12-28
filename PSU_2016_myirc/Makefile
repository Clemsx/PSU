##
## Makefile for Makefile in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc
## 
## Made by Leo Blouard
## Login   <lblouard@epitech.net>
## 
## Started on  Mon May 29 13:06:35 2017 Leo Blouard
## Last update Wed May 31 12:40:07 2017 Leo Blouard
##

CC	=	gcc

RM	=	rm -rf

SERVER	=	server

CLIENT	=	client

SRCS	=	serverDir/display.c		\
		serverDir/init_client.c		\
		serverDir/init_struct.c		\
		serverDir/server.c		\
		serverDir/main.c

SRCC	=	clientDir/check.c		\
		clientDir/client.c		\
		clientDir/main.c		\
		clientDir/cmd.c			\
		clientDir/display.c		\
		clientDir/display2.c		\
		clientDir/get_next_line.c	\
		clientDir/functions.c		\
		clientDir/functions2.c		\
		clientDir/parseCmd.c		\
		clientDir/init.c

OBJS	=	$(SRCS:.c=.o)

OBJC	=	$(SRCC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-I.
LDFLAGS	+=

all:		$(OBJS) $(OBJC)
		$(CC) -o $(SERVER) $(SRCS) $(LDFLAGS)
		$(CC) -o $(CLIENT) $(SRCC) $(LDFLAGS)

clean:
		$(RM) $(OBJS) $(OBJC)
		$(RM) *~
		$(RM) \#*#
		$(RM) serverDir/*~
		$(RM) serverDir/\#*#
		$(RM) clientDir/*~
		$(RM) clientDir/\#*#

fclean:		clean
		$(RM) $(CLIENT) $(SERVER)

re:		fclean all

.PHONY:		all clean fclean re
