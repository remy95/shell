/*
** epure.c for epure in /home/macmil_r/rendu/minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Fri Mar  7 11:28:22 2014 a
** Last update Sat Mar  8 21:47:45 2014 a
*/

char	*epure(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while (str[i] == ' ' && str[i] != '\0')
    {
      str[i] = '\0';
      i = i - 1;
    }
  while (*str == ' ' && *str != '\0')
    str = str + 1;
  return (str);
}
