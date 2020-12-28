/*
** spill.c for spill in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 21:22:17 2017 Leo Blouard
** Last update Sun Apr 16 10:22:28 2017 clement xia
*/

#include "../strace.h"
#include "../syscall.h"

int		spill_reg(t_strace *strace, t_sys *sys)
{
  print_error(sys, strace);
  if (sys->type == 0)
    {
      fprintf(stderr, ") = ?\n");
    }
  else
    {
      if ((ptrace(PTRACE_SINGLESTEP, strace->chd_pid, 0, 0)) == -1)
	return (0);
      waitpid(strace->chd_pid, &strace->chd_st, 0);
      if ((ptrace(PTRACE_GETREGS, strace->chd_pid, 0, &strace->reg)) == -1)
	return (0);
      if (is_neg(strace->reg.rax) == 0)
	fprintf(stderr, ") = 0x%llx\n", strace->reg.rax + 1);
      else
	fprintf(stderr, ") = 0x%llx\n", strace->reg.rax);
    }
  return (1);
}

t_sys	*get_spill(int nbr)
{
  int		i;

  i = 0;
  while (sysc_gl[i].nbr != -1)
    {
      if (sysc_gl[i].nbr == nbr)
	return (&sysc_gl[i]);
      i++;
    }
  return (NULL);
}

int		spill_sys(t_strace *strace)
{
  t_sys		*sys;

  sys = get_spill((strace->reg.rax & EXIT));
  if (sys == NULL)
    return (0);
  fprintf(stderr, "%s(", sys->name);
  spill_reg(strace, sys);
  return (1);
}
