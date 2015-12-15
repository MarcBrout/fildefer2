/*
** check_scope.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 14 11:34:11 2015 marc brout
** Last update Tue Dec 15 18:45:45 2015 marc brout
*/

#include "fdf.h"

char		check_scope(t_param *arg, char *name)
{
  if (FLD(arg->ini, name, "type", 0) == NULL ||
      my_strcmp(FLD(arg->ini, name, "type", 0), TYPE))
    return (0);
  if (FLD(arg->ini, name, DATA, 0) == NULL)
    return (0);
  if (FLD(arg->ini, name, SHAPE, 0) == NULL ||
      (my_strcmp(FLD(arg->ini, name, SHAPE, 0), PIXEL) &&
       my_strcmp(FLD(arg->ini, name, SHAPE, 0), LINE) &&
       my_strcmp(FLD(arg->ini, name, SHAPE, 0), POLY)))
    return (0);
  return (1);
}

char		ret_shape(t_param *arg, char *name)
{
  if (!(my_strcmp(FLD(arg->ini, name, SHAPE, 0), PIXEL)))
    return (1);
  if (!(my_strcmp(FLD(arg->ini, name, SHAPE, 0), LINE)))
    return (2);
  if (!(my_strcmp(FLD(arg->ini, name, SHAPE, 0), POLY)))
    return (3);
  return (0);
}

char		open_ini(t_param *arg, char **av)
{
  if ((arg->ini = bunny_load_ini(av[1])) == NULL)
    return (1);
  if (FLD(arg->ini, NULL, "objlist", 0) == NULL)
    return (2);
  return (0);
}

