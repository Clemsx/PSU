/*
** server.h for server in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/serverDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 22 16:50:24 2017 Leo Blouard
** Last update Tue May 30 15:54:13 2017 Leo Blouard
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/time.h>
#include <sys/select.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

typedef struct		s_chan
{
  int			id_chan;
  char			title[500];
}			t_chan;

typedef struct		s_user
{
  int			id_user;
  int			socket_id;
  char			*nick;
}			t_user;

typedef struct          s_serv
{
  int                   port;
  int			socket_id;
  t_user		user[50];
  t_chan		chan[50];
  int			nb_user;
  int			nb_chan;
  int			fd_max;
}			t_serv;

typedef struct          s_client
{
  int                   sc_id;
  char                  *path;
  struct sockaddr_in    sc_address;
  socklen_t             len;
}			t_client;

/* display.c */
void	helpme();

/* functions.c */
int	verifParam(char *port);

/* server.c */
int	init_server(int port);
void	startServer(int port);

/* init_struct.c */
void	semi_init_server(t_serv *server, int bigfd);

/* init_client.c */
void    init_accept(t_serv *server, int socket_id, fd_set *bigfd);

#endif /* !SERVER_H_ */
