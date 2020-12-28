/*
** retr.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu May 18 10:51:23 2017 clement xia
** Last update Sun May 21 11:41:09 2017 clement xia
*/

#include "my_ftp.h"

void	dl_retr(t_custom *custom, char *file, int new_fd)
{
  int	fd_file;
  char	new_file[4096];

  if ((fd_file = open(file, O_RDONLY)) == -1)
    dprintf(custom->socket_id, "550 Fail to open the file\r\n");
  else if (access(file, R_OK | F_OK) == -1)
    dprintf(custom->socket_id, "550 Fail to open the file\r\n");
  else
    {
      while (read(fd_file, new_file, 4096) != 0)
	{
	  write(new_fd, new_file, strlen(new_file));
	  memset(new_file, 0, 4096);
	}
      close(fd_file);
      close(custom->pass_socket);
      dprintf(custom->socket_id, "226 Transfer done\r\n");
    }
}

int	stop_block_me(t_custom *custom)
{
  struct sockaddr_in	radd;
  unsigned int		le;
  int			fd;

  le = sizeof(struct sockaddr_in);
  fd = accept(custom->pass_socket, (struct sockaddr *)&radd, &le);
  return (fd);
}

int	retr(t_custom *custom, char *cmd)
{
  int	new_fd;
  char	*file;
  int	new_pid;

  if (custom->mode == 0)
    dprintf(custom->socket_id, "425 Use PORT or PASV first\r\n");
  else
    {
      if ((file = get_parameter(cmd)) != NULL)
	{
	  dprintf(custom->socket_id,
	      "150 File status okay, about to open data connection\r\n");
	  if ((new_pid = fork()) == 0)
	    {
	      new_fd = stop_block_me(custom);
	      dl_retr(custom, file, new_fd);
	      exit(1);
	    }
	}
      else
	dprintf(custom->socket_id, "550 Fail to open the file\r\n");
    }
  return (1);
}
