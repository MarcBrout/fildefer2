/*
** aff_fdf.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 18:18:02 2015 marc brout
** Last update Mon Dec 14 21:51:19 2015 marc brout
*/

#include "fdf.h"

t_bunny_response	my_keys(t_bunny_event_state state,
				t_bunny_keysym keysym,
				void *data)
{
  if (keysym == BKS_ESCAPE)
    if (state == GO_DOWN)
      {
	(void)data;
	return (EXIT_ON_SUCCESS);
      }
  return (GO_ON);
}

t_bunny_response	main_loop(void *data)
{
  t_param		*arg;
  t_form		*tmp;

  arg = data;
  background(arg);
  tmp = arg->form;
  while (tmp != NULL)
    {
      tmp->func(tmp, arg->pix);
      tmp = tmp->next;
    }
  bunny_blit(&arg->win->buffer, &arg->pix->clipable, NULL);
  bunny_display(arg->win);
  return (GO_ON);
}

void		background(t_param *arg)
{
  int		i;
  t_color	*pixels;
  int		total;

  total = WIDTH * HEIGHT;
  pixels = arg->pix->pixels;
  i = -1;
  while (++i < total)
    pixels[i].full = BACKGROUND;
}

char		aff_fdf(t_param *arg)
{
  arg->key = &my_keys;
  if ((arg->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((arg->win = bunny_start(WIDTH, HEIGHT, 0, "Fil de fer 2")) == NULL)
    return (1);
  bunny_set_loop_main_function(main_loop);
  bunny_set_key_response(arg->key);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
