/*
** parseCmd.c for parseCmd in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Wed May 31 12:32:50 2017 Leo Blouard
** Last update Wed May 31 17:46:56 2017 Leo Blouard
*/

#include "client.h"

char	**parse(char *cmd)
{
  char  **newcmd;
  int   i;
  int	j;
  int	k;
  
  i = 0;
  j = 0;
  k = 0;
  newcmd = malloc(2048);
  while (cmd[i])
    {
      if (cmd[i] == '/')
	{
	  newcmd[k] = malloc(2048);
	  while (cmd[i] != '\0' && cmd[i] != ' ')
	    {
	      newcmd[k][j] = cmd[i];
	      j++;
	      i++;
	    }
	  newcmd[k][j] = '\0';
	  k++;
	  j = 0;
	}
      i++;
    }
  newcmd[k] = '\0';
  return (newcmd);
}

char	**parseParam(char *cmd)
{
  char	**params;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  params = malloc(2048);
  while (cmd[i] != ' ')
    i++;
  i++;
  while (cmd[i] != '\0')
    {
      while (cmd[i] == ' ')
	i++;
      params[k] = malloc(4048);
      while (cmd[i] != ' ' && cmd[i] != '\0')
	{
	  if (cmd[i] == '[')
	    {
	      i++;
	      break;
	    }
	  if (cmd[i] != ']')
	    params[k][j] = cmd[i];
	  j++;
	  i++;
	}
      i  -= 1;
      params[k][j] = '\0';
      k++;
      j = 0;
      i++;
    }
  params[k] = '\0';
  return (params);
}
