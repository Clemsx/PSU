/*
** functions.c for functions in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/serverDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 22 16:52:39 2017 Leo Blouard
** Last update Mon May 22 18:36:35 2017 clement xia
*/

#include "server.h"

int	verifParam(char *port)
{
  int           i;

  i = 0;
  while (port[i])
    {
      if (port[i] >= 48 && port[i] <= 57)
	i++;
      else
	return (-1);
    }
  return (0);
}
