/*
** my_ls2.c for my_ls2 in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Nov 24 18:02:43 2016 clement xia
** Last update Thu Nov 24 18:34:31 2016 clement xia
*/

#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int	my_printf(char *tmp, ...);
char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);
void	my_sort_tab(char **tab, int l);

void    check_tab(char **tab, int nb)
{
  int   i;
  int   j;
   
  j = 0;
  i = 0;
  while (i < nb)
    {
      my_sort_tab(tab, i);
      i++;
    }
  while (j < nb)
    {
      my_printf("%s  ", tab[j]);
      j++;
    }
  my_printf("\n");
}

int     my_alpha(char c)
{
  int   i;
  char  *maj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char  *min = "abcdefghijklmnopqrstuvwxyz";
  char  *num = "0123456789";
   
  i = 0;
  while (i < my_strlen(maj))
    {
      if (num[i] == c)
	return (i);
      else if (min[i] == c || maj[i] == c)
	return (i + 10);
      i++;
    }
  return (0);
}

int     my_cmpstr(char *s1, char *s2)
{
  int   i;
  int   s;
  int   res;
   
  i = 0;
  s = 0;
  if (my_strlen(s1) >= my_strlen(s2))
    s = my_strlen(s1);
  else
    s = my_strlen(s2);
  while (i < s)
    {
      res = my_alpha(s1[i]) - my_alpha(s2[i]);
      if (res < 0)
	return (-1);
      else if (res > 0)
	return (1);
      i++;
    }
  return (0);
}

void    my_sort_tab(char **tab, int l)
{
  int   i;
  char  *t;
   
  i = l;
  while ((i > 0) && my_cmpstr(tab[i], tab[i - 1]) < 0)
    {
      t = tab[i - 1];
      tab[i - 1] = tab[i];
      tab[i] = t;
      i--;
    }
}
