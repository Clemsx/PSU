/*
** show_alloc_mem.c for show_alloc_mem in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Feb  7 02:06:22 2017 Leo Blouard
** Last update Wed Feb  8 10:34:19 2017 Leo Blouard
*/

#include "lib/malloc.h"

void            show_alloc_mem()
{
  t_alloc       *mem;

  printf("break : %p\n", sbrk(0));
  while (mem)
    {
      printf("%p - %p : %zu octets\n", mem, mem + mem->sizemem, mem->sizemem);
      mem = mem->next;
    }
}
