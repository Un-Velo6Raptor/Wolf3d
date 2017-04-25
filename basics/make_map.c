/*
** make_map.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 14:48:33 2016 
** Last update Fri Dec 30 17:53:53 2016 
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		*make_buffer(int fd)
{
  char		buffer[4096];
  int		size;
  char		*res;

  res = NULL;
  size = 0;
  while ((size = read(fd, buffer, 4095)) > 0)
    {
      buffer[size] = '\0';
      res = my_realloc(res, buffer, size);
    }
  return (res);
}

int		check_map(char **map, int *idx, sfVector2i *mapSize)
{
  int		tmp;
  int		x_max;
  int		player;

  tmp = 0;
  player = 0;
  x_max = my_strlen(map[*idx]);
  while (map[*idx] != NULL)
    {
      if ((tmp = my_char_isnum(map[*idx], &player)) == -1)
	return (84);
      if (tmp != x_max)
	return (84);
      (*idx)++;
    }
  if ((*idx) == 0 || x_max == 0 || player != 1)
    return (84);
  (*mapSize).x = x_max;
  (*mapSize).y = (*idx);
  return (0);
}

int		**make_tab_int(char **map, int nb_ligne)
{
  int		**res;
  int		idx;
  int		idx2;

  res = NULL;
  idx = 0;
  if ((res = malloc(sizeof(int *) * nb_ligne)) == NULL)
    return (NULL);
  while (map[idx] != NULL)
    {
      idx2 = 0;
      if ((res[idx] = malloc(sizeof(int) * my_strlen(map[idx]))) == NULL)
	return (NULL);
      while (map[idx][idx2] != '\0')
	{
	  res[idx][idx2] = map[idx][idx2] - '0';
	  idx2++;
	}
      idx++;
    }
  free_tab(map);
  return (res);
}

int		**make_map(char *str, sfVector2i *mapSize)
{
  char		**map;
  char		*res;
  int		nb_ligne;
  int		fd;

  nb_ligne = 0;
  if ((fd = open(str, O_RDONLY)) == -1)
    return (NULL);
  if ((res = make_buffer(fd)) == NULL)
    return (NULL);
  if ((map = my_str_to_wordtab(res)) == NULL)
    return (NULL);
  if (close(fd) == -1)
    return (NULL);
  if (check_map(map, &nb_ligne, mapSize) == 84)
    {
      my_puterror("Bad Map.\n");
      return (NULL);
    }
  free(res);
  if ((map = make_wallmap(map)) == NULL)
    return (NULL);
  (*mapSize).x += 2;
  (*mapSize).y += 2;
  return (make_tab_int(map, nb_ligne + 2));
}
