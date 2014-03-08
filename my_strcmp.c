/*
** my_strcmp.c for strcmp in /home/macmil_r/rendu/Piscine-C-lib/my
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sun Jan  5 14:59:29 2014 a
** Last update Sat Mar  8 21:51:23 2014 a
*/

int     my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}
