/*
** my.h for  in /home/januar_m/delivery/graphical/bswireframe
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 13:47:53 2016 
** Last update Sun Jan 15 11:08:26 2017 
*/

#ifndef MY_H_
# define MY_H_

# include		<SFML/Graphics/RenderWindow.h>
# include		<SFML/Graphics/Texture.h>
# include		<SFML/Graphics/Sprite.h>
# include		<SFML/Audio.h>
# include		<unistd.h>
# include		<stdlib.h>
# include		<stdio.h>
# include		"framefuffer.h"
# include		"map_player.h"

/*
** Prototypes of src.
*/

void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i,
				     sfColor);
t_my_framebuffer	*my_framebuffer_create(int, int);
sfVector2f		move_forward(sfVector2f, float, float);
sfRenderWindow		*create_window(char *, int, int);
sfVector2f		found_player(int **, sfVector2i);
sfVector2i		set_vector(int, int);
sfVector2f		set_vector_f(float, float);
sfVector2i		set_vector_f_to_i(float, float);
sfColor			set_pixel_color(int, int, int);
void			make_view(t_map_player *, sfColor,
				  t_my_framebuffer *, int);
float			raycast(sfVector2f, float, int **, sfVector2i);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			reset_frame(t_my_framebuffer *);
int			gest_key(t_map_player *);

/*
** Prototypes of basics.
*/

int			**make_map(char *, sfVector2i *);
char			*my_realloc(char *, char *, int);
char			*my_strcpy(char *, char *);
char			*my_strcat(char *, char *);
int			my_strlen(char *);
char			*my_strdup(char *);
int			my_char_isnum(char *, int *);
char			**my_str_to_wordtab(char *);
void			free_tab(char **);
void			my_putstr(char *);
void			my_puterror(char *);
char			**make_wallmap(char **);
int			match(char *, char *);
int			check_env(char **);

#endif /* !MY_H_ */
