/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/clemsx/delivery/CPool_Day08/task04
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Wed Oct 12 17:02:56 2016 clement xia
** Last update Wed Dec 14 17:26:49 2016 clement xia
*/

#include <stdlib.h>

char	*my_strncpy(char *dest, char *src, int n);

int	is_alpha(char c)
{
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || (c == 47) || (c == 45) || (c == 46))
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

int	word_count(char *str)
{
  int	i;
  int	word;

  i = 0;
  word = 0;
  while (str[i] != '\0')
    {
      if (is_alpha(str[i]) == 1 && (is_alpha(str[i + 1]) == 0))
	word = word + 1;
      i = i + 1;
    }
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	l;
  char	**tab;

  i = 0;
  j = 0;
  l = 0;
  tab = malloc((word_count(str) + 1) * (sizeof(char *)));
  while (str[i] != '\0')
    {
      if (is_alpha(str[i]) == 1)
	l = l + 1;
      if (is_alpha(str[i]) == 1 && (is_alpha(str[i + 1]) == 0))
	{
	  tab[j] = malloc(sizeof(char) * (l + 1));
	  my_strncpy(tab[j], &str[i - l + 1], l);
	  l = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
  tab[j] = '\0';
  return (tab);
}
