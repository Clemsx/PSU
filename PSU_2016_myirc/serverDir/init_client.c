/*
** init_client.c for irc in /home/clemsx/Tek2/PSU/PSU_2016_myirc/serverDir
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 22 22:30:45 2017 clement xia
** Last update Mon May 29 13:16:47 2017 Leo Blouard
*/

#include "server.h"

void			init_accept(t_serv *server, int socket_id, fd_set *bigfd)
{
  int			new_sock;
  struct sockaddr_in	sock_in;
  unsigned int		le;

  le = sizeof(sock_in);
  new_sock = accept(socket_id, (struct sockaddr *)&sock_in, &le);
  if (new_sock != -1)
    {
      FD_SET(new_sock, bigfd);
      if (new_sock > server->fd_max)
	server->fd_max = new_sock;
      else
	server->fd_max = server->fd_max;
      server->user[server->nb_user].socket_id = new_sock;
      server->user[server->nb_user].id_user = server->nb_user;
      server->user[server->nb_user].nick = NULL;
      server->nb_user = server->nb_user + 1;
    }
  printf("User number %d connected\n", server->nb_user);
}
