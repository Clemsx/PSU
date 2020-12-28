/*
** my_strcat.c for my_strcat in /home/clemsx/Usefull/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov 15 18:26:35 2016 clement xia
** Last update Tue Nov 15 18:28:48 2016 clement xia
*/

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	size;

  i = 0;
  size = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[size + i] = src[i];
      i++;
    }
  dest[size + i] = '\0';
  return (dest);
}
