/*
** strace.c for strace in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 21:22:55 2017 Leo Blouard
** Last update Sun Apr 16 09:18:55 2017 clement xia
*/

#include "../strace.h"

void	sigh(int sid)
{
  if (sid == SIGINT)
    {
      if ((ptrace(PTRACE_CONT, g_strace->chd_pid, NULL, NULL)) == -1)
	return ;
      if ((ptrace(PTRACE_DETACH, g_strace->chd_pid, NULL, NULL)) == -1)
	return ;
      fprintf(stderr, "Process %d detached\n", g_strace->pid);
      exit(g_strace->chd_st);
    }
}

int	st_pt(t_strace *strace)
{
  int	bool;
  int	verif;

  bool = 1;
  waitpid(strace->chd_pid, &strace->chd_st, 0);
  while (bool)
    {
      if (WIFEXITED(strace->chd_st) == 1)
	bool = 1;
      verif = 0;
      if ((ptrace(PTRACE_GETREGS, strace->chd_pid, NULL, &strace->reg)) == -1)
	return (1);
      verif = check_sys(strace);
      if ((ptrace(PTRACE_SINGLESTEP, strace->chd_pid, NULL, NULL)) == -1)
	return (1);
      waitpid(strace->chd_pid, &strace->chd_st, 0);
      if (verif == 1)
	spill_sys(strace);
    }
  return (0);
}

int	st_fork(t_strace *strace)
{
  pid_t	id;

  id = fork();
  if (id == -1)
    exit (0);
  if ((strace->parent = id))
    strace->parent = 1;
  else
    strace->parent = 0;
  strace->chd_pid = id;
  if (strace->parent == 0)
    {
      if ((ptrace(PTRACE_TRACEME, NULL, NULL, NULL)) == -1)
	return (1);
      kill(getpid(), SIGSTOP);
      execvp(strace->argv[1], &strace->exec);
      return (0);
    }
  else if (strace->parent == 1)
      return (st_pt(strace));
  return (strace->chd_st);
}

int	st_att(t_strace *strace)
{
  int	bool;
  int	verif;

  bool = 1;
  if ((ptrace(PTRACE_ATTACH, strace->chd_pid, NULL, NULL)) == -1)
    return (1);
  waitpid(strace->chd_pid, &strace->chd_st, 0);
  while (bool != 0)
    {
      if (WIFEXITED(strace->chd_st) == 1)
	bool = 0;
      verif = 0;
      if ((ptrace(PTRACE_GETREGS, strace->chd_pid, NULL, &strace->reg)) == -1)
	return (1);
      verif = check_sys(strace);
      if ((ptrace(PTRACE_SINGLESTEP, strace->chd_pid, NULL, NULL)) == -1)
	return (1);
      waitpid(strace->chd_pid, &strace->chd_st, 0);
      if (verif == 1)
	spill_sys(strace);
      return (strace->chd_st);
    }
  return (strace->chd_st);
}
