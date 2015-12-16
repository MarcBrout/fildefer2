/*
** cube.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec 15 13:50:24 2015 marc brout
** Last update Wed Dec 16 18:08:03 2015 marc brout
*/

#include "fdf.h"

char		add_vert_to_cube(t_form *cube)
{
  t_obj		*vertice;

  if ((vertice = malloc(sizeof(t_obj))) == NULL)
    return (1);
  vertice->next = cube->objs;
  cube->objs = vertice;
  return (0);
}

char		create_list(t_form *cube)
{
  int		i;

  i = 13;
  while (--i > 0)
    if (add_vert_to_cube(cube))
      return (1);
  return (0);
}

void		trace_cube(t_param *arg)
{
  t_obj		*vertice;

  vertice = arg->form->objs;
  facea(vertice, PAS);
  vertice = vertice->next->next->next->next;
  diags(vertice, PAS);
  vertice = vertice->next->next->next->next;
  faceb(vertice, PAS);
}

char		init_cube_scope(t_param *arg)
{
  t_form	*cube;

  if ((cube = malloc(sizeof(t_form))) == NULL)
    return (1);
  cube->shape = 2;
  cube->color = 0;
  cube->aff = 0;
  cube->x = 0;
  cube->y = 0;
  cube->zoom = 1;
  cube->func = &pos_line;
  cube->name = my_strdup("cube");
  cube->objs = NULL;
  cube->next = arg->form;
  arg->form = cube;
  return (0);
}

char		generate_cube(t_param *arg)
{
  if (init_cube_scope(arg))
    return (1);
  if (create_list(arg->form))
    return (1);
  trace_cube(arg);
  return (0);
}
