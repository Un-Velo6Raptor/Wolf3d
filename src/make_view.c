/*
** make_view.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Dec 24 12:11:53 2016 
** Last update Fri Dec 30 21:58:00 2016 
*/

#include	<unistd.h>
#include	<math.h>
#include	"my.h"
#include	"map_player.h"

void		make_view(t_map_player *all_news,  sfColor p_color,
			  t_my_framebuffer *window, int idx)
{
  float		result;
  float		wall;
  float		save;

  save = all_news->direction - (30 / all_news->mode);
  result = 0;
  wall = 0;
  reset_frame(window);
  p_color = sfWhite;
  while (idx < window->width / all_news->mode)
    {
      result = raycast(all_news->pos, save, all_news->map, all_news->mapSize)
	* cos ((save - all_news->direction) * M_PI / 180);
      wall = (1.0 / result) * window->height;
      my_draw_line(window,
		   set_vector_f_to_i(idx, window->height / 2.0 - wall / 2.0),
		   set_vector_f_to_i(idx, window->height / 2.0 + wall / 2.0),
		   p_color);
      save += ((60.0 / all_news->mode) / (window->width / all_news->mode));
      idx++;
    }
}
