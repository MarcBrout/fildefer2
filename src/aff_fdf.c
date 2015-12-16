/*
** aff_fdf.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 18:18:02 2015 marc brout
** Last update Wed Dec 16 21:49:25 2015 marc brout
*/

#include "fdf.h"

t_bunny_response	my_keys(t_bunny_event_state state,
				t_bunny_keysym keysym,
				void *data)
{
  t_param		*arg;
  int			i;

  i = -1;
  arg = data;
  if (state == GO_DOWN)
    {
      while (++i < 8 && keysym != arg->keytab[i]);
      if (i < 8)
	return (arg->keyfunc[i](arg));
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
      if (tmp->aff)
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
  arg->cur = arg->form;
  arg->cur->aff = 1;;
  if ((arg->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((arg->win = bunny_start(WIDTH, HEIGHT, 0, "Fil de fer 2")) == NULL)
    return (1);
  if (init_keytab(arg))
    return (1);
  if (set_keyfunc(arg))
    return (1);
  bunny_set_loop_main_function(main_loop);
  bunny_set_key_response(arg->key);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
