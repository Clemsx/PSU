/*
** cmd3.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue May 16 22:08:33 2017 clement xia
** Last update Sun May 21 11:33:24 2017 clement xia
*/

#include "my_ftp.h"

int	init_pasv(t_custom *custom)
{
  int			sock;
  struct sockaddr_in	sock_in;
  int			bool;
  unsigned int		le;

  le = sizeof(sock_in);
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  bool = 1;
  sock_in.sin_family = AF_INET;
  sock_in.sin_addr.s_addr = INADDR_ANY;
  sock_in.sin_port = htons(0);
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &bool, sizeof(int)) != 0)
    if (bind(sock, (struct sockaddr *)&sock_in, sizeof(sock_in)) == -1)
      {
	close(sock);
	return (-1);
      }
  if (listen(sock, SOMAXCONN) == -1)
    return (-1);
  getsockname(sock, (struct sockaddr *)&sock_in, &le);
  custom->port = ntohs(sock_in.sin_port);
  custom->mode = 1;
  custom->pass_socket = sock;
  return (sock);
}

int	pasv(t_custom *custom)
{
  int	port1;
  int	port2;

  if (init_pasv(custom) != -1)
    {
      port1 = custom->port / 256;
      port2 = custom->port % 256;
      dprintf(custom->socket_id, "227 Entering passive mode (%s,%d,%d)\r\n",
	      custom->ip, port1, port2);
      printf("Port for PASV : %d\n", (port1 * 256) + port2);
    }
  else
    dprintf(custom->socket_id, "500 Failed to entering passive mode\r\n");
  return (1);
}

int	dele(t_custom *custom, char *cmd)
{
  char	*tmp;

  if ((tmp = get_parameter(cmd)) == NULL)
    dprintf(custom->socket_id, "501 problems with arguments\r\n");
  else if (remove(tmp) < 0)
    dprintf(custom->socket_id, "521 Deleting file failed\r\n");
  else
    dprintf(custom->socket_id, "250 File deleted\r\n");
  return (1);
}
