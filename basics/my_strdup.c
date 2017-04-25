/*
** my_strdup.c for  in /home/januar_m/delivery/CPool_Day08
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Wed Oct 12 09:36:21 2016 Martin Januario
** Last update Sun Jan 15 11:11:05 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strdup(char *src)
{
  char	*str;

  if ((str = malloc(my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
