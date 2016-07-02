/*
** main.c for crypt in /home/meridj/Rendu/crypt/srcs
**
** Made by Lemeh
** Login   <meridj@epitech.net>
**
** Started on  Tue Jun  7 20:31:41 2016 Lemeh
** Last update Tue Jun  7 19:41:16 2016 courneil lucasc
*/

#include "crypt.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	read_f(int fd, int n)
{
  char	*str;

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

  if (ac != 3)
    my_putstr("USAGE: ./decypt file n\n", 2);
  else
    {
      fd = open_f(av[1]);
      n = my_getnbr(av[2]);
      if (n > 25 || n < -25)
	my_putstr("Wrong usage of N, only in the range of [-25;25]", 2);
      else
	read_f(fd, n);
      close(fd);
    }
  return (0);
}
