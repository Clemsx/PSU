/*
** my_ls_l.c for my_ls_l in /home/clemsx/PSU/PSU_2016_my_ls
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Fri Nov 18 17:26:26 2016 clement xia
** Last update Thu Nov 24 19:21:48 2016 clement xia
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>

int	my_printf(char *tmp, ...);
int	my_strlen(char *str);
char	*my_strncpy(char *dest, char *src, int nb);
int	my_putchar(char c);

void	*allocation(int n)
{
  void	*res;

  if ((res = malloc(n)) == NULL)
    exit(1);
  return (res);
}

void	type(mode_t const types)
{
  char	t;
  
  if (S_ISDIR(types))
    t = 'd';
  else if (S_ISREG(types))
    t = '-';
  else if (S_ISCHR(types))
    t = 'c';
  else if (S_ISBLK(types))
    t = 'b';
  else if (S_ISSOCK(types))
    t = 's';
  else if (S_ISFIFO(types))
    t = 'f';
  else if (S_ISLNK(types))
    t = 'l';
  my_putchar(t);
}

void	perm(mode_t const right)
{
  (right & S_IRUSR) ? my_putchar('r') : my_putchar('-');
  (right & S_IWUSR) ? my_putchar('w') : my_putchar('-');
  (right & S_IXUSR) ? my_putchar('x') : my_putchar('-');
  (right & S_IRGRP) ? my_putchar('r') : my_putchar('-');
  (right & S_IWGRP) ? my_putchar('w') : my_putchar('-');
  (right & S_IXGRP) ? my_putchar('x') : my_putchar('-');
  (right & S_IROTH) ? my_putchar('r') : my_putchar('-');
  (right & S_IWOTH) ? my_putchar('w') : my_putchar('-');
  (right & S_IXOTH) ? my_printf("x ") : my_printf("- ");
}

void	my_ls_l()
{
  DIR	*dirt;
  char	*d;
  struct stat	info;
  struct passwd *pwd;
  struct dirent *file;
  struct group	*getgid;

  dirt = opendir(".");
  file = readdir(dirt);
  while ((file = readdir(dirt)) != NULL)
    {
      if ((stat(file->d_name, &info)) == -1)
	exit(1);
      if (((pwd = getpwuid(info.st_uid)) != NULL
	   && (getgid = getgrgid(info.st_gid)) != NULL) && file->d_name[0] != '.')
	{
	  type(info.st_mode);
	  perm(info.st_mode);
	  d = allocation(my_strlen(ctime(&info.st_mtime)));
	  d = my_strncpy(d, &ctime(&info.st_mtime)[4], 12);
	  my_printf("%d %s %s %d %s %s \n", info.st_nlink, pwd->pw_name,
		    getgid->gr_name, info.st_size, d, file->d_name);
	}
    }
  closedir(dirt);
}
