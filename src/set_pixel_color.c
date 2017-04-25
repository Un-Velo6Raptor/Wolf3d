/*
** set_pixel_color.c for  in /home/januar_m/delivery/graphical/bswireframe
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 14:51:44 2016 
** Last update Tue Dec 27 18:00:36 2016 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

sfColor		set_pixel_color(int a, int b, int c)
{
  sfColor	pixels_color;

  pixels_color.r = a;
  pixels_color.g = b;
  pixels_color.b = c;
  pixels_color.a = 255;
  return (pixels_color);
}

