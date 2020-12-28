/*
** flags.c for flags in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/src
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 21:21:22 2017 Leo Blouard
** Last update Thu Apr 13 22:39:45 2017 Leo Blouard
*/

#include "../strace.h"

void	check_p(char *nbr)
{
  if (my_atoi(nbr) > 0)
    {
      printf("-p ok\n");
      exit (0);
    }
  else
    {
      fprintf(stderr, "Usage : ./strace [-s] [-p <pid>|<command>]\n");
      exit (0);
    }
}

void	check_s()
{
  printf("-s ok\n");
  exit (0);
}

int	trace_yes(char *str)
{
  if (str[0] == '-')
    return (1);
  return (0);
}

void	saveflag(char **argv, t_strace *strace)
{
  int	i;

  i = 1;
  strace->s_flag = 0;
  strace->p_flag = 0;
  while (argv[i] != '\0')
    {
      if (strcmp(argv[i], "-s") == 0)
	{
	  strace->s_flag = 1;
	  strace->flag = FLAG_S;
	  check_s();
	}
      else if (strcmp(argv[i],"-p") == 0)
	{
	  strace->p_flag = 1;
	  strace->flag = FLAG_P;
	  check_p(argv[i + 1]);
	}
      else if (trace_yes(argv[i]) == 0)
	strace->exec = argv[i];
      i++;
    }
}
