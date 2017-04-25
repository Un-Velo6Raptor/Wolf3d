/*
** found_player.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Dec 30 16:17:39 2016 
** Last update Fri Dec 30 16:38:47 2016 
*/

#include	"my.h"

sfVector2f	found_player(int **map, sfVector2i mapSize)
{
  sfVector2f	tmp;
  int		idx;
  int		idx2;

  idx = 0;
  tmp.x = 1.5;
  tmp.y = 1.5;
  while (idx < mapSize.y)
    {
      idx2 = 0;
      while (idx2 < mapSize.x)
	{
	  if (map[idx][idx2] == 2)
	    {
	      tmp.x = idx2 + 0.5;
	      tmp.y = idx + 0.5;
	      return (tmp);
	    }
	  idx2++;
	}
      idx++;
    }
  return (tmp);
}
