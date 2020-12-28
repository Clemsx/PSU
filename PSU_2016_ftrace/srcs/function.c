/*
** function.c for ftrace in /home/clemsx/Tek2/PSU/PSU_2016_ftrace/srcs
**
** Made by clement xia
** Login   <clemsx@epitech.net>
**
** Started on  Wed May  3 22:51:49 2017 clement xia
** Last update Sun May  7 19:14:40 2017 Leo Blouard
*/

#include "ftrace.h"

int		my_free(t_ftrace *ftrace)
{
  if (ftrace == NULL)
    return (0);
  if (ftrace->argv == NULL)
    free (ftrace->argv);
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

int		is_neg(long long int reg)
{
  if (reg < 0)
    return (0);
  return (1);
}

void		print_error(t_sys *sys, t_ftrace *ftrace)
{
  if (sys->param > 0)
    fprintf(stderr, "0x%llx", ftrace->reg.rdi);
  if (sys->param > 1)
    fprintf(stderr, ", 0x%llx", ftrace->reg.rsi);
  if (sys->param > 2)
    fprintf(stderr, ", 0x%llx", ftrace->reg.rdx);
  if (sys->param > 3)
    fprintf(stderr, ", 0x%llx", ftrace->reg.r8);
  if (sys->param > 4)
    fprintf(stderr, ", 0x%llx", ftrace->reg.r10);
  if (sys->param > 5)
    fprintf(stderr, ", 0x%llx", ftrace->reg.r9);
}

uint64_t	set_op(t_ftrace *ftrace)
{
  uint64_t      op;
  uint64_t      i;

  if (WIFEXITED(ftrace->chd_st) == 1)
    return (0);
  if ((ptrace(PTRACE_GETREGS, ftrace->chd_pid, NULL, &ftrace->reg)) == -1)
    return (1);
  i = ptrace(PTRACE_PEEKTEXT, ftrace->chd_pid, ftrace->reg.rip, NULL);
  op = i & 0xff;
  return (op);
}
