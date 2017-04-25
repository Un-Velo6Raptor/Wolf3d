/*
** make_wallmap.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Dec 30 14:25:32 2016 
** Last update Fri Dec 30 18:37:30 2016 
*/

#include	<stdlib.h>
#include	"my.h"

int		count_ligne(char **map)
{
  int		idx;
  int		max;

  idx = 0;
  max = 0;
  if (map == NULL)
    return (-1);
  while (map[idx] != NULL)
    {
      if (idx == 0)
	max = my_strlen(map[idx]);
      if (idx != 0 && max != my_strlen(map[idx]))
	return (-1);
      idx++;
    }
  if (max == 0 || idx == 0)
    return (-1);
  return (idx);
}

char		*line_wall(int nb)
{
  int		idx;
  char		*tmp;

  idx = 0;
  tmp = NULL;
  if ((tmp = malloc(sizeof(char) * (nb + 3))) == NULL)
    return (NULL);
  while (idx < nb + 2)
    {
      tmp[idx] = '1';
      idx++;
    }
  tmp[idx] = '\0';
  return (tmp);
}

char		*wallmap_next(char ***new_map, char **map, int idx)
{
  int		idx2;

  idx2 = 0;
  if (((*new_map)[idx + 1] = malloc(sizeof(char) *
				    (my_strlen(map[idx]) + 3))) == NULL)
    return (NULL);
  (*new_map)[idx + 1][0] = '1';
  while (map[idx][idx2] != '\0')
    {
      (*new_map)[idx + 1][idx2 + 1] = map[idx][idx2];
      idx2++;
    }
  (*new_map)[idx + 1][idx2 + 1] = '1';
  (*new_map)[idx + 1][idx2 + 2] = '\0';
  return ("Ok");
}

char		**make_wallmap(char **map)
{
  char		**new_map;
  int		idx;
  int		idx2;

  new_map = NULL;
  idx = 0;
  if ((idx2 = count_ligne(map)) <= 0 ||
      (new_map = malloc(sizeof(char *) * (idx2 + 3))) == NULL ||
      (new_map[0] = line_wall(my_strlen(map[0]))) == NULL)
    return (NULL);
  while (map[idx] != NULL)
    {
      wallmap_next(&new_map, map, idx);
      if (new_map[idx + 1] == NULL)
	return (NULL);
      idx++;
    }
  if ((new_map[idx + 1] = line_wall(my_strlen(map[0]))) == NULL)
    return (NULL);
  new_map[idx + 2] = NULL;
  free_tab(map);
  return (new_map);
}
