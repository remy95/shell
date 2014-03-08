/*
** my_strlen.c for strlen in /home/macmil_r/rendu/PSU_2013_minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sat Mar  8 21:53:54 2014 a
** Last update Sat Mar  8 21:54:18 2014 a
*/

int	my_strlen(char *str)
{
  int	b;

  b = 0;
  while (str[b] != '\0')
   {
     b = b + 1;
   }
  return (b);
}
