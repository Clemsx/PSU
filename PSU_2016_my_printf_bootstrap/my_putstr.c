/*
** my_putstr.c for my_putstr in /home/clemsx/delivery/CPool_Day04
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Oct  6 12:01:49 2016 clement xia
** Last update Tue Nov  8 16:38:06 2016 clement xia
*/

void	my_putchar(char c);

void	my_putstr(char	*str)
{
  int	i;

  i = 0;
  while(str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
