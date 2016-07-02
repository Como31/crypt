/*
** tools.c for  in /home/courne_l/rendu/cpe/colle/crypt
**
** Made by courneil lucasc
** Login   <courne_l@epitech.net>
**
** Started on  Tue Jun  7 18:17:27 2016 courneil lucasc
** Last update Tue Jun  7 22:31:34 2016 Lemeh
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

int     my_getnbr(char *str)
{
  int   res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str)
    {
      res = res * 10;
      res = res + *str - '0';
      str = str + 1;
    }
  return (res);
}
