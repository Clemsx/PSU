/*
** malloc.h for Malloc in /home/lblouard/delivery/Annee2/PSU/PSU_2016_malloc
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Jan 24 11:18:06 2017 Leo Blouard
** Last update Wed Feb  8 08:05:38 2017 clement xia
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

pthread_mutex_t		g_malloc;

typedef struct		s_allocMem
{
  size_t		sizemem;
  int			free;
  struct s_allocMem	*next;
}			t_alloc;

t_alloc			*startlst;
t_alloc			*endlst;
void			*malloc(size_t size);
void			free(void *mem);
void			*realloc(void *ptr, size_t size);
void			*calloc(size_t nb, size_t size);
void			show_alloc_mem();

#endif /* !MALLOC_H_ */
