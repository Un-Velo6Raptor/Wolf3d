/*
** move_forward.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 11:29:28 2016 
** Last update Tue Dec 20 13:49:34 2016 
*/

#include	<math.h>
#include	"my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  float		angle;
  float		res_x;
  float		res_y;

  angle = direction * (M_PI / 180);
  res_x = cos(angle) * distance;
  res_y = sin(angle) * distance;
  pos.x += res_x;
  pos.y += res_y;
  return (pos);
}
