/*
** my_ftp.h for ftp in /home/clemsx/Tek2/PSU/PSU_2016_myftp
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Mon May 15 12:29:57 2017 clement xia
** Last update Sun May 21 11:23:44 2017 clement xia
*/

#ifndef MY_FTP_H_
# define MY_FTP_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

# define UNUSED(x) (void)(x)

typedef struct		s_server
{
  struct sockaddr_in	server_add;
  int			socket_id;
}			t_server;

typedef struct		s_client
{
  struct sockaddr_in	client_add;
  int			socket_id;
  unsigned int		size;
}			t_client;

typedef struct		s_custom
{
  int			port;
  char			*ip;
  int			pass_client;
  int			pass_socket;
  char			*log;
  int			connected;
  int			logged;
  int			mode;
  char			*path;
  char			*path_parent;
  int			socket_id;
}			t_custom;

/* server.c */
int		start_server(t_server *server, t_client *client, int port, char *path);

/* client.c */
t_client	*init_client(t_client *client);

/* manager.c */
int		invite_cmd(t_client *client, char *path);

/* cmd.c */
int		list_cmd2(char *cmd, t_custom *custom);
int		list_cmd(char *cmd, t_custom *custom);
int		good_bye(t_custom *custom);

/* cmd2.c */
int		help(t_custom *custom);
int		cwd(t_custom *custom, char *cmd);
int		pwd(t_custom *custom);
int		noop(t_custom *custom);
int		cdup(t_custom *custom);

/* cmd3.c */
int		dele(t_custom *custom, char *cmd);
int		pasv(t_custom *custom);

/* port.c */
int		port(t_custom *custom);

/* retr.c */
int		retr(t_custom *custom, char *cmd);
int		stop_block_me(t_custom *custom);

/* stor.c */
int		stor(t_custom *custom, char *cmd);

/* tool.c */
int		is_connected(t_custom *custom, char *cmd);
int		connected_cmd(t_custom *custom, char *cmd);
char		*replace_ip(char *ip);

/* parsing.c */
char		*get_parameter(char *cmd);
char		*get_cmd(char *cmd);

char		*get_next_line(const int fd);

/* list.c */
int		list(t_custom *custom, char *cmd);

#endif /* !MY_FTP_H_ */
