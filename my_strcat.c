/*
** my_strcat.c for strcat in /home/macmil_r/rendu/PSU_2013_minishell1
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Mon Jan  6 14:03:39 2014 a
** Last update Wed Mar  5 15:54:43 2014 a
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int   j;
  char  *str3;

  j = 0;
  i = 0;
  str3 = malloc(sizeof(str3) * (my_strlen(str1) + my_strlen(str2) + 5));
  if (str3 == NULL)
    exit(0);
  while (str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  if (str2 != NULL)
    while (str2[j] != '\0')
      str3[i++] = str2[j++];
  str3[i] = '\0';
  return (str3);
}
