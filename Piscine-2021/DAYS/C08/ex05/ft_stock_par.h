#ifndef FT_STOCK_PAR_H
#define FT_STOCK_PAR_H

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/

typedef struct s_stock_par
{
	int	size_param;
	char	*str;
	char	*copy;
	char	**tab;
}	t_stock_par;

struct s_stock_par	*ft_param_to_tab(int ac, char **av);

/* ft_split_whitespaces */
char	**ft_split_whitespaces(char *str);

/* ft_show_par */
void	ft_show_tab(struct s_stock_par *par);

#endif
