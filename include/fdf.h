/*
** fdf.h for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 11 13:21:09 2015 marc brout
** Last update Fri Dec 11 13:54:55 2015 marc brout
*/

#ifndef FDF_H_
# define FDF_H_
# define HEIGHT 768
# define WIDTH 1024

# include "lapin.h"

typedef struct		s_dot
{
  t_bunny_position	pos;
  t_color		col;
}			t_dot;

typedef struct		s_pixels
{
  t_dot			a;
  struct s_pixels	*next;
}			t_pixels;

typedef struct		s_lines
{
  t_dot			a;
  t_dot			b;
  struct s_lines	*next;
}			t_lines;

typedef struct		s_polys
{
  t_dot			a;
  t_dot			b;
  t_dot			c;
  struct s_polys	*next;
}			t_polys;

typedef struct		s_loop
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
}			t_loop;

typedef struct		s_param
{
  t_pixels		*pixels;
  t_lines		*lines;
  t_polys		*polys;
  t_bunny_ini		*ini;
  t_loop		loop;
}			t_param;

#endif
