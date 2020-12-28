/*
** spill.c for ftrace in /home/clemsx/Tek2/PSU/PSU_2016_ftrace/srcs
**
** Made by clement xia
** Login   <clemsx@epitech.net>
**
** Started on  Wed May  3 22:52:41 2017 clement xia
** Last update Sun May  7 18:54:51 2017 Leo Blouard
*/

#include "ftrace.h"
#include "syscall.h"

int		spill_reg(t_ftrace *ftrace, t_sys *sys)
{
  print_error(sys, ftrace);
  if (sys->type == 0)
    fprintf(stderr, ") = ?\n");
  else
    {
      if ((ptrace(PTRACE_SINGLESTEP, ftrace->chd_pid, 0, 0)) == -1)
	return (0);
      waitpid(ftrace->chd_pid, &ftrace->chd_st, 0);
      if ((ptrace(PTRACE_GETREGS, ftrace->chd_pid, 0, &ftrace->reg)) == -1)
	return (0);
      if (is_neg(ftrace->reg.rax) == 0)
	fprintf(stderr, ") = 0x%llx\n", ftrace->reg.rax + 1);
      else
	fprintf(stderr, ") = 0x%llx\n", ftrace->reg.rax);
    }
  return (1);
}

t_sys		*get_spill(int nbr)
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

int		spill_sys(t_ftrace *ftrace)
{
  t_sys		*sys;

  sys = get_spill((ftrace->reg.rax & EXIT));
  if (sys == NULL)
    return (0);
  fprintf(stderr, "Syscall %s(", sys->name);
  spill_reg(ftrace, sys);
  return (1);
}
