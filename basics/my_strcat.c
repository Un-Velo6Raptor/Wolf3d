/*
** my_strcat.c for  in /home/januar_m/delivery/CPool_Day07
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Tue Oct 11 12:53:27 2016 Martin Januario
** Last update Tue Dec 20 19:43:44 2016 
*/

#include	"my.h"

char	*my_strcat(char *dest, char *src)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
