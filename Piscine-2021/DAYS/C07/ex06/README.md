##  Exercise 06: ft_convert_base
- Create a function that returns the result of the conversion of the string __nbr__ from a base __base_from__ to a base __base_to__. The string must have enough allocated memory. The number represented by __nbr__ must fit inside an __int__.
- Here's how it should be prototyped:
```C
	char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
```
- Allowed functions: malloc, free


## Algorithm
- the idea is to convert the input string from `base_from` to int decimal using `ft_atoi_base`.
- then convert the ìnt decimal from int to char\* `base_to` using `ft_itoa_base`.

#### ft_convert_base function:
1. firt we check if the input `base_form` and `base_to` are valid inputs.
2. As we checking we get the size of `base_from` and `base_to`.
3. We also check if one of the input is an empty string, if true we return 0.
4. We convert the input `*nbr` into an int using `ft_atoi_base` passing `*nbr` and it's length.
5. Then we pass the result of step (4) to `ft_atoi_base`alongside the `base_to` length.
6. return the result of step (5) to the main function.

#### ft_atoi_base
1. check if `*str` is negative by checking the first element if its '-' or '+'.
	- If so we assign -1 to the sign variable.
2. As long as `str[i]`
	- `get_digit` and assign the return value of the variable digit.
	- check if digit is a negative number, if so we return -1
	- else we add it to n `n = (n * base_n) + digit`
3. We return `n * sign`

#### git_digit
1. We check if the char digit is between 0 and 9
	- if so we check if `(digit - '0') >= base` if true we return -1.
	- else we return `digit - '0'`
2. We check for digit >= 'a' and digit <= 'f'
	- if so we check if the int representation of it is >= to base, if true we return -1.
	- else we return `digit + 10 - 'a'`
3. We check for digit >= 'A' and digit <= 'F'
	- If so we check if the int representation of it is >= to base, if true we return -1.
	- else we return `digit + 10 'A'`
4. we return -1 (means all of the above is false).

#### ft_itoa_base
1. declare base = "0123456789abcdef", and \*str
2. calculate the length of the input `nbr` using `nbrlen`
	- ex: nbr 1337 = 4 and 13 = 2.. and so on..
3. Allocate memory for the string that we gonna return using the return value from step (2)
4. check if the return value of the `malloc` is null.. if so we return `NULL`
5. Add `'\0'` to the end of the str in step (1), the last elemnt of str is the return value of (2) and decrement 'i' by 1.
6. check if `nbr` is 0, if so we assign str[0] to 0.
7. check if `nbr` is negative, if so we add '-' to the first element of str[0]
8. as long as `nbr > 0`
	- we assign the index `nbr % nbase` of base to str[i].
	- then `nbr /= nbase`
	- then we decrement `i--`
9. finally we return `str`

#### nbrlen
1. we check if the number is negative:
	- if so, we convert it to positive `nb = -nb`
	- and increment the variable len.
2. As long as the number is greater than 0
	- we divide the nb by the nbase and assign in to nb
	- we increment the length.
3. we return len.

