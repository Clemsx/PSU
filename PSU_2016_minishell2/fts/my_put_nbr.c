/*
** my_put_nbr.c for my_put_nbr in /home/clemsx/Pool/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Oct 31 11:12:22 2016 clement xia
** Last update Tue Nov  8 16:40:23 2016 clement xia
*/

void	my_putchar(char c);

void	my_put_nbr(int nb)
{
  long	nbr;

  nbr = nb;
  if (nb < 0)
    {
      my_putchar('-');
      nbr = -1 * nbr;
    }
  if (nbr >= 10)
    {
      my_put_nbr(nbr / 10);
    }
  my_putchar(48 + (nbr % 10));
}
