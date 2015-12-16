/*
** pos_pixels.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 21:23:50 2015 marc brout
** Last update Wed Dec 16 18:36:52 2015 marc brout
*/

#include "fdf.h"

void			pos_pixel(t_form *form, t_bunny_pixelarray *pix)
{
  t_obj			*tmp;
  t_bunny_position	pos;

  tmp = form->objs;
  while (tmp != NULL)
    {
      pos.x = tmp->a.pos.x;
      pos.y = tmp->a.pos.y;
      pos.x += form->x;
      pos.y += form->y;
      pos.x *= form->zoom;
      pos.y *= form->zoom;      
      tekpixel(pix, &pos, &tmp->a.col);
      tmp = tmp->next;
    }
}

void	set_pos(t_bunny_position *pos, t_dot *dot1, t_dot *dot2,
		 t_color *col)
{
  pos[0].x = dot1->pos.x;
  pos[0].y = dot1->pos.y;
  pos[1].x = dot2->pos.x;
  pos[1].y = dot2->pos.y;
  col[0].full = dot1->col.full;
  col[1].full = dot2->col.full;
}

void	add_pos(t_bunny_position *pos, t_form *form)
{
  pos[0].x += form->x;
  pos[0].y += form->y;
  pos[1].x += form->x;
  pos[1].y += form->y;
  pos[0].x *= form->zoom;
  pos[0].y *= form->zoom;
  pos[1].x *= form->zoom;
  pos[1].y *= form->zoom;
}

void			pos_line(t_form *form, t_bunny_pixelarray *pix)
{
  t_obj			*tmp;
  t_bunny_position	pos[2];
  t_color		col[2];

  tmp = form->objs;
  while (tmp != NULL)
    {
      set_pos(pos, &tmp->a, &tmp->b, col);
      add_pos(pos, form);
      tekline(pix, pos, col);
      tmp = tmp->next;
    }
}

void			pos_poly(t_form *form, t_bunny_pixelarray *pix)
{
  t_obj			*tmp;
  t_bunny_position	pos[2];
  t_color		col[2];

  tmp = form->objs;
  while (tmp != NULL)
    {
      set_pos(pos, &tmp->a, &tmp->b, col);
      add_pos(pos, form);
      tekline(pix, pos, col);
      set_pos(pos, &tmp->b, &tmp->c, col);
      add_pos(pos, form);
      tekline(pix, pos, col);
      set_pos(pos, &tmp->c, &tmp->a, col);
      add_pos(pos, form);
      tekline(pix, pos, col);
      tmp = tmp->next;
    }
}
