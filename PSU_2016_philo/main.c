/*
** main.c for philo in /home/clemsx/Tek2/PSU/PSU_2016_philo
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Mar 13 18:10:35 2017 clement xia
** Last update Thu Mar 16 19:20:23 2017 Leo Blouard
*/

#include "extern.h"
#include "philo.h"

int	main(int ac, char **av)
{
  RCFStartup(ac, av);
  if (ac == 5 && (check_param(av) == 1))
    {
      check_nbr(av);
      init();
    }
  else
    {
      printerr();
      exit(84);
    }
  RCFCleanup();
  return (0);
}
