/*
** strace.h for strace in /home/clemsx/Tek2/PSU/PSU_2016_strace/include
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Apr 11 08:05:50 2017 clement xia
** Last update Sun Apr 16 10:32:37 2017 clement xia
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/ptrace.h>
# include <sys/wait.h>
# include <sys/user.h>
# include <sys/types.h>

# define FLAG_S		0B01
# define FLAG_P		0B10
# define INSTRU_MASK	0x000000000000FFFF
# define EXIT		0xFFFF
# define REG1		0x80CD
# define REG2		0x50F

typedef struct			s_strace
{
  int				flag;
  int				s_flag;
  int				p_flag;
  char				*exec;
  pid_t				pid;
  int				error;
  char				**argv;
  int				argc;
  int				chd_st;
  pid_t				chd_pid;
  int				parent;
  

  struct user_regs_struct	reg;
}				t_strace;

typedef struct			s_sys
{
  int				nbr;
  char				*name;
  int				param;
  int				type;
}				t_sys;

t_strace			*g_strace;

/* check.c */
int				check_argv(t_strace *strace, int ac, char** av);
int				recheck(t_strace *strace, int ac, char** av);
int				check_sys(t_strace *strace);
void				saveflag(char **argv, t_strace *strace);

/* flags.c */
void				check_s();
void				check_p(char *nbr);
int				trace_yes(char *str);
void				saveflag(char **argv, t_strace *strace);

/* spill.c */
int				spill_sys(t_strace *strace);
int				spill_reg(t_strace *strace, t_sys *sys);
t_sys				*get_spill(int nbr);

/* strace.c */
int				st_att(t_strace *strace);
int				st_fork(t_strace *strace);
int				st_pt(t_strace *strace);
void				sigh(int sid);

/* functions.c */
void				do_pid(t_strace strace, int result);
int				my_free(t_strace *strace);
int				my_atoi(char *nbr);
int				is_neg(long long int reg);
void				print_error(t_sys *sys, t_strace *strace);

#endif /* !STRACE_H_ */
