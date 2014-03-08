/*
** malloc_wordtab.c for malloc in /home/macmil_r/rendu/PSU_2013_minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sat Mar  8 21:29:23 2014 a
** Last update Sat Mar  8 21:49:22 2014 a
*/

#include <stdlib.h>
#include "minishell.h"

char	**my_malloc(char **tab, char *str, char word)
{
  tab = malloc(sizeof(*tab) * ((countchar(str, word) + 1)));
  if (tab == NULL)
    exit(0);
  return (tab);
}

char	*my_malloc2(char *tab, char *str, int i, char word)
{
  tab = malloc(sizeof(tab) * ((count_word(str + i, word) + 1)));
  if (tab == NULL)
    exit(0);
  return (tab);
}
