/*
** map_player.h for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 26 17:27:15 2016 
** Last update Fri Dec 30 18:12:43 2016 
*/

#ifndef MAP_PLAYER_H_
# define MAP_PLAYER_H_

typedef struct	s_map_player
{
  sfVector2i	mapSize;
  sfVector2f	pos;
  sfVector2f	pos_2;
  sfSprite	*sprite;
  sfColor	pixels_color;
  float		direction;
  float		direction_2;
  int		**map;
  int		sounds;
  int		mode;
}		t_map_player;

#endif /* !MAP_PLAYER_H_ */
