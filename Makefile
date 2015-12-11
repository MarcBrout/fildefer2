##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Fri Dec 11 13:58:10 2015 marc brout
##

SRCP	= ./src/

SRCP2	= ./tcore/

SRC     = $(SRCP)fdf2.c \
	$(SRCP2)tekpixel.c \
	$(SRCP2)tekline.c \
	$(SRCP2)tekllproject.c

OBJS    = $(SRC:.c=.o)

NAME    = fdf2

CC      = gcc

CFLAGS  = -W -Wall -Werror -ansi -pedantic -g

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
	$(CC) -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
