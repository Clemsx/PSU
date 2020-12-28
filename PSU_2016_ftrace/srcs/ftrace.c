/*
** ftrace.c for ftrace in /home/clemsx/Tek2/PSU/PSU_2016_ftrace/srcs
**
** Made by clement xia
** Login   <clemsx@epitech.net>
**
** Started on  Wed May  3 22:49:51 2017 clement xia
** Last update Sun May  7 20:46:31 2017 Leo Blouard
*/

#include "ftrace.h"

int		st_pt(t_ftrace *ftrace, t_elf *elf)
{
  int		bool;
  int		verif;
  uint64_t	op;
  int		call;
  int		ret;

  bool = 1;
  waitpid(ftrace->chd_pid, &ftrace->chd_st, 0);
  while (bool)
    {
      op = set_op(ftrace);
      st_op(ftrace, elf, call, ret);
      if (op == 0xe8 || op == 0x9a || op == 0xff)
        call = 1;
      if (op == 0xc3 || op == 0xcb || op == 0xc2 || op == 0xca)
        ret = 1;
      verif = check_sys(ftrace);
      if ((ptrace(PTRACE_SINGLESTEP, ftrace->chd_pid, NULL, NULL)) == -1)
	return (1);
      waitpid(ftrace->chd_pid, &ftrace->chd_st, 0);
      if (verif == 1)
	spill_sys(ftrace);
    }
  return (0);
}

void		st_op(t_ftrace* ftrace, t_elf* elf, int call, int ret)
{
  Elf64_Sym	*sym;

  if (call && (sym = get_symbol(elf, (Elf64_Addr)ftrace->reg.rip)) != NULL)
    {
      if (strlen(get_symbol_name(elf, sym))
	  && sym->st_size)
        fprintf(stderr, "Entering function %s at 0x%llx\n", get_symbol_name(elf, sym), ftrace->reg.rip);
    }
  if (ret && (sym = get_symbol(elf, (Elf64_Addr)ftrace->reg.rip)) != NULL)
    {
      if (strlen(get_symbol_name(elf, sym))
	  && sym->st_size)
        fprintf(stderr, "Leaving function %s\n", get_symbol_name(elf, sym));
    }
}

int		st_fork(t_ftrace *ftrace, t_elf *elf)
{
  pid_t		id;

  id = fork();
  if (id == -1)
    exit (0);
  if ((ftrace->parent = id))
    ftrace->parent = 1;
  else
    ftrace->parent = 0;
  ftrace->chd_pid = id;
  if (ftrace->parent == 0)
    {
      if ((ptrace(PTRACE_TRACEME, NULL, NULL, NULL)) == -1)
	return (1);
      kill(getpid(), SIGSTOP);
      execvp(ftrace->argv[1], &ftrace->exec);
      return (0);
    }
  else if (ftrace->parent == 1)
    return (st_pt(ftrace, elf));
  return (ftrace->chd_st);
}
