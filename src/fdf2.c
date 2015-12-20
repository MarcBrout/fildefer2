/*
** fdf2.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 11 13:44:58 2015 marc brout
** Last update Sun Dec 20 16:36:51 2015 marc brout
*/

#include "fdf.h"

char		add_form_to_list(t_param *arg, char *name)
{
  t_form	*elem;

  if (check_scope(arg, name))
    {
      if ((elem = bunny_malloc(sizeof(t_form))) == NULL)
	return (1);
      elem->name = my_strdup(name);
      elem->color = ((FLD(arg->ini, name, COLOR, 0) == NULL) ? 0 : 1);
      elem->objs = NULL;
      elem->aff = 0;
      elem->x = 0;
      elem->y = 0;
      elem->zoom = 1;
      elem->shape = ret_shape(arg, name);
      elem->next = arg->form;
      arg->form = elem;
    }
  return (0);
}

char		const_form_list(t_param *arg)
{
  int		i;
  char		*name;

  i = -1;
  while ((name = (char *)FLD(arg->ini, NULL, "objlist", ++i)) != NULL)
    if (add_form_to_list(arg, name))
      return (1);
  return (0);
}

char		fill_objs(t_param *arg)
{
  t_form	*tmp;

  tmp = arg->form;
  while (tmp != NULL)
    {
      if (fill_this_scope(arg, tmp))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char		launch_fdf(char **av)
{
  t_param	arg;

  arg.form = NULL;
  if (av[1] != NULL)
    {
      if (open_ini(&arg, av))
	return (1);
      if (const_form_list(&arg))
	return (1);
      if (fill_objs(&arg))
	return (1);
    }
  if (generate_cube(&arg))
    return (1);
  if (aff_fdf(&arg))
    return (1);
  free_all(&arg);
  if (av[1] != NULL)
    bunny_delete_ini(arg.ini);
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  if (ev[0] == NULL || ac < 0)
    return (1);
  if (launch_fdf(av))
    return (1);
  return (0);
}
