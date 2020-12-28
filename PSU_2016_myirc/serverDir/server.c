/*
** server.c for irc in /home/clemsx/Tek2/PSU/PSU_2016_myirc/serverDir
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 22 23:48:11 2017 clement xia
** Last update Tue May 30 15:58:24 2017 Leo Blouard
*/

#include "server.h"

void			listen_me(int socket_id)
{
  if (listen(socket_id, SOMAXCONN) == -1)
    {
      close(socket_id);
      printf("%d - %s\n", errno, strerror(errno));
      exit(84);
    }
}

int			init_slt(t_serv *serv, int socket_id, fd_set *bigfd)
{
  FD_ZERO(bigfd);
  FD_SET(socket_id, bigfd);
  if (select(serv->fd_max + 1, bigfd, NULL, NULL, NULL) == -1)
    {
      close(socket_id);
      return (-1);
    }
  return (0);
}

int			init_server(int port)
{
  int			le;
  int			socket_id;
  struct sockaddr_in	sock_addr;

  le = 1;
  if ((socket_id = socket(AF_INET, SOCK_STREAM, 0)) != -1)
    {
      sock_addr.sin_port = htons(port);
      sock_addr.sin_addr.s_addr = INADDR_ANY;
      sock_addr.sin_family = AF_INET;
      setsockopt(socket_id, SOL_SOCKET, SO_REUSEADDR, &le, sizeof(int));
      if (bind(socket_id, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) != -1)
	listen_me(socket_id);
    }
  else
    {
      close(socket_id);
      printf("%d - %s\r\n", errno, strerror(errno));
      exit(84);
    }
  return (socket_id);
}

void		startServer(int port)
{
  t_serv	serv;
  fd_set	bigfd;
  int		socket_id;

  socket_id = init_server(port);
  semi_init_server(&serv, socket_id);
  while (1)
    {
      if (init_slt(&serv, socket_id, &bigfd) == -1)
	return ;
      if (FD_ISSET(socket_id, &bigfd) != 0)
	{
	  init_accept(&serv, socket_id, &bigfd);
	  printf("FD ISSET OK\r\n");
	}
    }
  close(socket_id);
}
