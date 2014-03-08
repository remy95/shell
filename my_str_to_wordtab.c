/*
** my_str_to_wordtab.c for wordtab in /home/macmil_r/rendu/PSU_2013_minishell1
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Thu Jan  2 12:23:46 2014 a
** Last update Sat Mar  8 21:53:32 2014 a
*/

#include <stdlib.h>
#include "minishell.h"

int     count_word(char *str, char word)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == word && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int     countchar(char *str, char word)
{
  int	c;

  c = 0;
  while ((str[c] != word) && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

char    **my_tab(char *str, char word, int a)
{
  char	**tab;
  int	i;
  int	b;

  b = 0;
  i = 0;
  tab = my_malloc(tab, str, word);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == word || str[i] == '\n')
        {
          while (str[i] == word)
            i++;
          a = a + 1;
          b = 0;
        }
      tab[a] = my_malloc2(tab[a], str, i, word);
      while ((str[i] != word)  && (str[i] != '\n') && (str[i] != '\0'))
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}

char    **my_str_to_wordtab(char *tmp, char word)
{
  char	*str;
  int	a;
  char	**tab;

  str = epure(tmp);
  a = 0;
  tab = my_tab(str, word, a);
  return (tab);
}
