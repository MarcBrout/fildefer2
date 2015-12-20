/*
** keytab.c for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec 16 18:55:56 2015 marc brout
** Last update Sun Dec 20 16:36:17 2015 marc brout
*/

#include "fdf.h"

char			init_keytab(t_param *arg)
{
  t_bunny_keysym	*keytab;

  if ((keytab = bunny_malloc(sizeof(t_bunny_keysym) * 9)) == NULL)
    return (1);
  keytab[0] = BKS_ESCAPE;
  keytab[1] = BKS_A;
  keytab[2] = BKS_LEFT;
  keytab[3] = BKS_RIGHT;
  keytab[4] = BKS_UP;
  keytab[5] = BKS_DOWN;
  keytab[6] = BKS_P;
  keytab[7] = BKS_M;
  arg->keytab = keytab;
  return (0);
}

char			set_keyfunc(t_param *arg)
{
  t_bunny_response	(**keyfunc)(t_param *);

  if ((keyfunc = bunny_malloc(sizeof(t_bunny_response *)* 9)) == NULL)
    return (1);
  keyfunc[0] = &key_escape;
  keyfunc[1] = &key_a;
  keyfunc[2] = &key_left;
  keyfunc[3] = &key_right;
  keyfunc[4] = &key_up;
  keyfunc[5] = &key_down;
  keyfunc[6] = &key_p;
  keyfunc[7] = &key_m;
  arg->keyfunc = keyfunc;
  return (0);
}

t_bunny_response	key_escape(t_param *arg)
{
  (void)arg;
  return (EXIT_ON_SUCCESS);
}

t_bunny_response	key_a(t_param *arg)
{
  arg->cur->aff = 0;
  arg->cur = (arg->cur->next == NULL) ? arg->form : arg->cur->next;
  arg->cur->aff = 1;
  return (GO_ON);
}

t_bunny_response	key_left(t_param *arg)
{
  arg->cur->x -= 10;
  return (GO_ON);
}
