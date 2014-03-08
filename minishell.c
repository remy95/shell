/*
** minishell.c for minishell in /home/macmil_r/rendu/PSU_2013_minishell1
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Fri Dec 13 16:45:11 2013 a
** Last update Sat Mar  8 21:47:15 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char     **path(char **tab, char **env)
{
  int	i;
  char	*str;
  char	**str1;

  i = 0;
  while (env[i] != '\0')
    {
      if (my_strncmp("PATH=", env[i], 5) == 0)
	str = env[i];
      i = i + 1;
    }
  while (*str != '=')
    str = str + 1;
  str = str + 1;
  str1 = my_str_to_wordtab(str, ':');
  return (str1);
}

char	pid(char **tab, char **env, char **mypath)
{
  int	i;
  char	*str;
  pid_t	pid;
  int	ret;

  ret = other_function(tab, env);
  if ((pid = fork()) == -1)
    exit(my_putstr("Fork problem"));
  i = 0;
  if (pid == 0)
    {
      while (mypath[i] != '\0')
	{
	  str = my_strcat(mypath[i], "/");
	  str = my_strcat(str, tab[0]);
	  execve(str, tab, env);
	  i = i + 1;
	}
      if (ret == 0)
	my_putstr("Shell did not recognize your comand\n");
    }
  else
    wait(0);
}

char	*my_copy(char buff[50000])
{
  int	i;
  char	*str;

  i = 0;
  str = malloc(sizeof(char) * 50000);
  while (buff[i] != '\0')
    {
      str[i] = buff[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

char    *my_read(int fd, int size)
{
  int   ret;
  int   i;
  char  buff[50000];
  char  *str;

  i = 0;
  ret = read(fd, buff, size);
  if (ret == 0 || ret == -1)
    exit(0);
  if (buff == NULL)
    exit(my_putstr("read not executable"));
  if (ret < 2)
    return (NULL);
  if (ret > 1)
    {
      while (buff[i] != '\0')
        {
          if (buff[i] == '\n')
            buff[i] = '\0';
          i = i + 1;
        }
    }
  str = my_copy(buff);
  return (str);
}

int     minishell(char **env)
{
  char  *buff;
  char  **tab;
  char  **mypath;
  int   ret;
  char  op;

  my_putstr("$>");
  my_signal();
  while (buff = my_read(0, 49999))
    {
      if (buff != NULL)
        {
          op = operation(buff);
          tab = my_str_to_wordtab(buff, op);
          mypath = path(tab, env);
          if (op == ';')
            point(tab, env, mypath);
          else if (op == '|' && tab[1] != '\0')
            my_pipe(tab, env, mypath);
          else if (op == ' ')
            pid(tab, env, mypath);
        }
      my_putstr("$>");
    }
}
