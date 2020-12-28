/*
** my_putnbr_base.c for my_putnbr_base in /home/clemsx/UPS/PSU_2016_my_printf
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Wed Nov  9 13:17:12 2016 clement xia
** Last update Thu Nov 10 14:09:19 2016 clement xia
*/

int	my_strlen(char*);
void	my_putchar(char);

char	*rev(char *str)
{
  int	i;
  char	c;

  i = 0;
  while (i < my_strlen(str) / 2)
    {
      c = str[i];
      str[i] = str[my_strlen(str) - 1 - i];
      str[my_strlen(str) - 1 - i] = c;
      i++;
    }
  return (str);
}

void	display_putnbr_base(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_nbr(unsigned int nbr, char *base)
{
  int	i;
  int	j;
  int	k;
  char arr[100];

  i = 0;
  j = my_strlen(base);
  k = 0;
  while (nbr !=  0)
    {
      k = nbr % j;
      nbr = nbr / j;
      arr[i] = base[k];
      i++;
    }
  arr[i] = '\0';
  display_putnbr_base(rev(arr));
}

void	my_putnbr_base(unsigned int nbr, char *base)
{
  unsigned int	i;

  i = 0;
  if (nbr < i && my_strlen(base) > 1)
    {
      my_putchar('-');
      nbr = nbr * (- 1);
      my_nbr(nbr, base);
    }
  else if (nbr == 0)
    my_putchar(48);
  else if (my_strlen(base) == 1 && nbr != 0)
    {
      while (i < nbr)
	{
	  my_putchar(base[0]);
	  i++;
	}
    }
  else
    my_nbr(nbr, base);
}
