/*
** fdf2.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 11 13:44:58 2015 marc brout
** Last update Fri Dec 11 13:58:31 2015 marc brout
*/

#include "fdf.h"

char		launch_fdf(char **av)
{
  t_param	arg;

  arg.pixels = NULL;
  arg.lines = NULL;
  arg.polys = NULL;

}

int		main(int ac, char **av, char **ev)
{
  if (ac > 2)
    return (1);
  if (ev[0] == NULL)
    return (1);
  if (launch_fdf(av))
    return (1);
  return (0);
}
