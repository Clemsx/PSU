/*
** check.c for check in /home/lblouard/delivery/Annee2/PSU/PSU_2016_philo
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Mar 14 16:25:46 2017 Leo Blouard
** Last update Thu Mar 16 14:18:36 2017 Leo Blouard
*/

#include "extern.h"
#include "philo.h"

void    check_nbr(char **av)
{
  int   i;

  i = 0;
  while (av[i] != NULL)
    {
      if (strcmp(av[1],"-p") == 0)
	{
	  nbphilo = atoi(av[2]);
	  loop = atoi(av[4]);
	}
      else if (strcmp(av[1],"-e") == 0)
	{
	  loop = atoi(av[2]);
	  nbphilo = atoi(av[4]);
	}
      else
	printerr();
      i++;
    }
}

int     check_param(char **av)
{
  if ((strcmp(av[1], "-p") != 0) && (strcmp(av[1], "-e") != 0))
    return (0);
  if ((strcmp(av[3], "-p") != 0) && (strcmp(av[3], "-e") != 0))
    return (0);
  else
    if (atoi(av[2]) < 0 || atoi(av[4]) < 0)
      return (0);
  return (1);
}

int	random_nb(int nb)
{
  int	i;

  srand(time(0));
  i = rand() % nb;
  i++;
  return (i);
}
 
