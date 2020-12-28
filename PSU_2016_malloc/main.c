/*
** main.c for main in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Feb  7 01:43:46 2017 Leo Blouard
** Last update Wed Feb  8 10:33:38 2017 Leo Blouard
*/

#include "lib/malloc.h"

int		main()
{
  void*	t1;
  void*	t2;

  t1 = malloc(sizeof(t_alloc));
  t2 = malloc(10);
  show_alloc_mem();
  return (0);
}
