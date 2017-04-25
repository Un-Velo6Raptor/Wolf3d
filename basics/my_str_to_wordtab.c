/*
** my_str_to_wordtab.c for  in /home/januar_m/delivery/graphical/wolf3d/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 20 20:35:33 2016 
** Last update Fri Dec 30 18:38:31 2016 
*/

#include	<stdlib.h>

int	start_idx(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] != '\0' && ((str[idx] >= 'A' && str[idx] <= 'Z') ||
			       (str[idx] >= 'a' && str[idx] <= 'z') ||
			       (str[idx] >= '0' && str[idx] <= '9')))
	return (idx);
      idx++;
    }
  return (idx);
}

int	count_words(char *str)
{
  int	idx;
  int	words;

  idx = 0;
  words = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] != '\0' && ((str[idx] >= 'A' && str[idx] <= 'Z') ||
			       (str[idx] >= 'a' && str[idx] <= 'z') ||
			       (str[idx] >= '0' && str[idx] <= '9')))
	{
	  while (str[idx] != '\0' && ((str[idx] >= 'A' && str[idx] <= 'Z') ||
				      (str[idx] >= 'a' && str[idx] <= 'z') ||
				      (str[idx] >= '0' && str[idx] <= '9')))
	    idx++;
	  words++;
	}
      while (str[idx] != '\0' && ((str[idx] < 'A' || str[idx] > 'Z') &&
				  (str[idx] < 'a' || str[idx] > 'z') &&
				  (str[idx] < '0' || str[idx] > '9')))
	idx++;
    }
  return (words);
}

char	*copy_words(char *str)
{
  int	idx;
  int	idx2;
  char	*res;

  idx = 0;
  idx2 = 0;
  while (str[idx] != '\0' && ((str[idx] >= 'A' && str[idx] <= 'Z') ||
			      (str[idx] >= 'a' && str[idx] <= 'z') ||
			      (str[idx] >= '0' && str[idx] <= '9')))
    idx++;
  if ((res = malloc(sizeof(char) * idx + 1)) == NULL)
    return (NULL);
  while (idx2 <= idx)
    {
      res[idx2] = str[idx2];
      idx2++;
    }
  res[idx] = '\0';
  return (res);
}

int	next_words(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0' && ((str[idx] >= 'A' && str[idx] <= 'Z') ||
			      (str[idx] >= 'a' && str[idx] <= 'z') ||
			      (str[idx] >= '0' && str[idx] <= '9')))
    idx++;
  while (str[idx] != '\0' && ((str[idx] < 'A' || str[idx] > 'Z') &&
			      (str[idx] < 'a' || str[idx] > 'z') &&
			      (str[idx] < '0' || str[idx] > '9')))
    idx++;
  return (idx);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	idx_malloc_tab;
  int	idx_words;
  int	idx;

  idx = start_idx(str);
  idx_words = 0;
  idx_malloc_tab = count_words(str);
  if ((tab = malloc(sizeof(char *) * (idx_malloc_tab + 1))) == NULL)
    return (NULL);
  while (str[idx] != '\0' && idx_words < idx_malloc_tab)
    {
      tab[idx_words] = copy_words(&str[idx]);
      if (tab[idx_words] == NULL)
	return (tab);
      idx_words++;
      idx += next_words(&str[idx]);
    }
  tab[idx_words] = NULL;
  return (tab);
}
