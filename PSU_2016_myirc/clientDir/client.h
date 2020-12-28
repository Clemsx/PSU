/*
** client.h for client in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 22 17:04:52 2017 Leo Blouard
** Last update Fri Jun  2 14:35:21 2017 Leo Blouard
*/

#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct		s_msg
{
  char			*from;
  char			*to;
  char			*message;
}			t_msg;

typedef struct		s_client
{
  int			connected;
  int			port;
  char			*ip;
  int			socket_id;
  struct sockaddr_in	s_address;
  fd_set		read;
  char			*nickname;
  int			channel;
  t_msg			*msg;
  char			cmd[9];
  char			*writeServer;
  char			*writeClient;
}			t_client;

/* init.c */
t_client		*initClient(t_client *client, int port);
void			init(int port, char *ip);
void			initServer(t_client *client);
void			initLoop(t_client *client);

/* fucntions.c */
void			loop(int socket_id, int port);
void			buffServer(t_client *client, int socket_id);
void			buffClient(t_client *client);
void			getFunctions(int socket_id, fd_set read, t_client *client);

/* functions2.c */
void		readServer(t_client *client);

/* display.c */
void		helpme();
void		helpNick();
void		helpServer();
void		helpList();
void		helpJoin();

/* display2.c */
void		helpPart();
void		helpUsers();
void		helpName();
void		helpMsg();
void		helpAccept();

/* cmd.c */
int		checkCmd(char *cmd, char **params, t_client *client);

/* check.c */
int		checkPort(char *port);
int		checkParam(char *ip, char *port, t_client *client);

/* parseCmd.c */
char			**parse(char *cmd);
char			**parseParam(char *cmd);
#endif
