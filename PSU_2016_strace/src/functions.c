/*
** functions.c for functions in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 21:21:42 2017 Leo Blouard
** Last update Sun Apr 16 10:01:12 2017 clement xia
*/

#include "../strace.h"

void		do_pid(t_strace strace, int result)
{
  g_strace = &strace;
  strace.chd_pid = strace.pid;
  signal(SIGINT, &sigh);
  result = st_att(&strace);
  (void)result;
}

int		my_free(t_strace *strace)
{
  if (strace == NULL)
    return (0);
  if (strace->argv == NULL)
    free (strace->argv);
  return (0);
}

int		my_atoi(char *nbr)
{
  int		i;

  i = 0;
  while (nbr[i])
    {
      if (nbr[i] >= 48 && nbr[i] <= 57)
	i++;
      else
	return (-1);
    }
  return (atoi(nbr));
}

int   is_neg(long long int reg)
{
  if (reg < 0)
    return (0);
  return (1);
}

void		print_error(t_sys *sys, t_strace *strace)
{
  if (sys->param > 0)
    fprintf(stderr, "0x%llx", strace->reg.rdi);
  if (sys->param > 1)
    fprintf(stderr, ", 0x%llx", strace->reg.rsi);
  if (sys->param > 2)
    fprintf(stderr, ", 0x%llx", strace->reg.rdx);
  if (sys->param > 3)
    fprintf(stderr, ", 0x%llx", strace->reg.r8);
  if (sys->param > 4)
    fprintf(stderr, ", 0x%llx", strace->reg.r10);
  if (sys->param > 5)
    fprintf(stderr, ", 0x%llx", strace->reg.r9);
}
