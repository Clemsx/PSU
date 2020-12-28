/*
** main.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 12:29:20 2017 clement xia
** Last update Sun May 21 11:41:25 2017 clement xia
*/

#include "my_ftp.h"

int	main(int ac, char **av)
{
  t_server	server;
  t_client	client;

  if (ac != 3)
    {
      printf("Usage : ./server port path\n");
      return (0);
    }
  if (start_server(&server, &client, atoi(av[1]), av[2]) == -1)
    {
      printf("Error start server\n");
      return (0);
    }
  return (0);
}
