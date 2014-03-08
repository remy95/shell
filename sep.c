/*
** sep.c for sep in /home/macmil_r/rendu/minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Fri Mar  7 12:09:03 2014 a
** Last update Sat Mar  8 21:54:46 2014 a
*/

#include "minishell.h"

char	point(char **tab, char **env, char **mypath)
{
  int	i;
  char	**word;

  i = 0;
  while (tab[i] != '\0')
    {
      word = my_str_to_wordtab(tab[i], ' ');
      pid(word, env, mypath);
      i = i + 1;
    }
}
