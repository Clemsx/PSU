/*
** sum_stdarg.c for stdarg in /home/clemsx/UPS/PSU_2016_my_printf_bootstrap
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov  8 14:52:26 2016 clement xia
** Last update Tue Nov  8 16:41:00 2016 clement xia
*/

#include <stdarg.h>

int	my_strlen(char *str);

int	sum_str(va_list arg, int nb)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (i < nb)
    {
      count = count + my_strlen(va_arg(arg, char *));
      i++;
    }
  va_end(arg);
  return (count);
}

int	sum_int(va_list arg, int nb)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (i < nb)
    {
      count = count + va_arg(arg, int);
      i++;
    }
  va_end(arg);
  return (count);
}

int	sum_stdarg(int i, int nb, ...)
{
  va_list	arg;

  va_start(arg, nb);
  if (i == 0)
    {
      return (sum_int(arg, nb));
    }
  else if (i == 1)
    {
      return (sum_str(arg, nb));
    }
  else
    {
      return (84);
    }
}
