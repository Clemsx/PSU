/*
** my_setenv.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1/fts
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Dec 12 11:57:23 2016 clement xia
** Last update Tue Dec 13 18:09:35 2016 clement xia
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	**set_env(char *s, char **env)
{
  //char	**new_env;
  int	i;

  i = 0;
  //if ((new_env = malloc(sizeof(char *) * (tab_len(env) + 2))) == NULL)
  //return (0);
  //new_env = env;
  while (env[i] != '\0')
    i++;
  if ((env[i] = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
    return (0);
  else
    env[i] = my_strcpy(env[i], s);
  env[i + 1] = '\0';
  return (env);
}
