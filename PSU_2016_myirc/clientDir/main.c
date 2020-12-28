/*
** main.c for main in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 22 16:59:29 2017 Leo Blouard
** Last update Tue May 23 15:12:11 2017 Leo Blouard
*/

#include "client.h"

int		main(int argc, char **argv)
{
  if (argc != 3)
    {
      helpme();
      exit (84);
    }
  else
    {
      if (checkPort(argv[2]) < 0)
	exit (84);
      init(atoi(argv[2]), argv[1]);
    }
  return (0);
}
