/*
** gest_key.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 26 22:24:01 2016 
** Last update Fri Dec 30 21:55:55 2016 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"map_player.h"
#include	"my.h"

int		gest_key(t_map_player *all_news)
{
  float		idx_dir;
  float		idx;

  idx = 1.0 / 10;
  idx_dir = 1.5;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    all_news->pos = move_forward(all_news->pos, all_news->direction, idx);
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    all_news->pos = move_forward(all_news->pos, all_news->direction, idx * -1);
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    all_news->direction -= idx_dir;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    all_news->direction += idx_dir;
  return (0);
}
