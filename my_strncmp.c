/*
** my_strcmp.c for strcmp in /home/macmil_r/rendu/Piscine-C-lib/my
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sun Jan  5 14:59:29 2014 a
** Last update Mon Jan  6 13:39:27 2014 a
*/

int     my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && i < nb - 1)
    i++;
  return (s1[i] - s2[i]);
}
