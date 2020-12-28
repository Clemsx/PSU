/*
** tool.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 22:31:23 2017 clement xia
** Last update Wed May 17 18:15:43 2017 clement xia
*/

#include "my_ftp.h"

char	*replace_ip(char *ip)
{
  int	i;

  i = 0;
  while (ip[i])
    {
      if (ip[i] == '.')
	ip[i] = ',';
      i++;
    }
  return (ip);
}

int	is_connected(t_custom *custom, char *cmd)
{
  if (((strcmp(get_cmd(cmd), "USER") != 0) &&
       (strcmp(get_cmd(cmd), "PASS") != 0)))
    return (2);
  else if (custom->logged == 0 && strcmp(get_cmd(cmd), "PASS") == 0)
    dprintf(custom->socket_id, "503 You must log-in first\r\n");
  else
    {
      list_cmd(cmd, custom);
      list_cmd2(cmd, custom);
    }
  return (0);
}

int	connected_cmd(t_custom *custom, char *cmd)
{
  if (strcmp(get_cmd(cmd), "QUIT") == 0)
    {
      good_bye(custom);
      return (1);
    }
  else
    {
      if (list_cmd(cmd, custom) == 1)
	return (2);
      else if (list_cmd2(cmd, custom) == 1)
	return (2);
    }
  return (0);
}
