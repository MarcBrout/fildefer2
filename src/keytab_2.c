/*
** keytab_2.c for fdf2 in /home/brout_m/rendu/projet/Infographie/gfx_fdf2/src
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec 16 21:50:47 2015 marc brout
** Last update Wed Dec 16 21:51:24 2015 marc brout
*/

#include "fdf.h"

t_bunny_response	key_right(t_param *arg)
{
  arg->cur->x += 5;
  return (GO_ON);
}

t_bunny_response	key_up(t_param *arg)
{
  arg->cur->y -= 5;
  return (GO_ON);
}

t_bunny_response	key_down(t_param *arg)
{
  arg->cur->y += 5;
  return (GO_ON);
}

t_bunny_response	key_p(t_param *arg)
{
  arg->cur->zoom += 0.1f;
  return (GO_ON);
}

t_bunny_response	key_m(t_param *arg)
{
  if (arg->cur->zoom > 0.1f)
    arg->cur->zoom -= 0.1f;
  return (GO_ON);
}
