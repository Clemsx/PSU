/*
** check.c for check in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue May 23 14:54:11 2017 Leo Blouard
** Last update Wed May 31 17:54:52 2017 Leo Blouard
*/

#include "client.h"

int             checkPort(char *port)
{
  int           i;

  i = 0;

  if (strlen(port) != 4)
    return (-1);
  while (port[i])
    {
      if (port[i] >= 48 && port[i] <= 57)
	i++;
      else
	return (-1);
    }
  return (atoi(port));
}

int		checkParam(char *ip, char *port, t_client *client)
{
  if (ip != NULL && port != NULL)
    {
      client->ip = ip;
      client->port = atoi(port);
      return (1);
    }
  return (0);
}
