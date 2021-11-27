/**********************************************************************
** 1.4 : Parsing flag using bitwise operations whatever the project is
**********************************************************************/

#include "bitwise.h"

/*
** First we build the ft_strchr_index function which is similar to libft strchr
** but instead returns the character index in a string
*/

static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

/*
** Then we create the function parse_options which receive av[1] 
** and our variable pointer address.
**
** a) Here we light the nth bit according to the parsed flag
** Firstly define flags as power of 2 in the header.h :
** # define FLAG_A	1         # define FLAG_B	2
** # define FLAG_C	4         # define FLAG_D	8
** etc. if more flags necessary.
**
** b) Then we send input from user after we find a '-' character
** hence the while (*(++s)) in order to skip it.
** if the string does not contain abcd it will return the USAGE
**
** c) Each time the function str_chr_index, we will light the bit corresponding.
** for example if we use /a.out -c we will get n equal to 2 (a starting at 0).
*/

int			parse_options(char *s, int *flags)
{
	int		n;

	while (*(++s)) // b)
	{
		if ((n = ft_strchr_index("abcd", *s)) == -1)
			error(s, USAGE); // b)
		*flags |= (1 << n); // c)
	}
	return (1);
}

/*
** Lastly a small example on how to use it.
**
** a) We check that exactly one parameter was sent starting with '-'.
**
** b) Remember that FLAG_C is defined as 4 in the header.h file
** if (flag & 4) also means (flag % 5)
**
** c) If flag A was ON it will toggle flag B OFF by clearing bit FLAG_B (2).
*/

int			main(int ac, char **av)
{
	int		flags;

    if (ac == 2 && *av[1] == '-')
        parse_options(av[1], &flags); // a)
    printf("value : %d\n", flags); // our variable raw value
    printf("binary value : %bd\n", flags); // displayed as a binary number
    if (flags & FLAG_C)  // b) ,
        printf("c flag ON");
    if (flags & FLAG_B && flags & FLAG_D) // replace 2 by FLAG_B and 8 by FLAG_D
        printf("Both flags b and d are together ON");
    if (flags & FLAG_A && flag & FLAG_B)  // replace 1 by FLAG_A and 2 by FLAG_B
    {
        *flags &= ~FLAG_B;  // c)
        printf("As flag A was ON, flag B is switched OFF");
        printf("new binary value : %bd\n", flags);
    }
	return (0);
}
