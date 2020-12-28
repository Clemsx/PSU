/*
** my.h for minishell1 in /home/clemsx/PSU/PSU_2016_minishell1/include
** 
** Made by clement xia
** Login   <clemsx@epitech.net>
** 
** Started on  Tue Dec 13 14:04:06 2016 clement xia
** Last update Sun Dec 18 14:30:30 2016 clement xia
*/

#ifndef MY_H_
# define MY_H_

char	*my_strcmp(char *s1, char *s2);
void	put_env(char **env);
void	builtins(char *str, char **env);
char	*find_path(char **env);
char	**my_str_to_wordtab(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
void	display_env(char **env);
char	*my_strncpy(char *dest, char *src);
char	**get_env(char **env);
int	tab_len(char **env);
char	**set_env(char *s, char **env);
char	*my_strcpy(char *dest, char *src);
char	**unset_env(char *s, char **env);
char	**get_env(char **env);
void	my_cd(char *pathfile);

#endif /* !MY_H_ */
