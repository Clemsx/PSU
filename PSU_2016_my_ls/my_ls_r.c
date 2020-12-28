/*
** my_ls_r.c for my_ls_r in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Fri Nov 18 15:46:41 2016 clement xia
** Last update Thu Nov 24 19:26:21 2016 clement xia
*/

#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>

int	my_printf(char *tmp, ...);

char	**rev_tab(char **tab, int nb)
{
  int	i;
  int	j;
  char	*rev;

  i = 0;
  while (i < nb)
    {
      j = i;
      while (j < nb)
	{
	  rev = tab[i];
	  tab[i] = tab[j];
	  tab[j] = rev;
	  j++;
	}
      i++;
    }
  return (tab);
}

void	display_tab_rev(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != '\0')
    i++;
  j = 0;
  tab = rev_tab(tab, i);
  while (tab[j] != '\0')
    {
      my_printf("%s  ", tab[j]);
      j++;
    }
  my_printf("\n");
}
 
void	my_ls_r()
{
  DIR	*dirt;
  struct dirent	*f;
  char **tab;
  int	i;
  
  i = 0;
  tab = malloc(sizeof (char *) * 100);
  dirt = opendir(".");
  if (dirt == NULL)
    exit (1);
  f = readdir(dirt);
  if (f == NULL)
    exit (1);
  while ((f = readdir(dirt)) != NULL)
    {
      if (f->d_name[0] != '.')
	tab[i++] = f->d_name;
    }
  display_tab_rev(tab);
  free(tab);
  closedir(dirt);
}
