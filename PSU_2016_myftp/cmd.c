/*
** cmd.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 20:25:30 2017 clement xia
** Last update Sun May 21 11:23:51 2017 clement xia
*/

#include "my_ftp.h"

int	login(t_custom *custom, char *cmd)
{
  if (custom->connected == 1)
    dprintf(custom->socket_id, "530 You can't change user\r\n");
  else
    {
      if ((custom->log = get_parameter(cmd)) == NULL)
	return (1);
      custom->logged = 1;
      dprintf(custom->socket_id, "331 Nice now need password\r\n");
    }
  return (1);
}

int	password(t_custom *custom)
{
  if (custom->connected == 1)
    {
      dprintf(custom->socket_id, "230 Already logged\r\n");
      return (1);
    }
  if (strcmp(custom->log, "Anonymous") == 0)
    {
      dprintf(custom->socket_id, "230 Login successful :D\r\n");
      custom->connected = 1;
    }
  else
    {
      custom->logged = 0;
      free(custom->log);
      custom->log = NULL;
      dprintf(custom->socket_id, "530 Login incorrect\r\n");
    }
  return (1);
}

int	good_bye(t_custom *custom)
{
  dprintf(custom->socket_id, "221 CYA\r\n");
  free(custom->log);
  free(custom->path);
  free(custom->path_parent);
  free(custom);
  exit (1);
  return (1);
}

int	list_cmd(char *cmd, t_custom *custom)
{
  if (strcmp(get_cmd(cmd), "USER") == 0)
    return (login(custom, cmd));
  else if (strcmp(get_cmd(cmd), "PASS") == 0)
    return (password(custom));
  else if (strcmp(get_cmd(cmd), "QUIT") == 0)
    return (good_bye(custom));
  else if (strcmp(get_cmd(cmd), "CWD") == 0)
    return (cwd(custom, cmd));
  else if (strcmp(get_cmd(cmd), "CDUP") == 0)
    return (cdup(custom));
  else if (strcmp(get_cmd(cmd), "DELE") == 0)
    return (dele(custom, cmd));
  else if (strcmp(get_cmd(cmd), "PWD") == 0)
    return (pwd(custom));
  return (0);
}

int	list_cmd2(char *cmd, t_custom *custom)
{
  if (strcmp(get_cmd(cmd), "PASV") == 0)
    return (pasv(custom));
  else if (strcmp(get_cmd(cmd), "PORT") == 0)
    return (port(custom));
  else if (strcmp(get_cmd(cmd), "HELP") == 0)
    return (help(custom));
  else if (strcmp(get_cmd(cmd), "NOOP") == 0)
    return (noop(custom));
  else if (strcmp(get_cmd(cmd), "RETR") == 0)
    return (retr(custom, cmd));
  else if (strcmp(get_cmd(cmd), "STOR") == 0)
    return (stor(custom, cmd));
  else if (strcmp(get_cmd(cmd), "LIST") == 0)
    return (list(custom, cmd));
  return (0);
}

