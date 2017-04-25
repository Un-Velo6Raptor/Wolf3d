/*
** my_realloc.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 19:17:22 2016 
** Last update Tue Dec 20 19:17:24 2016 
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_realloc(char *res, char *buffer, int size)
{
  char	*new_str;

  if (res == NULL)
    res = my_strdup(buffer);
  else
    {
      if ((new_str = malloc(sizeof(char) *
			    (my_strlen(res) + size + 1))) == NULL)
	return (NULL);
      my_strcpy(new_str, res);
      my_strcat(new_str, buffer);
      free(res);
      return (new_str);
    }
  return (res);
}
