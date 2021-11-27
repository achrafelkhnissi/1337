#ifndef FT_HEXDUMP_H
#define FT_HEXDUMP_H

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void	ft_hexdump(char *content, unsigned int size, int flag);
void	ft_putaddr(int nbr, int flag);
void	ft_puthex(char *str, int index, int flag);
int	ft_putstr(char *str, int index, int size, int flag);
char	*get_content(char *file);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	check_flag(char **av);
int	ft_strlen(char *str);
void	ft_putchar(char c);

#endif
