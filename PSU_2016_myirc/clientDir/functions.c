/*
** functions.c for functions in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue May 23 14:40:17 2017 Leo Blouard
** Last update Fri Jun  2 14:36:06 2017 Leo Blouard
*/

#include "client.h"


void		connectClient(t_client *client)
{
  char		*cmd;
  char		**newCmd;
  char		**params;

  cmd = malloc(2048);
  newCmd = malloc(2048);
  if ((cmd = get_next_line(1)) == NULL)
    return;
  if (cmd[0] != '/' || strlen(cmd) <= 9)
    return;
  newCmd = parse(cmd);
  params = malloc(2048);
  if (((params = parseParam(cmd)) == NULL)
       ||(checkParam(params[0], params[1], client) == 0))
    {
      helpServer();
      return;
    }
  if (strcmp(newCmd[0], "/server") == 0)
    initServer(client);
  if (client->connected == 1)
    printf("USER connected\n");
  return;
}

void		exec(t_client *client, int socket_id)
{
  char		*cmd1;
  char		**newcmd;
  char		**params;
  int		i;
  
  i = 0;
  cmd1 = malloc(4048);
  cmd1 = get_next_line(1);
  if (cmd1 == NULL)
    return;
  newcmd = malloc(4048);
  newcmd = parse(cmd1);
  params = malloc(4048);
  params = parseParam(cmd1);
  while (newcmd[i])
    {
      if (checkCmd(newcmd[i], params, client) != 1)
	{
	  printf("Wrong cmd\n");
	  return;
	}
      i++;
    }
  (void)client;
  (void)socket_id;
}


void		getFunctions(int socket_id, fd_set read, t_client *client)
{
  if (FD_ISSET(socket_id, &read))
    readServer(client);
  if (FD_ISSET(0, &read))
    {
      if (client->connected == 0)
	connectClient(client);
      else
	exec(client, socket_id);
    }
}
