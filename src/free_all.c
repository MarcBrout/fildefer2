/*
** free_all.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 21:29:07 2015 marc brout
** Last update Wed Dec 16 21:54:13 2015 marc brout
*/

#include "fdf.h"

void		free_obj(t_obj *obj)
{
  t_obj		*tmp;
  t_obj		*sav;

  tmp = obj;
  while (tmp->next != NULL)
    {
      sav = tmp->next;
      free(tmp);
      tmp = sav;
    }
  free(tmp);
}

void		free_all(t_param *arg)
{
  t_form	*tmp;
  t_form	*sav;

  tmp = arg->form;
  while (tmp->next != NULL)
    {
      sav = tmp->next;
      free(tmp->name);
      if (tmp->objs != NULL)
	free_obj(tmp->objs);
      free(tmp);
      tmp = sav;
    }
  free(tmp->name);
  if (tmp->objs != NULL)
    free_obj(tmp->objs);
  free(tmp);
  free(arg->keytab);
  free(arg->keyfunc);
}
