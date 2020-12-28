/*
** tools.c for tools in /home/clemsx/UPS/PSU_2016_my_printf
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Sat Nov 12 10:05:14 2016 clement xia
** Last update Mon Nov 14 12:05:53 2016 clement xia
*/

#include <stdarg.h>

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putnbr_base(int nbr, char *base);

void    my_puthexa(unsigned long nb, char *base)
{
  unsigned long  beg;
  unsigned long  res;

  res = nb % 16;
  beg = (nb - res) / 16;
  if (beg)
    {
      my_puthexa(beg, base);
    }
  my_putchar(base[res]);
}

int    my_putstr_np(va_list ap)
{
  int   i;
  char  *str;

  i = 0;
  str = va_arg(ap, char *);
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  if (str[i] < 8)
	    my_putstr("00");
	  else if (str[i] < 32)
	    my_putstr("0");
	  my_putnbr_base(str[i], "01234567");
	}
      i++;
    }
  return (i - 1);
}
