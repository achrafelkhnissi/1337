#ifndef FT_ADV_OPP_H
# define FT_ADV_OPP_H

# include <unistd.h>
# include <stdlib.h>

typedef int		(*t_s_opp)(int, int);

typedef struct	s_opp
{
	char	*op;
	t_s_opp	func;
}				t_opp;

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);

#endif
