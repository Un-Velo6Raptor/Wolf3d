/*
** my_strlen.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 19:24:09 2016 
** Last update Tue Dec 20 19:24:44 2016 
*/

#include	"my.h"

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
