/*
** tekline.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:29:29 2015 marc brout
** Last update Wed Dec 16 22:08:16 2015 marc brout
*/

#include "fdf.h"

void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *pos,
		t_color	*color)
{
  float	a;
  int	b;
  int	c;

  a = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  b = (float)(pos[0].y - a * pos[0].x);
  while (pos[0].x != pos[1].x)
    {
      tekpixel(pix, pos, &color[0]);
      pos[0].x += ((pos[0].x > pos[1].x) ? -1 : 1);
      c = a * pos[0].x + b;
      while (pos[0].y != c && pos[0].y != pos[1].y)
	{
	  tekpixel(pix, pos, &color[0]);
	  pos[0].y += (pos[0].y > c) ? -1 : 1;
	}
    }
  while (pos[0].y != pos[1].y && pos[0].x == pos[1].x)
    {
      tekpixel(pix, pos, &color[0]);
      pos[0].y += (pos[0].y > pos[1].y) ? -1 : 1;
    }
}
