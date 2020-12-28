/*
** client.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 17:02:08 2017 clement xia
** Last update Mon May 15 19:00:44 2017 clement xia
*/

#include "my_ftp.h"

t_client	*init_client(t_client *client)
{
  if ((client = malloc(sizeof(t_client *))) == NULL)
    return (NULL);
  client->socket_id = -1;
  client->size = sizeof(struct sockaddr);
  return (client);
}
