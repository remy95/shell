/*
** my_putstr.c for my_putstr in /home/macmil_r/rendu/Piscine-C-Jour_04
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Fri Oct  4 19:16:52 2013 a
** Last update Sat Mar  8 21:50:29 2014 a
*/

int	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}


