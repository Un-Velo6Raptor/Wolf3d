/*
** free_tab.c for  in /home/januar_m/delivery/graphical/wolf3d
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 20:48:19 2016 
** Last update Tue Dec 20 20:49:22 2016 
*/

#include	<stdlib.h>
#include	"my.h"

void		free_tab(char **tab)
{
  int		idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      free(tab[idx]);
      idx++;
    }
  free(tab);
}
