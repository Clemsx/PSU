/*
** malloc.c for malloc_PSU in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Jan 26 14:07:03 2017 Leo Blouard
** Last update Wed Feb  8 08:07:32 2017 clement xia
*/

#include "lib/malloc.h"

t_alloc		*find_mem(size_t size)
{
  t_alloc	*actual;

  actual = startlst;
  while (actual != NULL)
    {
      if (actual->free && actual->sizemem >= size)
	return (actual);
      actual = actual->next;
    }
  return (NULL);
}

void		*add_mem(size_t size)
{
  void	*ptr;
  int	pagesize;
  int	nbpage;

  if (size <= 0)
    return (NULL);
  pagesize = (int)getpagesize();
  nbpage = (size / pagesize);
  ptr = sbrk((nbpage + 1) * pagesize);
  if (!ptr)
    {
      pthread_mutex_unlock(&g_malloc);
      return (NULL);
    }
  if (ptr == (void *) -1)
    {
      pthread_mutex_unlock(&g_malloc);
      return (NULL);
    }
  return (ptr);
}

t_alloc		*init_mem(t_alloc *init, size_t size, void *ptr)
{
  init = (t_alloc *)ptr;
  init->sizemem = size;
  init->free = 0;
  init->next = NULL;
  return (init);
}

void		*malloc(size_t size)
{
  t_alloc	*hd;
  void		*tmp;

  if (size <= 0)
    return (NULL);
  pthread_mutex_lock(&g_malloc);
  hd = find_mem(size + sizeof(t_alloc *));
  if (hd)
    {
      hd->free = 0;
      pthread_mutex_unlock(&g_malloc);
      return (hd + 1);
    }
  tmp = add_mem(size);
  hd = init_mem(NULL, size, tmp);
  if (startlst == NULL)
    startlst = hd;
  if (endlst == NULL)
    endlst = hd;
  else
    endlst->next = hd;
  hd->free = 0;
  pthread_mutex_unlock(&g_malloc);
  return (hd + 1);
}
