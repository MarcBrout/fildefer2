/*
** tekisoproject.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 12:55:58 2015 marc brout
** Last update Thu Dec 17 10:57:34 2015 marc brout
*/

#include "lapin.h"

void	tekisoproject(t_bunny_position *out, int x, int y, int z)
{
  float	cnt;

  cnt = 0.5f;
  out->x = x + y;
  out->y = z - cnt * y + cnt * x;
}
