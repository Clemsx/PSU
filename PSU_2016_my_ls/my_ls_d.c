/*
** my_ls_d.c for my_ls_d in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Fri Nov 18 20:35:37 2016 clement xia
** Last update Fri Nov 18 21:41:00 2016 clement xia
*/

#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>

int	my_printf(char *tmp, ...);
char	**rev_tav(char **tab, int nb);
void	display_tab_rev(char **tab);
int	my_strcmp(char *s1, char *s2);

void	my_ls_d(char *path)
{
  if (my_strcmp(path, "-d") == 0)
    my_printf(".\n");
  else
    my_printf("%s", path);
}
