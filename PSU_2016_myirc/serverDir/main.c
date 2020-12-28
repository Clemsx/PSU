/*
** main.c for main in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/serverDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 22 16:48:14 2017 Leo Blouard
** Last update Mon May 29 13:33:24 2017 Leo Blouard
*/

#include "server.h"

int	main(int argc, char **argv)
{
  if (argc != 2)
    {
      helpme();
      return (0);
    }
  else
    {
      if (strcmp(argv[1], "--help") == 0)
	{
	  helpme();
	  return (0);
	}
      startServer(atoi(argv[1]));
    }
  return (0);
}
