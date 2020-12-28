/*
** cmd2.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue May 16 20:02:23 2017 clement xia
** Last update Sat May 20 18:35:31 2017 clement xia
*/

#include "my_ftp.h"

int	cdup(t_custom *custom)
{
  if (chdir("../") < 0)
    dprintf(custom->socket_id, "550 can't go to parent directory\r\n");
  dprintf(custom->socket_id, "200 Successfully changed to parent dir\r\n");
  return (1);
}

int	pwd(t_custom *custom)
{
  char	path[1024];

  chdir(custom->path);
  if (getcwd(path, 1024) == NULL)
    {
      dprintf(custom->socket_id, "500 can't get the path\r\n");
    }
  dprintf(custom->socket_id, "257 \"%s\"\r\n", path);
  return (1);
}

int	help(t_custom *custom)
{
  dprintf(custom->socket_id, "214 Available commands on FTP\r\n");
  dprintf(custom->socket_id, " USER PASS CWD CDUP QUIT DELE PWD PASV");
  dprintf(custom->socket_id, " PORT HELP NOOP RETR STOR LIST\n");
  dprintf(custom->socket_id, "214 HELP OK\r\n");
  return (1);
}

int	cwd(t_custom *custom, char *cmd)
{
  char	*tmp;

  tmp = get_parameter(cmd);
  if (tmp == NULL)
    dprintf(custom->socket_id, "501 problems with arguments\r\n");
  else if (chdir(tmp) < 0)
    dprintf(custom->socket_id, "550 can't change directory\r\n");
  else
    dprintf(custom->socket_id, "250 Successfully change directory\r\n");
  return (1);
}

int	noop(t_custom *custom)
{
  dprintf(custom->socket_id, "200 NOOP nothings good\r\n");
  return (1);
}
