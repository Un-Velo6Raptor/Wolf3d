/*
** main.c for  in /home/januar_m/delivery/graphical/bswireframe
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 14:54:48 2016 
** Last update Thu Feb  2 14:43:58 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"
#include	"map_player.h"

int			loop_window(sfRenderWindow *window,
				    t_my_framebuffer *pixel_buffer,
				    t_map_player *all_news, sfTexture *texture)
{
  sfEvent		event;
  sfColor		background;

  all_news->mode += 1;
  background = set_pixel_color(69, 69, 69);
  make_view(all_news, all_news->pixels_color, pixel_buffer, 0);
  sfTexture_updateFromPixels(texture, pixel_buffer->pixels, 600, 500, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(window);
	  gest_key(all_news);
	}
      make_view(all_news, all_news->pixels_color, pixel_buffer, 0);
      sfTexture_updateFromPixels(texture,
				 pixel_buffer->pixels, 600, 500, 0, 0);
      sfRenderWindow_clear(window, background);
      sfRenderWindow_drawSprite(window, all_news->sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
  return (0);
}

int			ini_window(t_map_player *all_news)
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  t_my_framebuffer	*pixel_buffer;
  sfEvent		event;

  if ((window = create_window("SFML Wolf3d", 600, 500)) == NULL)
    return (84);
  sfRenderWindow_pollEvent(window, &event);
  all_news->sprite = sfSprite_create();
  texture = sfTexture_create(600, 500);
  if ((pixel_buffer = my_framebuffer_create(600, 500)) == NULL)
    return (84);
  sfSprite_setTexture(all_news->sprite, texture, sfTrue);
  reset_frame(pixel_buffer);
  loop_window(window, pixel_buffer, all_news, texture);
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  t_map_player		*all_news;

  if (check_env(env) == 1)
    return (84);
  if ((all_news = malloc(sizeof(t_map_player) * 1)) == NULL)
    return (84);
  all_news->map = NULL;
  all_news->mapSize = set_vector(0, 0);
  all_news->direction = 90.0;
  all_news->direction_2 = 90.0;
  all_news->sounds = 1;
  all_news->mode = 0;
  if (argc != 2 ||
      (all_news->map = make_map(argv[1], &all_news->mapSize)) == NULL)
    return (84);
  all_news->pos = found_player(all_news->map, all_news->mapSize);
  all_news->pos_2 = found_player(all_news->map, all_news->mapSize);
  if (ini_window(all_news) == 84)
    return (84);
  return (0);
}
