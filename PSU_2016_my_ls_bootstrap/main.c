/*
** main.c for main in /home/clemsx/PSU/PSU_2016_my_ls_bootstrap
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Thu Nov 17 14:46:24 2016 clement xia
** Last update Thu Nov 17 17:05:44 2016 clement xia
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	my_printf(char *tmp, ...);
int	my_strlen(char *str);

void	check_type(struct stat info)
{
  if ((info.st_mode & S_IFMT) == S_IFREG)
    my_printf("f\n");
  else if ((info.st_mode & S_IFMT) == S_IFDIR)
    my_printf("d/\n");
  else if ((info.st_mode & S_IFMT) == S_IFCHR)
    my_printf("c\n");
  else if ((info.st_mode & S_IFMT) == S_IFBLK)
    my_printf("b\n");
  else if ((info.st_mode & S_IFMT) == S_IFIFO)
    my_printf("p|\n");
  else if ((info.st_mode & S_IFMT) == S_IFLNK)
    my_printf("l@\n");
  else if ((info.st_mode & S_IFMT) == S_IFSOCK)
    my_printf("s=\n");
}

void	my_minor(struct stat info)
{
  if ((info.st_mode & S_IFMT) != S_IFBLK && (info.st_mode & S_IFMT) != S_IFCHR)
    my_printf("N/A\n");
  else
    my_printf("%d\n", minor(info.st_rdev));
 }

void	my_major(struct stat info)
{
  if ((info.st_mode & S_IFMT) != S_IFBLK && (info.st_mode & S_IFMT) != S_IFCHR)
    my_printf("N/A\n");
  else
    my_printf("%d\n", major(info.st_rdev));
}

void	my_name(char *av)
{
  int	i;

  i = my_strlen(av);
  while (av[i] != '/')
    {
      i--;
    }
  i++;
  while(av[i] != '\0')
    {
      my_printf("%c", av[i]);
      i++;
    }
  my_printf("\n");
}

int	main(int ac, char **av)
{
  struct stat	info;
  
  if (ac == 2)
    {
      stat(av[1], &info);
      my_printf("Name: ");
      my_name(av[1]);
      my_printf("Type: ");
      check_type(info);
      my_printf("Inode : %d\n", info.st_ino);
      my_printf("Hard link: %d\n", info.st_nlink);
      my_printf("Size: %d\n", info.st_size);
      my_printf("Allocated space: %d\n", info.st_blocks * 512);
      my_printf("Minor: ");
      my_minor(info);
      my_printf("Major: ");
      my_major(info);
      my_printf("UID: %d\nGID: %d\n", info.st_uid, info.st_gid);
    }
  else
    my_printf("Erreur");
  return (0);
}
