/*
** my_putchar.c for putchar in /home/clemsx/Pool/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Oct 31 11:50:34 2016 clement xia
** Last update Mon Nov 14 11:16:03 2016 clement xia
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
