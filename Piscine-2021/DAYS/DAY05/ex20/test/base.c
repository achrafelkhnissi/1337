#include <unistd.h>
#include <stdio.h>
#include "assist.c"

int	ft_check_all(char *base)
{
	int i;
	char *str;
	int len = ft_strlen(base);

	i = 0;
	str = "0123456789abcdef";
	while(base[i] && i < len)
	{
		if(base[i] == str[i])
		i++;
	else
		return(0);
		
	}

	return(1);
}

int     ft_check_octal(char *base)
{
        char *strp;
        int i;
        i = 0;
        strp = "poneyvif";
                while(base[i])
                {
                        if(base[i] == strp[i])
                                i++;
                        else
                                return(0);
                }

        return(1);
}


void	ft_putnbr_base(int nbr, char *base)
{

		if(ft_strlen(base) == 16 && ft_check_all(base))
			print_hex(nbr);
		if(ft_strlen(base) == 8 && ft_check_octal(base))
				ft_putnbr(print_num(nbr, 8));
		if(ft_strlen(base) == 10 && ft_check_all(base))
				ft_putnbr(print_num(nbr, 10));
	        if(ft_strlen(base) == 2 && ft_check_all(base))
	                ft_putnbr(print_num(nbr, 2));

}

int	main()
{
	for (int i = -15; i < 15; i++)
	{
		//ft_putnbr_base(i, "0123456789abcdef");
		//ft_putnbr_base(i, "poneyvif");
		ft_putnbr_base(i, "01");
		//ft_putnbr_base(i,  "0123456789");
		write(1, "\n", 1);
	}

	return(0);
}
