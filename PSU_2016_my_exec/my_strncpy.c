/*
** my_strncpy.c for my_strncpy in /home/clemsx/Usefull/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov 15 17:30:53 2016 clement xia
** Last update Fri Nov 18 12:28:04 2016 clement xia
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
