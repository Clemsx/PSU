/*
** builtins.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Dec  8 15:21:17 2016 clement xia
** Last update Wed Dec 14 17:59:02 2016 clement xia
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_printf.h"

char	*find_path(char **env)
{
  int	i;
  char	*path;

  i = 0;
  while (env[i][0] != 'P' || env[i][1] != 'A' ||
	 env[i][2] != 'T' || env[i][3] != 'H')
    i++;
  path = env[i];
  return (path);
}


void	builtins(char *str, char **env)
{
  char	**s;
  
  s = my_str_to_wordtab(str);
  if (s[0] != 0 && my_strcmp(s[0], "exit") == 0)
    exit (0);
  else if (s[0] != 0 && my_strcmp(s[0], "env") == 0)
    display_env(env);
  else if (s[0] != 0 && my_strcmp(s[0], "setenv") == 0)
    set_env(s[1], env);
  else if (s[0] != 0 && my_strcmp(s[0], "unsetenv") == 0)
    unset_env(s[1], env);
  else if (s[0] != 0 && my_strcmp(s[0], "cd") == 0)
    {
      if (s[1] == 0)
	chdir("/home");
      else
	my_cd(s[1]);
    }
}

