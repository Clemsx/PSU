/*
** init.c for init in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue May 23 14:35:16 2017 Leo Blouard
** Last update Wed May 31 18:01:25 2017 Leo Blouard
*/

#include "client.h"

t_client		*initClient(t_client *client, int port)
{
  client->connected = 0;
  client->socket_id = -1;
  client->port = port;
  client->nickname = NULL;
  client->channel = -1;
  return (client);
}

void			initServer(t_client *client)
{
  struct protoent       *proto;

  proto = getprotobyname("TCP");
  client->socket_id = socket(AF_INET, SOCK_STREAM, proto->p_proto);
  client->s_address.sin_family = AF_INET;
  client->s_address.sin_addr.s_addr = inet_addr(client->ip);
  client->s_address.sin_port = htons(client->port);
  if (connect(client->socket_id, (struct sockaddr *) &client->s_address,
	      sizeof(client->s_address)) == -1)
    {
      printf("Connection to the server failed\n");
      return;
    }
  client->connected = 1;
}

void			initLoop(t_client *client)
{
  FD_ZERO(&client->read);
  FD_SET(0, &client->read);
  if (client->socket_id != -1)
    FD_SET(client->socket_id, &client->read);
  if (select((client->socket_id != -1 ? client->socket_id + 1 : 1),
	     &client->read, NULL, NULL, NULL) == -1)
    {
      printf("Init loop failed\n");
      exit (84);
    }
  getFunctions(client->socket_id, client->read, client);
}

void			init(int port, char *ip)
{
  t_client		*client;

  client = malloc(sizeof(t_client *));
  client = initClient(client, port);
  client->ip = ip;
  helpServer();
  while (1)
    initLoop(client);
}
