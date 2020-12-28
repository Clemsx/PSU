/*
** ftrace.h for ftrace in /home/clemsx/Tek2/PSU/PSU_2016_ftrace
**
** Made by clement xia
** Login   <clemsx@epitech.net>
**
** Started on  Wed May  3 22:29:35 2017 clement xia
** Last update Sun May  7 19:22:41 2017 Leo Blouard
*/

#ifndef FTRACE_H_
#define FTRACE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/reg.h>
#include <asm/unistd_64.h>
#include <sys/mman.h>

# define INSTRU_MASK	0x000000000000FFFF
# define EXIT		0xFFFF
# define REG1		0x80CD
# define REG2		0x50F

typedef struct			s_ftrace
{
  char				*exec;
  pid_t				pid;
  int				error;
  char				**argv;
  int				argc;
  int				chd_st;
  pid_t				chd_pid;
  int				parent;
  struct user_regs_struct	reg;
}				t_ftrace;

typedef struct			s_sys
{
  int				nbr;
  char				*name;
  int				param;
  int				type;
}				t_sys;

t_ftrace			*g_ftrace;

typedef struct			elf64
{
  Elf64_Ehdr			*ehdr;
  Elf64_Phdr			*phdr;
  Elf64_Shdr			*shdr;
  size_t			size;
  uint8_t			*mem;
} t_elf;

/* check.c */
int				check_argv(t_ftrace *ftrace, int ac, char** av);
int				recheck(t_ftrace *trace, int ac, char** av);
int				check_sys(t_ftrace *ftrace);
void				saveflag(char **argv, t_ftrace *ftrace);

/* spill.c */
int				spill_sys(t_ftrace *ftrace);
int				spill_reg(t_ftrace *ftrace, t_sys *sys);
t_sys				*get_spill(int nbr);

/* strace.c */
int				st_fork(t_ftrace *ftrace, t_elf *elf);
int				st_pt(t_ftrace *ftrace, t_elf *elf);
void				st_op(t_ftrace *ftrace, t_elf *elf, int call, int ret);

/* functions.c */
int				my_free(t_ftrace *ftrace);
int				my_atoi(char *nbr);
int				is_neg(long long int reg);
void				print_error(t_sys *sys, t_ftrace *ftrace);
uint64_t			set_op(t_ftrace *ftrace);
/* elf64.c */
int				setup_elf(t_elf *elf, char **av);
Elf64_Sym			*get_symbol(t_elf *elf, Elf64_Addr addr);
char				*get_strtab(t_elf *elf);
char				*get_symbol_name(t_elf *elf, Elf64_Sym *symtab);

#endif /* !FTRACE_H_ */
