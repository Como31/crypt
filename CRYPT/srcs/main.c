/*
** main.c for crypt in /home/meridj/Rendu/crypt/srcs
**
** Made by Lemeh
** Login   <meridj@epitech.net>
**
** Started on  Tue Jun  7 20:31:41 2016 Lemeh
** Last update Tue Jun  7 23:46:07 2016 Lemeh
*/

#include "crypt.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-2);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s2[i] != 0)
    return (-1);
  return (0);
}

int	read_f(int fd, int n)
{
  char		*str;

  if ((str = malloc(sizeof(char) * 2048)) == NULL)
    {
      my_putstr("error malloc", 2);
      return (-1);
    }
  if ((read(fd, str, 2048)) == -1)
    {
      my_putstr("error to read", 2);
      return (-1);
    }
  decrypt(str, n);
  free(str);
  return (0);
}

int	open_f(char *str)
{
  int	fd;

  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_putstr("error to open file\n", 2);
      return (-1);
    }
  return (fd);
}

int	main(int ac, char **av)
{
  int	fd;
  int	n;

  if (ac != 4)
    my_putstr("USAGE: ./crypt [-f ou -s] [file ou string] n\n", 2);
  else
    {
      n = my_getnbr(av[3]);
      if (n > 25 || n < -25)
	my_putstr("Wrong usage of N, only in the range of [-25;25]", 2);
      if ((my_strcmp(av[1], "-f")) == 0)
	{
	  fd = open_f(av[2]);
	  read_f(fd, n);
	  close(fd);
	}
      else if ((my_strcmp(av[1], "-s")) == 0)
	decrypt(av[2], n);
    }
  return (0);
}
