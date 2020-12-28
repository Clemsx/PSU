/*
** main.c for main in /home/clemsx/PSU/PSU_2016_my_exec
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon Nov 21 11:06:55 2016 clement xia
** Last update Wed Nov 23 11:57:43 2016 clement xia
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int	my_putstr(char *str);
int	my_printf(char *tmp, ...);
char	**my_str_to_wordtab(char *str);

char	*my_prog_name(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 32)
    {
      str[i] = str[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

int	main(int ac, char *av[])
{
  pid_t forch;
  int	status;
  char	*newenv[] = { NULL };
  char	**newarg;

  newarg = my_str_to_wordtab(av[1]);
  my_printf("%s - %d\n", av[0], ac);
  my_printf("Program name : %s\n", my_prog_name(av[1]));
  my_printf("Nb args : \n");
  my_printf("PID : %d\n", getpid());
  if ((forch = fork()) == 0)
    {
      my_printf("Child PID : %d\n", forch);
      execve(my_prog_name(av[1]), newarg, newenv);
    }
  else
    {
      wait(&status);
      if (WIFEXITED(status))
	{
	  my_printf("Program terminated\n");
	  my_printf("Status : OK\n");
	}
    }
  return (0);
}
