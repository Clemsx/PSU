/*
** my_cd.c for minishell in /home/clemsx/PSU/PSU_2016_minishell1/fts
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Wed Dec 14 16:50:40 2016 clement xia
** Last update Sun Dec 18 14:23:17 2016 clement xia
*/

#include <unistd.h>
#include "../include/my.h"
#include "../include/my_printf.h"

void	my_cd(char *pathfile)
{
  if ((my_strcmp(pathfile, "..") == 0))
    chdir("../");
  else
    chdir(pathfile);
}
