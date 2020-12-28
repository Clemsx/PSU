/*
** free.c for free in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Jan 31 15:56:24 2017 Leo Blouard
** Last update Wed Feb  8 08:06:30 2017 clement xia
*/

#include "lib/malloc.h"

void		check_free()
{
  t_alloc	*tmp;

  tmp = startlst;
  while (tmp)
    {
      if (tmp->next == tmp)
	{
	  tmp->next = NULL;
	  endlst = tmp;
	}
      tmp = tmp->next;
    }
}

void		free(void *mem)
{
  t_alloc	*hd;

  if (!mem)
    return;
  pthread_mutex_lock(&g_malloc);
  hd = (t_alloc *)mem - 1;
  if (((char*)mem + hd->sizemem) == sbrk(0))
    {
      if (startlst == endlst)
	{
	  endlst = startlst;
	  startlst = NULL;
	}
      else
	check_free();
      sbrk(0 - sizeof(t_alloc*) - hd->sizemem);
      hd->free = 1;
      pthread_mutex_unlock(&g_malloc);
      return;
    }
  hd->free = 1;
  pthread_mutex_unlock(&g_malloc);
}
