/*
** unset_env.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1/fts
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Dec 12 16:15:08 2016 clement xia
** Last update Sun Dec 18 14:20:00 2016 clement xia
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"

char	**unset_env(char *s, char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp(s, env[i]) == 0)
	{
	  if (env[i + 1] == NULL)
	    env[i] = 0;
	  else
	    {
	      while (env[i] != NULL)
		{
		  env[i] = env[i + 1];
		  i++;
		}
	    }
	}
      i++;
    }
  env[i] = '\0';
  return (env);
}
