/*
** crypt.h for crypt in /home/meridj/Rendu/crypt/include
**
** Made by Lemeh
** Login   <meridj@epitech.net>
**
** Started on  Tue Jun  7 20:28:44 2016 Lemeh
** Last update Tue Jun  7 23:40:12 2016 Lemeh
*/

#ifndef CRYPT_H_
# define CRYPT_H_

void	my_putchar(char c);
void	my_putstr(char *str, int fd);
int	my_strlen(char *str);
int	read_f(int fd, int n);
int	open_f(char *str);
int	my_getnbr(char *str);
void	decrypt(char *src, int n);

#endif /* !CRYPT_H_ */
