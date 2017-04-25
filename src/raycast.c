/*
** raycast.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 14:07:01 2016 
** Last update Thu Jan  5 16:04:06 2017 
*/

#include	<math.h>
#include	"my.h"

sfVector2f	set_vector_f(float x, float y)
{
  sfVector2f	vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

sfVector2i	set_vector_f_to_i(float x, float y)
{
  sfVector2i	vector;

  vector.x = (int) x;
  vector.y = (int) y;
  return (vector);
}

sfVector2i	set_vector(int x, int y)
{
  sfVector2i	vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  sfVector2f	tmp_pos;
  sfVector2i	tmp;
  float		result;
  float		idx;

  result = 0;
  idx = 1.0 / 100.0;
  tmp = set_vector(pos.x, pos.y);
  tmp_pos = set_vector_f(pos.x, pos.y);
  while (tmp_pos.x > 0 && tmp_pos.x < mapSize.x
	 && tmp_pos.y > 0 && tmp_pos.y < mapSize.y &&
	 map[tmp.y][tmp.x] != 1)
    {
      tmp_pos = move_forward(tmp_pos, direction, idx);
      tmp = set_vector_f_to_i(tmp_pos.x, tmp_pos.y);
      result += idx;
    }
  return (result);
}
