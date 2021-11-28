#ifndef FT_TAIL_H
#define FT_TAIL_H

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void	ft_tail(int ac, int bytes, char *file);
void    show_file_name(int ac, int bytes, char *filename);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	stdin_to_stdout(void);
int	check_flag(char **av);
int	ft_strlen(char *str);
int	ft_atoi(char *str);
int	get_tail_index(char *file);

#endif
