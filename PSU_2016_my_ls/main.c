/*
** main.c for main in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Nov 17 17:21:16 2016 clement xia
** Last update Fri Nov 18 20:55:24 2016 clement xia
*/

#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>

int	my_printf(char *tmp, ...);
int	my_strcmp(char *s1, char *s2);
void	normal_dir(char *path);
void	my_ls_l();
void	my_ls_r();
void	my_ls_d();

void	ac2(char *path)
{
  if (my_strcmp(path, "-l") == 0)
    my_ls_l();
  else if (my_strcmp(path, "-r") == 0)
    my_ls_r();
  else if (my_strcmp(path, "-d") == 0)
    my_ls_d();
  else
    normal_dir(path);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    normal_dir(av[1]);
  else if (ac == 2)
    ac2(av[1]);
  return (0);
}
