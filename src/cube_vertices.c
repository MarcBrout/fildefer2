/*
** cube_vertices.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec 15 16:32:02 2015 marc brout
** Last update Tue Dec 15 17:09:27 2015 marc brout
*/

#include "fdf.h"

void		add_dota(t_obj *obj, int x, int y, int z)
{
  tekisoproject(&obj->a.pos, x, y, z);
  obj->a.pos.x += WIDTH / 2;
  obj->a.pos.y += HEIGHT / 2;
  obj->a.col.full = DEFAULT_COL;
}

void		add_dotb(t_obj *obj, int x, int y, int z)
{
  tekisoproject(&obj->b.pos, x, y, z);
  obj->b.pos.x += WIDTH / 2;
  obj->b.pos.y += HEIGHT / 2;
  obj->b.col.full = DEFAULT_COL;
}

void		facea(t_obj *cube, int cns)
{
  t_obj		*vertice;

  vertice = cube;
  add_dota(vertice, -cns, cns, -cns);
  add_dotb(vertice, cns, cns, -cns);
  vertice = vertice->next;
  add_dota(vertice, cns, cns, -cns);
  add_dotb(vertice, cns, -cns, -cns);
  vertice = vertice->next;
  add_dota(vertice, cns, -cns, -cns);
  add_dotb(vertice, -cns, -cns, -cns);
  vertice = vertice->next;
  add_dota(vertice, -cns, -cns, -cns);
  add_dotb(vertice, -cns, cns, -cns);
}

void		faceb(t_obj *cube, int cns)
{
  t_obj		*vertice;

  vertice = cube;
  add_dota(vertice, -cns, cns, cns);
  add_dotb(vertice, cns, cns, cns);
  vertice = vertice->next;
  add_dota(vertice, cns, cns, cns);
  add_dotb(vertice, cns, -cns, cns);
  vertice = vertice->next;
  add_dota(vertice, cns, -cns, cns);
  add_dotb(vertice, -cns, -cns, cns);
  vertice = vertice->next;
  add_dota(vertice, -cns, -cns, cns);
  add_dotb(vertice, -cns, cns, cns);
}

void		diags(t_obj *cube, int cns)
{
  t_obj		*vertice;

  vertice = cube;
  add_dota(vertice, -cns, cns, -cns);
  add_dotb(vertice, -cns, cns, cns);
  vertice = vertice->next;
  add_dota(vertice, cns, cns, -cns);
  add_dotb(vertice, cns, cns, cns);
  vertice = vertice->next;
  add_dota(vertice, cns, -cns, -cns);
  add_dotb(vertice, cns, -cns, cns);
  vertice = vertice->next;
  add_dota(vertice, -cns, -cns, -cns);
  add_dotb(vertice, -cns, -cns, cns);
}
