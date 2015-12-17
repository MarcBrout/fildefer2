/*
** filling_process.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 17:45:03 2015 marc brout
** Last update Thu Dec 17 12:21:03 2015 marc brout
*/

#include "fdf.h"

char		fill_pixels(t_param *arg, t_form *scp)
{
  int		i;

  i = -3;
  while (((i += 3) >= 0) && check_trio(arg, scp, i))
    {
      if (add_obj_to_list(scp))
	return (1);
      put_data(arg, scp, &scp->objs->a.pos, i);
      put_color(arg, scp, &scp->objs->a.col, i);
    }
  return (0);
}

char		fill_lines(t_param *arg, t_form *scp)
{
  int		i;

  i = -6;
  while (((i += 6) >= 0) && check_trio(arg, scp, i) &&
	 check_trio(arg, scp, i + 3))
    {
      if (add_obj_to_list(scp))
	return (1);
      put_data(arg, scp, &scp->objs->a.pos, i);
      put_color(arg, scp, &scp->objs->a.col, i);
      put_data(arg, scp, &scp->objs->b.pos, i + 3);
      put_color(arg, scp, &scp->objs->b.col, i + 3);
    }
  return (0);
}

char		fill_polygones(t_param *arg, t_form *scp)
{
  int		i;

  i = -9;
  while (((i += 9) >= 0) && check_trio(arg, scp, i) &&
	 check_trio(arg, scp, i + 3) && check_trio(arg, scp, i + 6))
    {
      if (add_obj_to_list(scp))
	return (1);
      put_data(arg, scp, &scp->objs->a.pos, i);
      put_color(arg, scp, &scp->objs->a.col, i);
      put_data(arg, scp, &scp->objs->b.pos, i + 3);
      put_color(arg, scp, &scp->objs->b.col, i + 3);
      put_data(arg, scp, &scp->objs->c.pos, i + 6);
      put_color(arg, scp, &scp->objs->c.col, i + 6);
    }
  return (0);
}
