/*
** stor.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu May 18 20:36:33 2017 clement xia
** Last update Mon May 22 14:44:07 2017 clement xia
*/

#include "my_ftp.h"

int	stor(t_custom *custom, char *cmd)
{
  UNUSED(cmd);
  if (custom->mode == 0)
    dprintf(custom->socket_id, "425 Use PORT or PASV first\r\n");
  return (1);
}
