/*
** manager.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 19:26:02 2017 clement xia
** Last update Sun May 21 11:31:36 2017 clement xia
*/

#include "my_ftp.h"

t_custom	*init_custom(t_client *client, char *path)
{
  t_custom	*custom;

  if ((custom = malloc(sizeof(t_custom))) == NULL)
    {
      return (NULL);
    }
  custom->connected = 0;
  custom->logged = 0;
  custom->path = path;
  custom->path_parent = path;
  custom->socket_id = client->socket_id;
  custom->pass_socket = 0;
  custom->pass_client = 0;
  custom->mode = 0;
  custom->port = 0;
  custom->ip = replace_ip(inet_ntoa(client->client_add.sin_addr));
  return (custom);
}

int		invite_cmd(t_client *client, char *path)
{
  int		tmp;
  t_custom	*custom;
  char		*cmd;

  custom = init_custom(client, path);
  dprintf(custom->socket_id, "220 connection to FTP\r\n");
  while (1)
    {
      cmd = get_next_line(custom->socket_id);
      if (strlen(cmd) > 0)
	{
	  if (custom->connected == 0)
	    {
	      if (is_connected(custom, cmd) == 2)
		dprintf(custom->socket_id, "530 Log-in with USER then PASS\r\n");
	    }
	  else
	    if ((tmp = connected_cmd(custom, cmd)) == 0)
	      dprintf(custom->socket_id, "500 Unknown commands\r\n");
	    else if (tmp == 1)
	      return (1);
	}
    }
}
