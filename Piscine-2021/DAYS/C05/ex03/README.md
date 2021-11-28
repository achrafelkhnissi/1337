
## Exercise 03: ft_recursive_power
- Create a recursive function that returns the value of a power applied to a number.
- Same conditions as before.
- Here's how it should be prototyped:
```C
int	ft_recursive_power(int nb, int power);
```

## Understanding Power (exponent)
- The power (exponent) of a number says how many times to use the number in a multiplication.
- In **8^2** the "2" says to use 8 twice in a multiplication, so `8^2 = 8 * 8 = 64`
- Exponents are also called Power or Indices.

### In General
- **a^n** tells you to multiply **a** by itself, so there are **n** of those **a**'s:

   ![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/exponent-definition.gif)

### Negative Exponents
- [Example](https://www.mathsisfun.com/exponent.html)
- [Laws of Exponents](https://www.mathsisfun.com/algebra/exponent-laws.html)
- [Negative Exponents Explained! - YouTube](https://www.youtube.com/watch?v=TKj8kEofbAw)

## Problems i faced
- I tried to pass the number and the power from (argv) but i had unexpected results.
- I Basically forgot the formula. Which is: `result = nb * recursive_power(nb, power)`
- Forget the right base case: power == 0

## Notes
- Works exactly the same way as the recursive power formula.
- Assuming nb = 8, power = 3;
	- result = 1;
	- result = nb * r_power(nb, power - 1);
	- (1) result = 8 * r_power(8, 2);
	- (2) result = 8 * r_power(8, 1);
	- (3) result = 8 * r_power(8, 0); (when power reaches 0 the function returns result);

	- (3) result = 8 * 1 = 8 -> returns to (2)
	- (2) result = 8 * 8 = 64 -> returns to (1)
	- (1) result = 8 * 64 = 512 -> returns to main
	- result = 521

