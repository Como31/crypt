/*
** algo.c for   in /home/courne_l/rendu/cpe/colle/crypt
**
** Made by courneil lucasc
** Login   <courne_l@epitech.net>
**
** Started on  Tue Jun  7 18:22:18 2016 courneil lucasc
** Last update Tue Jun  7 21:49:39 2016 courneil lucasc
*/

#include "crypt.h"
#include <stdlib.h>

void	convert_src(char *src, int n, int i, int n_)
{
  if (src[i] + n > 'z' || src[i] + n > 'Z'
      || src[i] + n >= 'A')
    {
      n_ = n;
      while (n_ > 0)
	{
	  if (src[i] == 'Z' || src[i] == 'z')
	    src[i] = src[i] - 26;
	  src[i] = src[i] + 1;
	  n_--;
	}
    }
  else if (src[i] + n >= 'a' || src[i] + n >= 'A')
    {
      n_ = n;
      while (n_ < 0)
	{
	  if (src[i] == 'A' || src[i] == 'a')
	    src[i] = src[i] + 25;
	  src[i] = src[i] - 1;
	  n_++;
	}
    }
  else
    src[i] = src[i] + n;
}

void	decrypt(char *src, int n)
{
  int	i;
  int	n_;

  i = 0;
  n_ = 0;
  while (src[i] != '\0')
    {
      if ((src[i] >= 'A' && src[i] <= 'Z')
	  || (src[i] >= 'a' && src[i] <= 'z'))
	{
	  convert_src(src, n, i, n_);
	}
      i++;
    }
  my_putstr(src, 2);
}
