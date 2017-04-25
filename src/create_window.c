/*
** create_window.c for  in /home/januar_m/delivery/graphical/bswireframe
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 14:49:07 2016 
** Last update Thu Dec  8 14:49:57 2016 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}
