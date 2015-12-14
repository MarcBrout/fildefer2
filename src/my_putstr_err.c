/*
** my_putstr_err.c for fdf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Nov 22 05:52:22 2015 marc brout
** Last update Sun Nov 22 18:34:19 2015 marc brout
*/

#include <unistd.h>

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}

void	my_putstr_err(char *str)
{
  while (*str)
    {
      my_putchar_err(*str);
      str++;
    }
}

int	aff_err(int i)
{
  if (i == 1)
    my_putstr_err("Missing Width or Value is 0. Terminating Execution.\n");
  if (i == 2)
    my_putstr_err("Missing Height or Value is 0. Terminating Execution.\n");
  if (i == 3)
    my_putstr_err("Missing Data value. Terminating Execution.\n");
  if (i == 4 || i == 6)
    {
      my_putstr_err("No [Forme1] \"fdf1\" form found. ");
      my_putstr_err("Terminating Execution.\n");
    }
  if (i == 5)
    my_putstr_err("Wrong file input. Terminating Execution.\n");
  return (i);
}
