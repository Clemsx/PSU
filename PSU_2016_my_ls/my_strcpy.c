/*
** my_strcpy.c for my_strcpy in /home/clemsx/Usefull/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov 15 17:27:39 2016 clement xia
** Last update Tue Nov 15 18:42:04 2016 clement xia
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
