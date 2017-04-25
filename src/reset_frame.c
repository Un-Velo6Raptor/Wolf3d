/*
** reset_frame.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 26 21:48:43 2016 
** Last update Thu Dec 29 15:41:20 2016 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"framefuffer.h"
#include	"my.h"

void		reset_frame_2(t_my_framebuffer *pixel_buffer)
{
  int		idx;
  int		width;

  width = pixel_buffer->width / 2;
  idx = width * 4 + 1;
  while (idx < (pixel_buffer->height * pixel_buffer->width * 4))
    {
      pixel_buffer->pixels[idx] = 0;
      idx++;
      if (idx % (width * 4) == 0)
	idx += width * 4 + 1;
    }
}

void		reset_frame_1(t_my_framebuffer *pixel_buffer)
{
  int		idx;
  int		width;

  width = pixel_buffer->width / 2;
  idx = 0;
  while (idx < (pixel_buffer->height * pixel_buffer->width * 4))
    {
      pixel_buffer->pixels[idx] = 0;
      idx++;
      if (idx % (width * 4) == 0)
	idx += width * 4 + 1;
    }
}

void		reset_frame(t_my_framebuffer *pixel_buffer)
{
  int		idx;

  idx = 0;
  while (idx < pixel_buffer->height * pixel_buffer->width * 4)
    {
      pixel_buffer->pixels[idx] = 0;
      idx++;
    }
}
