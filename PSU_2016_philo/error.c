/*
** error.c for error in /home/lblouard/delivery/Annee2/PSU/PSU_2016_philo
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue Mar 14 16:12:28 2017 Leo Blouard
** Last update Wed Mar 15 13:39:16 2017 clement xia
*/

#include "philo.h"

void	printerr()
{
  fprintf(stderr,"USAGE\n");
  fprintf(stderr,"\t\t./philo [-p][-e]\n");
  fprintf(stderr,"DESCRIPTION\n");
  fprintf(stderr,"\t\t-p\tfollowed by the number of philosophers\n");
  fprintf(stderr,"\t\t-e\tfollowed by the max eat occurence\n");
}
