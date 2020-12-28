/*
** display2.c for display2 in /home/lblouard/delivery/Annee2/PSU/PSU_2016_myirc/clientDir
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Mon May 29 14:17:49 2017 Leo Blouard
** Last update Mon May 29 14:23:10 2017 Leo Blouard
*/

#include "client.h"

void	helpPart()
{
  printf("USAGE: /part $channel\n");
}

void    helpUsers()
{
  printf("USAGE: /users\n");
}

void    helpName()
{
  printf("USAGE: /names $channel\n");
}

void    helpMsg()
{
  printf("USAGE: /msg $nickname $message\n");
  printf("       /msg $channel $nickname $file\n");
}

void    helpAccept()
{
  printf("USAGE: /accept_file $nickname\n");
}
