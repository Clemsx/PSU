/*
** functions2.c for functions2 in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 29 13:22:42 2017 Leo Blouard
** Last update Fri Jun  2 15:34:54 2017 Leo Blouard
*/

#include "client.h"

void		readServer(t_client *client)
{
  char		**cmd;
  char		**param;
  int		i;

  i = 0;
  if ((cmd = get_next_line(client->socket_id)) != NULL)
    {
      if (!strstr(cmd, "PRIVMSG"))
	printf("Server :%s\n", cmd);
      else
	{
	  param = parseParam(cmd);
	  while (param[i++])
	    printf("%s ", param[i]);
	}
    }
  return;
}
