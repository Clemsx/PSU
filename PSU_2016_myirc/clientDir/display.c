/*
** display.c for display in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Tue May 23 14:34:47 2017 Leo Blouard
** Last update Mon May 29 14:17:38 2017 Leo Blouard
*/

#include "client.h"

void    helpme()
{
  printf("USAGE: ./client host port\n");
}

void	helpNick()
{
  printf("USAGE: /nick $nickname\n");
}

void	helpServer()
{
  printf("USAGE: /server $host[$port]\n");
}

void	helpList()
{
  printf("USAGE: /list [$string]\n");
}

void	helpJoin()
{
  printf("USAGE: /join $channel");
}
