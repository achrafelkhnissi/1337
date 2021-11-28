#ifndef FT_STOCK_PAR_H
#define FT_STOCK_PAR_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_split_whitespaces.c"

typedef struct	s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);
char **ft_split_whitespaces(char *av);
void	ft_show_tab(struct s_stock_par *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
int     is_whitespace(char c);
int     word_count(char *str);
char	*ft_strdup_w(char *str, int *index);
char	**ft_split_whitespaces(char *str);

#endif
