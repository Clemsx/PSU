/*
** my_ls.c for my_ls in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Fri Nov 18 11:02:45 2016 clement xia
** Last update Thu Nov 24 19:17:03 2016 clement xia
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	my_printf(char *tmp, ...);
char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);
int	my_cmpstr(char *s1, char *s2);
int	my_alpha(char c);
void	check_tab(char **tab, int nb);

void	my_free(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
}

void	add_in_tab(char **tab, char *path)
{
  DIR	*dirt;
  struct dirent *f;
  int   i;
  
  i = 0;
  if (path == 0)
    dirt = opendir(".");
  else
    dirt = opendir(path);
  f = readdir(dirt);
  while ((f = readdir(dirt)) != NULL)
    {
      if (f->d_name[0] != '.')
	{
	  tab[i] = malloc(sizeof(char) * my_strlen(f->d_name) + 1);
	  my_strcpy(tab[i], f->d_name);
	  i++;
	}
    }
  tab[i] = '\0';
  check_tab(tab, i);
  my_free(tab);
}

char	**tab_alloc(char *path)
{
  DIR	*dirt;
  char	**tab;
  int	i;
  struct dirent	*f;

  i = 0;
  if (path == 0)
    dirt = opendir(".");
  else
    dirt = opendir(path);
  f = readdir(dirt);
  while ((f = readdir(dirt)) != NULL)
    i++;
  tab = malloc(sizeof(char *) * i + 1);
  return (tab);
}

void	normal_dir(char *path)
{
  DIR	*dirt;
  struct dirent	*f;
  char	**tab;
  
  if (path == 0)
    dirt = opendir(".");
  else
    dirt = opendir(path);
  if (dirt == NULL)
    exit (1);
  f = readdir(dirt);
  if (f == NULL)
    exit (1);
  tab = tab_alloc(path);
  add_in_tab(tab, path);
  free(tab);
  closedir(dirt);
}
