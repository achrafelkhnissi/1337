/**********************************************************************
** 1.7 : Using bit operation to align a size
**********************************************************************/

#include <stdio.h>
#include <ctype.h>

/*
** we can use a combination of left and right shifts using the power of two
** align. If align = 5 we will align on 2^5 = 32 bytes
** Constraint : align < 32
*/

size_t			ft_align_power_of_two(size_t size, size_t align)
{
	return (((size + (1 << align) - 1) >> align) << align);
}

/*
** equivalently we can use a mask
** if size is 37 and we add the mask (31) we get 68.
** Then we ask to keep only the bits above the 5th since '~mask' toggle bits
** will becomes 0b1...10000
** Constraint : mask must be a power of 2 - 1
*/

size_t			ft_align_mask(size_t size, size_t mask)
{
	return ((size + mask) & ~mask);
}

int		main(void)
{
	int n = 37;
	printf("%lu\n", ft_align_power_of_two(n, 5)); // 2^5 = 32
	printf("%lu\n", ft_align_mask(n, 0x1f)); // 0x1f + 1 = 0x20 = 32
	return (0);
}

/*
Resulting assembly:

ft_align_power_of_two(unsigned long long, unsigned long long):
    mov rcx, rsi
    mov eax, 1
    sal eax, cl
    cdqe
    lea rax, [rdi-1+rax]
    shr rax, cl
    sal rax, cl
    ret

ft_align_mask(unsigned long long, unsigned long long):
    lea rax, [rdi+rsi]
    not rsi
    and rax, rsi
    ret

You can hence witness that the function aligning using the mask is much more optimized !!
*/
