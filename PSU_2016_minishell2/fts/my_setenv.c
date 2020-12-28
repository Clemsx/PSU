/*
** my_setenv.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1/fts
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Dec 12 11:57:23 2016 clement xia
** Last update Sun Dec 18 14:22:54 2016 clement xia
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"

char	**set_env(char *s, char **env)
{
  int	i;

  i = 0;
  while (env[i] != '\0')
    i++;
  if ((env[i] = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
    return (0);
  else
    env[i] = my_strcpy(env[i], s);
  env[i + 1] = '\0';
  return (env);
}
