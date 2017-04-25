/*
** my_char_isnum.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 20:27:16 2016 
** Last update Fri Dec 30 16:09:47 2016 
*/

#include	"my.h"

int		my_char_isnum(char *str, int *player)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] < '0' || str[idx] > '2')
	return (-1);
      if (str[idx] == '2')
	(*player)++;
      idx++;
    }
  return (idx);
}
