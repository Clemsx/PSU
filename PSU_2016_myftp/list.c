/*
** list.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Sat May 20 16:06:23 2017 clement xia
** Last update Sun May 21 11:34:30 2017 clement xia
*/

#include "my_ftp.h"

void	display_list(t_custom *custom, char *cmd)
{
  char	tmp[4096];
  char	*file;

  if ((file = get_parameter(cmd)) == NULL)
    {
      system("ls -ln");
    }
  else
    {
      sprintf(tmp, "ls -ln %s", file);
      system(tmp);
    }
  dprintf(custom->socket_id, "226 Transfer done\r\n");
}

int	list(t_custom *custom, char *cmd)
{
  int			new_pid;
  int			fd;

  if (custom->mode == 0)
    dprintf(custom->socket_id, "425 Use PORT or PASV first\r\n");
  else
    {
      dprintf(custom->socket_id,
	      "150 File status okay, about to open data connection\r\n");
      if ((new_pid = fork()) == 0)
	{
	  fd = stop_block_me(custom);
	  dup2(fd, 1);
	  display_list(custom, cmd);
	  dup2(1, fd);
	  exit(1);
	}
    }
  return (1);
}
