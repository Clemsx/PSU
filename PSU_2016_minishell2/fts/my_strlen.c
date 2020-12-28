/*
** my_strlen.c for my_strlen in /home/clemsx/delivery/CPool_Day04
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Oct  6 12:55:24 2016 clement xia
** Last update Sun Dec 18 14:27:41 2016 clement xia
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
