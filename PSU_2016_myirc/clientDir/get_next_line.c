/*
** get_next_line.c for get_next_line in /home/lblouard/delivery/CPE_2016_getnextline
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon Nov 28 15:11:35 2016 Leo Blouard
** Last update Sun May 21 02:36:36 2017 Leo Blouard
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(src);
  while (i < n)
    {
      dest[i] = src[i];
      i++;
      if (src[i] == '\0' && n > len)
	{
	  dest[i] = '\0';
	  return (dest);
	}
    }
  return (dest);
}

char		*my_realloc(char *str, int size)
{
  char		*tmp;
  int		i;

  tmp = malloc(size);
  if (str != NULL)
    {
      i = my_strlen(str);
      if (size < i)
	i = size;
      my_strncpy(tmp, str, i);
      free(str);
    }
  return (tmp);
}

char		readline(const int fd)
{
  static int	len;
  static char	*tmp;
  static char	buff[READ_SIZE];
  char		caract;

  if (len == 0)
    {
      len = read(fd, buff, READ_SIZE);
      tmp = (char *)&buff;
      if (len == 0)
	return (0);
    }
  len = len - 1;
  caract = *tmp;
  tmp = tmp + 1;
  return (caract);
}

char		*get_next_line(const int fd)
{
  char		caract;
  char		*line;
  int		len;

  len = 0;
  line = malloc(READ_SIZE + 1);
  if (line == NULL)
    return (NULL);
  caract = readline(fd);
  while (caract != '\n' && caract != '\0')
    {
      line[len] = caract;
      caract = readline(fd);
      len = len + 1;
      if (len % (READ_SIZE + 1))
	line = my_realloc(line, len + READ_SIZE + 1);
    }
  line[len] = '\0';
  if (caract == 0 && line[0] == 0)
    return (NULL);
  return (line);
}
