/*
** server.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 13:17:42 2017 clement xia
** Last update Sun May 21 11:32:53 2017 clement xia
*/

#include "my_ftp.h"

int		init_socket(t_server *server)
{
  struct protoent	*proto;

  proto = getprotobyname("TCP");
  server->socket_id = socket(AF_INET, SOCK_STREAM, proto->p_proto);
  return (server->socket_id);
}

t_server	*init_server(t_server *server, int port)
{
  if ((server = malloc(sizeof(t_server))) == NULL)
    return (NULL);
  server->server_add.sin_family = AF_INET;
  server->server_add.sin_addr.s_addr = INADDR_ANY;
  server->server_add.sin_port = htons(port);
  server->socket_id = -1;
  return (server);
}

void	init_while(t_server *server, t_client *client, char *path)
{
  int	pid;

  while (1)
    {
      if ((client->socket_id = accept(server->socket_id,
				      (struct sockaddr *)&client->client_add, &client->size)) != -1)
	{
	  if ((pid = fork()) == 0)
	    invite_cmd(client, path);
	  else
	    close(client->socket_id);
	  if (pid == 0)
	    return ;
	}
    }
  close(server->socket_id);
}

int	start_server(t_server *server, t_client *client, int port, char *path)
{
  server = init_server(server, port);
  client = init_client(client);
  init_socket(server);
  if (server->socket_id == -1)
    return (-1);
  if (bind(server->socket_id, (struct sockaddr *)&server->server_add,
	   sizeof(struct sockaddr)) == -1)
    {
      if (setsockopt(server->socket_id, SOL_SOCKET,
		     SO_REUSEADDR, &(int){1}, sizeof(int)) == -1)
	return (-1);
    }
  if (listen(server->socket_id, SOMAXCONN) == -1)
    return (-1);
  init_while(server, client, path);
  return (0);
}
