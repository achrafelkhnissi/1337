#include <unistd.h>

void    ft_putnbr(int nb)
{
        char c;
        if(nb < 0)
        {
                nb = -nb;
                write(1, "-", 1);
        }
        if(nb < 10)
        {
                c = nb + '0';
                write(1, &c, 1);
        }
        else
        {
                ft_putnbr(nb / 10);
                ft_putnbr(nb % 10);
        }
}

void	print_hex(int nb)
{
	char *str;
	str = "0123456789abcdef";
	if(nb == 0)
		write(1, "0", 1);
	while(nb)
	{
		write(1, &str[nb % 16], 1);
		nb /= 16;
	}
}

int print_num(int decimalnum, int base)
{
    int octalnum = 0, temp = 1;

    while (decimalnum != 0)
    {
        octalnum = octalnum + (decimalnum % base) * temp;
        decimalnum = decimalnum / base;
        temp = temp * 10;
    }

    return octalnum;
}

int     ft_strlen(char *str)
{
        int i;
        i  = 0;
        while(str[i])
                i++;
        return(i);
}
