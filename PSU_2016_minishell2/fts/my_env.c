/*
** my_env.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1/fts
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Sun Dec 11 19:45:32 2016 clement xia
** Last update Sun Dec 18 14:21:47 2016 clement xia
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  if (tab[i] == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}

char    **get_env(char **env)
{
  char  **new_env;
  int   i;

  i = 0;
  if ((new_env = malloc((tab_len(env) + 1) * sizeof(char *))) == NULL)
    return (0);
  while (env[i] != NULL)
    {
      if ((new_env[i] = malloc((my_strlen(env[i]) + 1) * sizeof(char))) == NULL)
	return (0);
      else
	new_env[i] = env[i];
      i++;
    }
  new_env[i] = '\0';
  return (new_env);
}

void	display_env(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      my_printf("%s\n", env[i]);
      i++;
    }
}
