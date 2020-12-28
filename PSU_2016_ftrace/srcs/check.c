/*
1;4801;0c** check.c for check in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
**
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
**
** Started on  Thu Apr 13 21:21:02 2017 Leo Blouard
** Last update Sun May  7 19:21:02 2017 Leo Blouard
*/

#include "ftrace.h"

int			recheck(t_ftrace *ftrace, int ac, char **av)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  ftrace->argv = calloc((ac + 1), sizeof(char *));
  if (ftrace->argv == NULL)
    return (0);
  while (av[i])
    {
      ftrace->argv[j] = av[j];
      ftrace->argc = j;
      i++;
      j++;
    }
  return (1);
}

int			check_argv(t_ftrace *ftrace, int argc, char **argv)
{
  if (ftrace->error == 1)
    return (0);
  if (recheck(ftrace, argc, argv) == 0)
    return (0);
  return (1);
}

int			check_sys(t_ftrace *ftrace)
{
  unsigned short	i;

  i = ptrace(PTRACE_PEEKTEXT, ftrace->chd_pid, ftrace->reg.rip, 0);
  if (i == EXIT)
    exit (1);
  if ((i == REG1) || (i == REG2))
    return (1);
  return (0);
}
