##
## Makefile for  in /home/januar_m/delivery/graphical/bswireframe
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Thu Dec  8 13:59:46 2016 
## Last update Sun Jan  1 13:42:49 2017 
##

SRC	=	src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/main.c			\
		src/raycast.c			\
		src/reset_frame.c		\
		src/move_forward.c		\
		src/create_window.c		\
		src/gest_key.c			\
		src/make_view.c			\
		src/set_pixel_color.c		\
		src/found_player.c		\
		src/my_framebuffer_create.c

BASICS	=	basics/make_map.c		\
		basics/my_realloc.c		\
		basics/my_strcpy.c		\
		basics/my_strcat.c		\
		basics/my_strdup.c		\
		basics/my_str_to_wordtab.c	\
		basics/my_char_isnum.c		\
		basics/free_tab.c		\
		basics/my_putstr.c		\
		basics/make_wallmap.c		\
		basics/match.c			\
		basics/check_env.c		\
		basics/my_strlen.c

OBJ	=	$(SRC:.c=.o)			\
		$(MENU:.c=.o)			\
		$(BASICS:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

NAME	=	wolf3d

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
