/*
** get_next_line.c for get_next_line in /home/clemsx/PSU/CPE_2016_getnextline
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Nov 28 11:17:22 2016 clement xia
** Last update Sun Dec 18 14:18:46 2016 clement xia
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/get_next_line.h"

char	*my_allocation(int len)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc(len)) == NULL)
    return (0);
  while (i < len)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

char	*my_reallocation(char *str, int new_len)
{
  int	i;
  char	*new_str;

  i = 0;
  if ((new_str = my_allocation(new_len)) == NULL)
    return (0);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  free(str);
  return (new_str);
}

char	get_c(const int fd)
{
  static char	buff[READ_SIZE];
  static char	*str;
  static int	i = 0;
  char	word;

  if (i == 0)
    {
      if ((i = read(fd, buff, READ_SIZE)) == 0)
	return (0);
      str = (char *)&buff;
    }
  i--;
  word = *str++;
  return (word);
}

char	*get_next_line(const int fd)
{
  int	i;
  char	buff_c;
  char	*str;

  i = 0;
  str = my_allocation(sizeof(char) * READ_SIZE + 1);
  if (str == 0)
    return (0);
  buff_c = get_c(fd);
  while (buff_c != '\n')
    {
      if (buff_c == 0)
	return (0);
      str[i] = buff_c;
      i++;
      if ((str = my_reallocation(str, (i + READ_SIZE + 1))) == NULL)
	return (0);
      buff_c = get_c(fd);
    }
  str[i] = '\0';
  return (str);
}
