#ifndef FT_CAT_H 
#define FT_CAT_H 

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void	ft_puterr(char *err);
void	stdin_to_stdout(void);
int	ft_cat(char *file);
int	ft_strlen(char *str);

#endif
