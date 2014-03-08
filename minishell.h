/*
** minishell.h for minishell in /home/macmil_r/rendu/PSU_2013_minishell1
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Mon Jan  6 16:26:57 2014 a
** Last update Sat Mar  8 22:09:39 2014 a
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

char    *my_read(int fd, int size);
int     minishell(char **env);
char	**my_str_to_wordtab(char *str, char word);
char    **my_malloc(char **tab, char *str, char word);
char    *my_malloc2(char *tab, char *str, int i, char word);
char    **str_to_path(char *str);
int     my_strncmp(char *s1, char *s2, int nb);
char    *my_strcat(char *str1, char *str2);
char	*epure(char *str);
int     my_pipe(char **tab, char **env, char **my_path);
char    point(char **tab, char **env, char **mypath);

#endif /* !MINISHELL_H_ */
