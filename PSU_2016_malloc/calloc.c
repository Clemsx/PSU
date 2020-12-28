/*
** calloc.c for malloc in /home/clemsx/CPP/PSU/tmalloc
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Feb  2 11:20:19 2017 clement xia
** Last update Mon Feb  6 23:39:56 2017 Leo Blouard
*/

#include "lib/malloc.h"

void            *calloc(size_t nb, size_t size)
{
  size_t	s;
  void		*ptr;

  if (!nb || !size)
    return (NULL);
  s = nb * size;
  if (size != (s / nb))
    return (NULL);
  ptr = malloc(s);
  if (!ptr)
    return (NULL);
  return (memset(ptr, 0, s));
}
