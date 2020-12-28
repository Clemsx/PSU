/*
** my_printf.c for my_printf in /home/clemsx/UPS/PSU_2016_my_printf
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov  8 14:28:40 2016 clement xia
** Last update Sun Dec 11 14:33:35 2016 clement xia
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/my_printf.h"

int	my_putstr_np(va_list ap);

int	check_flag_nb(const char *tmp, int i, va_list ap)
{
  int	j;

  if (tmp[i + 1] == 'd' || tmp[i + 1] == 'i')
      my_put_nbr(va_arg(ap, int));
  else if (tmp[i + 1] == 'l' && tmp[i + 2] == 'd')
    {
      my_put_nbr(va_arg(ap, int));
      i++;
    }
  else if (tmp[i + 1] == 'h' && tmp[i + 2] == 'd')
    {
      my_put_nbr(va_arg(ap, int));
      i++;
    }
  else if (tmp[i + 1] == 'c')
    j = my_putchar((char) va_arg(ap, int));
  else if (tmp[i + 1] == 's')
    j = my_putstr(va_arg(ap , char *));
  else if (tmp[i + 1] == 'S')
    j = my_putstr_np(ap);
  return (j);
}

int	check_flag_base(const char *tmp, int i, va_list ap)
{
  char	*hexa_min = "0123456789abcdef";
  char	*hexa_max = "0123456789ABCDEF";
  
  if (tmp[i + 1] == 'p')
    {
      my_putstr("0x");
      my_puthexa(va_arg(ap, unsigned long), hexa_min);
    }
  else if (tmp[i + 1] == 'x' || tmp[i + 1] == 'X')
    my_putnbr_base(va_arg(ap, unsigned int), (tmp[i + 1] == 'x' ? hexa_min : hexa_max));
  else if (tmp[i + 1] == 'b')
    my_putnbr_base(va_arg(ap, unsigned int), "01");
  else if (tmp[i + 1] == 'o')
    my_putnbr_base(va_arg(ap, unsigned int), "01234567");
  return (i);
}

int	check_flag_special(const char *tmp, int i)
{
  if (tmp[i + 1] != 'c' && tmp[i + 1] != 's' && tmp[i + 1] != 'S' &&
      tmp[i + 1] != 'd' && tmp[i + 1] != 'i' && tmp[i + 1] != 'l' &&
      tmp[i + 1] != 'h' && tmp[i + 1] != 'p' && tmp[i + 1] != 'x' &&
      tmp[i + 1] != 'X' && tmp[i + 1] != 'b' && tmp[i + 1] != 'o' &&
      tmp[i + 1] != '%')
    {
      my_putchar(tmp[i]);
      my_putchar(tmp[i + 1]);
    }
  else if (tmp[i + 1] == '%')
    {
      my_putchar(tmp[i + 1]);
    }
  return (i);
}

int	my_printf(const char *tmp, ...)
{
  va_list	ap;
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  va_start(ap, tmp);
  while (tmp[i] != '\0')
    {
      if (tmp[i] == '%')
	{
	  k += check_flag_nb(tmp, i, ap);
	  check_flag_base(tmp, i, ap);
	  check_flag_special(tmp, i);
	  i++;
	  j++;
	}
      else
	my_putchar(tmp[i]);
      i++;
    }
  va_end(ap);
  return (j != 0) ? (i - j + k) : (i + k); 
}
