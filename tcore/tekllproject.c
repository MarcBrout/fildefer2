/*
** tekllproject.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov 18 12:55:58 2015 marc brout
** Last update Sun Nov 22 04:38:58 2015 marc brout
*/

#include "../include/fdf.h"

void	tekllproject(t_bunny_position *out, int x, int y, int z)
{
  out->x = x / 2 + y;
  out->y = -z + y;
}
