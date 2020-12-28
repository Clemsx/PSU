/*
** action.c for action in /home/lblouard/delivery/Annee2/PSU/PSU_2016_philo
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Mar 14 16:59:52 2017 Leo Blouard
** Last update Sun Mar 19 14:57:12 2017 Leo Blouard
*/

#include "extern.h"
#include "philo.h"

void		eat(t_philo *philo)
{
  pthread_mutex_trylock(philo->left_hand);
  pthread_mutex_trylock(philo->right_hand);
  lphilo_take_chopstick(philo->left_hand);
  lphilo_take_chopstick(philo->right_hand);
  lphilo_eat();
  philo->action = 1;
  philo->nbloop++;
  usleep(5);
  lphilo_release_chopstick(philo->left_hand);
  lphilo_release_chopstick(philo->right_hand);
  pthread_mutex_unlock(philo->left_hand);
  pthread_mutex_unlock(philo->right_hand);
}

void		thinks(t_philo *philo)
{
  if (nbphilo % 2 == 0)
    {
      pthread_mutex_trylock(philo->left_hand);
      lphilo_take_chopstick(philo->left_hand);
      philo->action = 2;
      lphilo_think();
      usleep(5);
      lphilo_release_chopstick(philo->left_hand);
      pthread_mutex_unlock(philo->left_hand);
    }
  else
    {
      pthread_mutex_trylock(philo->right_hand);
      lphilo_take_chopstick(philo->right_hand);
      philo->action = 2;
      lphilo_think();
      usleep(5);
      lphilo_release_chopstick(philo->right_hand);
      pthread_mutex_unlock(philo->right_hand);
    }
}

void		sleepl(t_philo *philo)
{
  lphilo_sleep();
  philo->action = 0;
}

int		endloop(t_philo *philo)
{
  int		i;

  i = 0;
  while (i < nbphilo)
    {
      if (philo[i].nbloop == loop)
	return (1);
      i++;
    }
  return (0);
}

void		*action_philo(void *arg)
{
  t_philo	*philo;

  philo = (t_philo*)arg;
  while (endloop(philo) == 0)
    {
      if (philo->action != 0 && philo->action != 2)
	sleepl(philo);
      else if (philo->action != 2)
	thinks(philo);
      else if(philo->action != 1)
	eat(philo);
    }
  return (arg);
}
