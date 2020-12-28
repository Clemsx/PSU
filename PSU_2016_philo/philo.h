/*
** philo.h for philo in /home/clemsx/Tek2/PSU/PSU_2016_philo
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Mar 14 11:36:15 2017 clement xia
** Last update Fri Mar 17 18:22:11 2017 clement xia
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int		nbphilo;
int		loop;

typedef enum		s_enum
  {
    SLEEP = 0,
    EAT = 1,
    THINKS = 2
  }			t_enum;

typedef struct		s_philo
{
  pthread_mutex_t	*left_hand;
  pthread_mutex_t	*right_hand;
  pthread_t		thread;
  int			nbloop;
  t_enum		action;
}			t_philo;

/* error.c */
void			printerr();

/* check.c */
void			check_nbr(char **av);
int			check_param(char **av);
int			random_nb(int nb);

/* philo.c */
void			init();
void			init_philo(pthread_mutex_t *chopstick);

/* action.c */
void	*action_philo(void *arg);

#endif /* !PHILO_H_ */
