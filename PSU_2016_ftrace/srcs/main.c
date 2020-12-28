/*
** main.c for ftrace in /home/clemsx/Tek2/PSU/PSU_2016_ftrace/srcs
**
** Made by clement xia
** Login   <clemsx@epitech.net>
**
** Started on  Wed May  3 22:43:50 2017 clement xia
** Last update Sun May  7 18:55:08 2017 Leo Blouard
*/

#include "ftrace.h"

int		main(int ac, char **av)
{
  int		result;
  t_ftrace	ftrace;
  t_elf		elf;

  result = 0;
  if (ac <= 1)
    {
      fprintf(stderr, "Usage : ./ftrace <command>\n");
      return (0);
    }
  if (check_argv(&ftrace, ac, av) == 0 || !setup_elf(&elf, av))
    {
      my_free(&ftrace);
      return (0);
    }
  result = st_fork(&ftrace, &elf);
  fprintf(stderr, "+++ exited with %d +++\n", result);
  my_free(&ftrace);
  return (0);
}
