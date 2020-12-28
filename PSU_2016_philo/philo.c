/*
** philo.c for philo in /home/lblouard/delivery/Annee2/PSU/PSU_2016_philo
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Mar 14 15:47:52 2017 Leo Blouard
** Last update Thu Mar 16 19:22:52 2017 Leo Blouard
*/

#include "extern.h"
#include "philo.h"

void			init_philo(pthread_mutex_t *chopstick)
{
  t_philo		*philo;
  int			i;
  int			j;

  i = 0;
  j = 0;
  if ((philo = malloc(sizeof(t_philo) * (nbphilo + 1))) == NULL)
    exit (84);
  while (i < nbphilo)
    {
      philo[i].left_hand = &chopstick[i];
      philo[i].right_hand = &chopstick[(i + 1) % nbphilo];
      philo[i].nbloop = 0;
      philo[i].action = 0;
      pthread_create(&philo[i].thread, NULL, action_philo, &philo[i]);
      i++;
    }
  while (j < nbphilo)
    {
      pthread_join(philo[j].thread, NULL);
      j++;
    }
  free(philo);
}

void			init()
{
  pthread_mutex_t	*chopsticks;
  int			i;

  i = 0;
  chopsticks = malloc(sizeof(pthread_mutex_t) * nbphilo);
  while (i < nbphilo)
    {
      pthread_mutex_init(&chopsticks[i], NULL);
      i++;
    }
  init_philo(chopsticks);
  free(chopsticks);
}
