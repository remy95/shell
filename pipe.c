/*
** pipe.c for  in /home/macmil_r/rendu/PSU_2013_minishell1
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Mon Feb 24 11:48:13 2014 a
** Last update Sat Mar  8 22:07:47 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	my_exec(char **tab, char **env, char **my_path)
{
  int	i;
  char	*str;

  while (my_path[i] != '\0')
    {
      str = my_strcat(my_path[i], "/");
      str = my_strcat(str, tab[0]);
      execve(str, tab, env);
      i = i + 1;
    }
  exit(my_putstr("Comand not found"));
}

int	my_pipe(char **tab, char **env, char **my_path)
{
  int	pid;

  if ((pid = fork()) == -1)
    exit(write(2, "error on fork\n", my_strlen("error on fork\n")));
  if (pid == 0)
    my_pipe2(tab, env, my_path);
  else if (pid != 0)
    wait(0);
}

int	my_child(char **tab, char **env, char **my_path, int pipefd[2])
{
  if(dup2(pipefd[1], 1) == -1)
    exit(0);
  my_exec(my_str_to_wordtab(tab[0], ' '), env, my_path);
}

int     my_fathe(char **tab, char **env, char **my_path, int pipefd[2])
{
  wait(0);
  close(pipefd[1]);
  if(dup2(pipefd[0], 0) == -1)
    exit(0);
  my_exec(my_str_to_wordtab(tab[1], ' '), env, my_path);
}

int	my_pipe2(char **tab, char **env, char **my_path)
{

  int	pid; 
  int	error;
  int	pipefd[2];

  if ((pid = fork()) == -1)
    exit(write(2, "error on fork\n", my_strlen("error on fork\n")));
  if (pid == 0)
    {
      error = pipe(pipefd);
      if (error == -1)
	exit( write(2, "error on pipe\n", my_strlen("error on pipe\n")));
      if ((pid = fork()) == -1)
        exit(write(2, "error on fork\n", my_strlen("error on fork\n")));
      if (pid == 0)
	my_child(tab, env, my_path, pipefd);
      else if (pid != 0)
	my_fathe(tab, env, my_path, pipefd);
    }
  else
    wait(0);
  exit(0);
}
