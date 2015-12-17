##
## Makefile for fdf2 in /home/brout_m/rendu/projet/Infographie/gfx_fdf2
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 14:00:22 2015 marc brout
## Last update Thu Dec 17 14:00:24 2015 marc brout
##

SRCP	= ./src/

SRCP2	= ./tcore/

SRC     = $(SRCP)fdf2.c \
	$(SRCP)free_all.c \
	$(SRCP)cube.c \
	$(SRCP)keytab.c \
	$(SRCP)keytab_2.c \
	$(SRCP)cube_vertices.c \
	$(SRCP)fill_obj.c \
	$(SRCP)aff_fdf.c \
	$(SRCP)pos_pixels.c \
	$(SRCP)filling_process.c \
	$(SRCP)check_scope.c \
	$(SRCP)my_strdup.c \
	$(SRCP)my_strcmp.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_strlen.c \
	$(SRCP)my_putstr_err.c \
	$(SRCP2)tekpixel.c \
	$(SRCP2)tekline.c \
	$(SRCP2)tekisoproject.c

OBJS    = $(SRC:.c=.o)

NAME    = fdf2

CC      = gcc

CFLAGS  = -W -Wall -Werror -ansi -pedantic -I./include/

LDFLAGS = -L/usr/local/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-L./lib/ \

RM      = rm -f

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
