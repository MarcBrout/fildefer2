/*
** fill_obj.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 12:03:47 2015 marc brout
** Last update Sun Dec 20 16:36:27 2015 marc brout
*/

#include "fdf.h"

char		check_trio(t_param *arg, t_form *scp, int i)
{
  if (FLD(arg->ini, scp->name, DATA, i) == NULL ||
      FLD(arg->ini, scp->name, DATA, i + 1) == NULL ||
      FLD(arg->ini, scp->name, DATA, i + 2) == NULL)
    return (0);
  if (scp->color)
    if (FLD(arg->ini, scp->name, COLOR, i / 3) == NULL)
      return (0);
  return (1);
}

char		add_obj_to_list(t_form *scope)
{
  t_obj		*elem;

  if ((elem = bunny_malloc(sizeof(t_obj))) == NULL)
    return (1);
  elem->next = scope->objs;
  scope->objs = elem;
  return (0);
}

void		put_data(t_param *arg, t_form *scp, t_bunny_position *pos,
			 int i)
{
  tekisoproject(pos,
		my_getnbr(FLD(arg->ini, scp->name, DATA, i)),
		my_getnbr(FLD(arg->ini, scp->name, DATA, i + 1)),
		my_getnbr(FLD(arg->ini, scp->name, DATA, i + 2)));
  pos->x += WIDTH / 2;
  pos->y += HEIGHT / 2;
}

void		put_color(t_param *arg, t_form *scp, t_color *col, int i)
{
  if (scp->color)
    col->full = my_getnbr(FLD(arg->ini, scp->name, DATA, i));
  else
    col->full = DEFAULT_COL;
}

char		fill_this_scope(t_param *arg, t_form *scope)
{
  char		ret;

  ret = 0;
  if (scope->shape == 1)
    {
      ret = fill_pixels(arg, scope);
      scope->func = &pos_pixel;
    }
  if (scope->shape == 2)
    {
      ret = fill_lines(arg, scope);
      scope->func = &pos_line;
    }
  if (scope->shape == 3)
    {
      ret = fill_polygones(arg, scope);
      scope->func = &pos_poly;
    }
  return (ret);
}
