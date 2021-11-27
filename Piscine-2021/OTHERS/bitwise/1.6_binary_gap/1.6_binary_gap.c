/*

A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range 1 to INT_MAX

*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static int solution(int N) {
    int count;
    int max = 0;

    while (N) // we go through each digit of the number, representing it as a binary figure like 9 becomes 0b1001
	{
        if (N & 1) // if the number is odd, same as if (N % 2 == 1)
        {
            count = 0; // starting the counter
            while ((N >>= 1) && (~N & 1)) // we divide by 2 (the right shift '>>=' is equivalent to '/= 2') and then check the N is not odd (even) by toggling its bits with '~'. Hence the last digit was 0 in a binary representation then it would become 1.
                ++count; // increase the counter by 1, same as count = count + 1;
            if (count > max)
			 	max = count; // if our counter is bigger than the previously
				// stored maximum it becomes the new maximum, to handle case such as 0b10000010001
        }
        else
            N >>= 1; // if N is even then we divide N per 2 to go through the number. Example: If we have '10 = 0b1010' so divided by 2 (right shift >>) it becomes '0b101 = 5'
    }
    return max;
}

int		main(void)
{
	int a = 9;

	ft_putnbr(solution(a));

	return (0);
}
