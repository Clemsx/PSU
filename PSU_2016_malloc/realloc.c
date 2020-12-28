/*
** realloc.c for realloc in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Jan 31 22:58:47 2017 Leo Blouard
** Last update Wed Feb  8 07:21:24 2017 clement xia
*/

#include "lib/malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_alloc       *hd;
  void          *newptr;
  size_t        newsize;

  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  if (!ptr)
    return (malloc(size));
  hd = (t_alloc *)ptr - 1;
  newsize = sizeof(t_alloc*) * (hd->sizemem - 1);
  if (hd->sizemem >= size)
      return (ptr);
  if ((newptr = malloc(size)) == NULL)
    return (NULL);
  pthread_mutex_lock(&g_malloc);
  if (newsize <= size)
    memcpy(newptr, ptr, newsize);
  else
    memcpy(newptr, ptr, size);
  pthread_mutex_unlock(&g_malloc);
  free(ptr);
  return (newptr);
}
