/*
** fdf.h for fdf2
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 11 13:21:09 2015 marc brout
** Last update Thu Dec 17 10:51:58 2015 marc brout
*/

#ifndef FDF_H_
# define FDF_H_
# define HEIGHT 1024
# define WIDTH 1280
# define TYPE "fdf2"
# define DATA "data"
# define COLOR "color"
# define SHAPE "shape"
# define PIXEL "pixel"
# define LINE "line"
# define POLY "polygone"
# define FLD bunny_ini_get_field
# define BACKGROUND BLACK
# define DEFAULT_COL RED
# define PAS 100

# include "lapin.h"

typedef struct		s_dot
{
  t_bunny_position	pos;
  t_color		col;
}			t_dot;

typedef struct		s_obj
{
  t_dot			a;
  t_dot			b;
  t_dot			c;
  struct s_obj		*next;
}			t_obj;

typedef struct		s_form
{
  char			shape;
  char			color;
  char			aff;
  int			x;
  int			y;
  float			zoom;
  void			(*func)(struct s_form *, t_bunny_pixelarray *);
  char			*name;
  t_obj			*objs;
  struct s_form		*next;
}			t_form;

typedef struct		s_param
{
  t_form		*form;
  t_form		*cur;
  t_bunny_keysym	*keytab;
  t_bunny_response	(**keyfunc)(struct s_param *);
  t_bunny_ini		*ini;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_key		key;
}			t_param;

t_bunny_response my_keys(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response main_loop(void *);
t_bunny_response key_escape(t_param *);
t_bunny_response key_a(t_param *);
t_bunny_response key_left(t_param *);
t_bunny_response key_right(t_param *);
t_bunny_response key_up(t_param *);
t_bunny_response key_down(t_param *);
t_bunny_response key_p(t_param *);
t_bunny_response key_m(t_param *);
void free_obj(t_obj *);
void free_all(t_param *);
void add_pos(t_bunny_position *, t_form *);
void set_pos(t_bunny_position *, t_dot *, t_dot *, t_color *);
void pos_pixel(t_form *, t_bunny_pixelarray *);
void pos_line(t_form *, t_bunny_pixelarray *);
void pos_poly(t_form *, t_bunny_pixelarray *);
void background(t_param *);
void tekpixel(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void tekline(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void put_data(t_param *, t_form *, t_bunny_position *, int);
void put_color(t_param *, t_form *, t_color *, int);
void tekisoproject(t_bunny_position *, int, int, int);
void trace_cube(t_param *);
void add_dota(t_obj *, int, int, int);
void add_dotb(t_obj *, int, int, int);
void facea(t_obj *, int);
void faceb(t_obj *, int);
void diags(t_obj *, int);
int my_getnbr(const char *);
int my_strlen(char *);
int my_strcmp(const char *, char *);
char init_keytab(t_param *);
char set_keyfunc(t_param *);
char *my_strdup(char *);
char aff_fdf(t_param *);
char check_trio(t_param *, t_form *, int);
char add_obj_to_list(t_form *);
char fill_polygones(t_param *, t_form *);
char fill_pixels(t_param *, t_form *);
char fill_lines(t_param *, t_form *);
char fill_objs(t_param *);
char fill_this_scope(t_param *, t_form *);
char ret_shape(t_param *, char *);
char launch_fdf(char **);
char open_ini(t_param *, char **);
char const_form_list(t_param *);
char add_form_to_list(t_param *, char *);
char check_scope(t_param *, char *);
char generate_cube(t_param *);
char init_cube_scope(t_param *);
char create_list(t_form *);
char add_vert_to_cube(t_form *);

#endif
