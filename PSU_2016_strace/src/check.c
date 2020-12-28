/*
** check.c for check in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 21:21:02 2017 Leo Blouard
** Last update Sun Apr 16 09:32:56 2017 clement xia
*/

#include "../strace.h"

int			recheck(t_strace *strace, int argc, char **argv)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  strace->argv = calloc((argc + 1), sizeof(char *));
  if (strace->argv == NULL)
    return (0);
  while (argv[i] && trace_yes(argv[i]))
    i++;
  if (!argv[i])
    return (0);
  while (argv[i])
    {
      strace->argv[j] = argv[j];
      strace->argc = j;
      i++;
      j++;
    }
  return (1);
}

int			check_argv(t_strace *strace, int argc, char **argv)
{
  if (strace->error == 1)
    return (0);
  if (recheck(strace, argc, argv) == 0)
    return (0);
  saveflag(argv, strace);
  return (1);
}

int			check_sys(t_strace *strace)
{
  unsigned short	i;

  i = ptrace(PTRACE_PEEKTEXT, strace->chd_pid, strace->reg.rip, 0);
  if (i == EXIT)
    exit (1);
  if ((i == REG1) || (i == REG2))
    return (1);
  return (0);
}
