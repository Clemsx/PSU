/*
** main.c for ùain in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Wed Apr 12 14:52:28 2017 Leo Blouard
** Last update Sun Apr 16 10:25:24 2017 clement xia
*/

#include "strace.h"

int		main(int argc, char **argv)
{
  int		result;
  t_strace	strace;

  result = 0;
  if (argc <= 1)
    {
      fprintf(stderr, "Usage : ./strace [-s] [-p <pid>|<command>]\n");
      return (0);
    }
  saveflag(argv, &strace);
  if (check_argv(&strace, argc, argv) == 0)
    {
      my_free(&strace);
      return (0);
    }
  if (strace.pid != 0)
    do_pid(strace, result);
  else
    result = st_fork(&strace);
  fprintf(stderr, "+++ exited with %d +++\n", result);
  my_free(&strace);
  return (0);
}
