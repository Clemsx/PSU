/*
** cmd.c for cmd in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue May 23 14:34:15 2017 Leo Blouard
** Last update Fri Jun  2 14:34:41 2017 Leo Blouard
*/

#include "client.h"

int     checkCmd(char *cmd, char **params, t_client *client)
{
  (void)params;
  if(strcmp(cmd, "/server") == 0)
    {
      printf("start server\n");
      return (1);
    }
  if (strcmp(cmd, "/nick") == 0)
    {
      if (params[0] != NULL)
	{
	  client->nickname = params[0];
	  printf("nickname changed\n");
	}
      else
	helpNick();
      return (1);
    }
  if (strcmp(cmd, "/join") == 0)
    {
      printf("start /join\n");
      return(1);
    }
  else if(strcmp(cmd, "/list") == 0)
    {
      printf("start /list\n");
      return (1);
    }
  else if(strcmp(cmd, "/part") == 0)
    {
      printf("start /part\n");
      return (1);
    }
  else if(strcmp(cmd, "/users") == 0)
    {
      printf("start /users\n");
      return (1);
    }
  else if(strcmp(cmd, "/names") == 0)
    {
      printf("start /names\n");
      return (1);
    }
  else if(strcmp(cmd, "/msg") == 0)
    {
      printf("start /msg\n");
      return (1);
    }
  else if (strcmp(cmd, "/quit") == 0)
    exit (0);
  return (0);
}
