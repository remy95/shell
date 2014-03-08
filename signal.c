/*
** signal.c for signal in /home/macmil_r/rendu/PSU_2013_minishell2
** 
** Made by a
** Login   <macmil_r@epitech.net>
** 
** Started on  Sat Mar  8 21:56:40 2014 a
** Last update Sat Mar  8 21:57:00 2014 a
*/

#include <signal.h>

void	prompter()
{
  my_putstr("\n$> ");
}

void	my_signal()
{
  signal(SIGTSTP, prompter);
  signal(SIGQUIT, prompter);
  signal(SIGINT, prompter);
}
