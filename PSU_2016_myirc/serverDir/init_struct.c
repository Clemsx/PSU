/*
** init_struct.c for irc in /home/clemsx/Tek2/PSU/PSU_2016_myirc/serverDir
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 22 22:18:40 2017 clement xia
** Last update Mon May 22 22:20:55 2017 clement xia
*/

#include "server.h"

void	semi_init_server(t_serv *server, int socket_id)
{
  server->nb_user = 0;
  server->nb_chan = 0;
  server->fd_max = socket_id;
}
