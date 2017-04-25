/*
** my_putstr.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 21:02:25 2016 
** Last update Tue Dec 20 21:05:08 2016 
*/

#include	<unistd.h>
#include	"my.h"

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
