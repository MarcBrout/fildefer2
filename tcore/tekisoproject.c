/*
** tekisoproject.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 12:55:58 2015 marc brout
** Last update Tue Dec 15 16:44:11 2015 marc brout
*/

#include "fdf.h"

void	tekisoproject(t_bunny_position *out, int x, int y, int z)
{
  float	cnt;

  cnt = 0.5f;
  out->x = x + y;
  out->y = z - cnt * y + cnt * x;
}
