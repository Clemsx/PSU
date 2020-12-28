/*
** my_printf.h for my_printf in /home/clemsx/Usefull/my_printf
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Nov 28 11:42:57 2016 clement xia
** Last update Sun Dec 18 14:31:24 2016 clement xia
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

int	my_printf(const char *tmp, ...);
int	my_putchar(char c);
int	my_strlen(char *str);
void	my_put_nbr(int nb);
int	my_putnbr_base(int nbr, char *base);
void	my_puthexa(unsigned long nb, char *base);
int	my_putstr(char *str);

#endif /* !MY_PRINTF_H_ */
