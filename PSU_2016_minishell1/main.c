/*
** main.c for minishell1 in /home/clemsx/PSU/PSU_2016_minishell1
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Dec  6 14:56:30 2016 clement xia
** Last update Wed Dec 14 17:36:50 2016 clement xia
*/

#include "include/my.h"
#include "include/get_next_line.h"
#include "include/my_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	command(char *s, char **path, char **env)
{
  char	*str;
  char	**tab;
  int	i;

  i = 0;
  str = my_strcat(path[i], "/");
  str = my_strcat(str, s);
  tab = my_str_to_wordtab(str);
  while ((execve(tab[0], tab, env)) == -1)
    {
      str = my_strcat(path[i++], "/");
      str = my_strcat(str, s);
      tab = my_str_to_wordtab(str);
      if (i == 6)
	{
	  if (my_strcmp(s, "") != 0 && my_strcmp(s, "exit") != 0)
	    my_printf("Command not found\n");
	}
    }
}

void	check_command(char *s, char **path, char **env)
{
  pid_t	forch;
  int	status;
  char	**str;

  str = my_str_to_wordtab(s);
  if(((my_strcmp(str[0], "cd") == 0) || (my_strcmp(str[0], "env") == 0) ||
      (my_strcmp(str[0], "setenv") == 0) || (my_strcmp(str[0], "unsetenv") == 0)
      || (my_strcmp(str[0], "exit") == 0)))
    builtins(s, env);
  else
    {
      if (((forch = fork()) == 0))
	command(s , path, env);
      else
	wait(&status);
    }
}

int	main(int ac, char **av, char **env)
{
  char	**path;
  char	*s;
  char	**envt;

  envt = get_env(env);
  my_printf("%s - %d\n", av[0], ac);
  my_printf("$> ");
  path = my_str_to_wordtab((find_path(envt)));
  while ((s = get_next_line(0)))
    {
      if (s[0] != 0)
	check_command(s, path, envt);
      my_printf("$> ");
    }
  return (0);
}
