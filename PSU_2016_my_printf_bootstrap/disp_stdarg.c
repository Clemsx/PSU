/*
** disp_stdarg.c for disp_stdarg in /home/clemsx/UPS/PSU_2016_my_printf_bootstrap
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov  8 14:53:11 2016 clement xia
** Last update Tue Nov  8 16:21:30 2016 clement xia
*/

#include <stdarg.h>

int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);

int	disp_stdarg(char *s, ...)
{
  int	i;
  va_list	arg;

  i = 0;
  va_start(arg, s);
  while (s[i] != '\0')
    {
      if (s[i] == 'c')
	my_putchar((char) va_arg(arg, int));
      else if (s[i] == 's')
	my_putstr(va_arg(arg, char *));
      else if (s[i] == 'i')
	my_put_nbr(va_arg(arg, int));
      else
	return (84);
      my_putchar('\n');
      i++;
    }
  va_end(arg);
  return (0);
}
