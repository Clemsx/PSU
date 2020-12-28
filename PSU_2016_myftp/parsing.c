/*
** parsing.c for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue May 16 19:09:27 2017 clement xia
** Last update Sun May 21 11:37:39 2017 clement xia
*/

#include "my_ftp.h"

char    *get_cmd(char *cmd)
{
  char	*save;
  int	i;

  if ((save = malloc(sizeof(char) * 50 + 1)) == NULL)
    return (NULL);
  i = 0;
  while (cmd[i] != '\0' && cmd[i] != '\r' && cmd[i] != '\n' && cmd[i] != ' ')
    {
      save[i] = cmd[i];
      i++;
    }
  save[i] = '\0';
  return (save);
}

int	is_alpha(char first)
{
  if ((first >= '!' && first < 126))
    return (1);
  return (-1);
}

char	*get_parameter(char *cmd)
{
  char	*save;
  int	x;
  int	y;

  if ((save = malloc(sizeof(char) * 50 + 1)) == NULL)
    return (NULL);
  x = 0;
  y = 0;
  while (cmd[x] != ' ')
    x++;
  x++;
  while (cmd[x] != '\0' && cmd[x] != '\r' && cmd[x] != '\n')
    {
      save[y] = cmd[x];
      y++;
      x++;
    }
  save[y] = '\0';
  if (is_alpha(save[0]) != 1)
    return (NULL);
  return (save);
}
