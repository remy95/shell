/*
** main.c for main in /home/macmil_r/rendu/PSU_2013_minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sat Mar  8 21:34:48 2014 a
** Last update Sat Mar  8 21:44:35 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int     other_function(char **tab, char **env)
{
  if (my_strncmp("cd", tab[0], 2) == 0)
    {
      chdir(tab[1]);
      return (1);
    }
  else if (my_strncmp("exit", tab[0], 4) == 0)
    exit(0);
  else
    return (0);
}

char    operation(char *buff)
{
  int   i;
  
  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '|')
        return ('|');
      if (buff[i] == ';')
        return (';');
      i = i + 1;
    }
  return (' ');
}

int     main(int ac, char **av, char **env)
{
  minishell(env);
}
