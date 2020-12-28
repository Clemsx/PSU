##
## Makefile for nmobjdump in /home/clemsx/Tek2/PSU/PSU_2016_nmobjdump
## 
## Made by clement xia
## Login   <clemsx@epitech.net>
## 
## Started on  Sat Feb 25 15:41:29 2017 clement xia
## Last update Sat Feb 25 15:46:05 2017 clement xia
##

CC		= gcc

NM_NAME		= my_nm

OBJ_NAME	= my_objdump

NM_SRCS		= nm/main.c

OBJ_SRCS	= objdump/main.c

NM_OBJS		= $(NM_SRCS:.c=.o)

OBJ_OBJS	= $(OBJ_SRCS:.c=.o)

all:	$(NM_NAME) $(OBJ_NAME)

$(NM_NAME): 	$(NM_OBJS)
		$(CC) -o $(NM_NAME) $(NM_OBJS)

$(OBJ_NAME):	$(OBJ_OBJS)
		$(CC) -o $(OBJ_NAME) $(OBJ_OBJS)

clean:
	rm -rf $(NM_NAME) $(OBJ_NAME)

fclean: clean
	rm -rf $(NM_OBJS) $(OBJ_OBJS)

re:	fclean all

.PHONY: all clean fclean re
