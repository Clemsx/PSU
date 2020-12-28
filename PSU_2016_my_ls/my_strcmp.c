/*
** my_strcmp.c for my_strcmp in /home/clemsx/Usefull/lib/my
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Nov 15 17:59:54 2016 clement xia
** Last update Tue Nov 15 18:03:55 2016 clement xia
*/

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  else if (my_strlen(s2) < my_strlen(s1))
    return (1);
  return (0);
}
