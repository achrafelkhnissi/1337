## Exercise 04: ft_fibonacci
- Create a function **ft_fibonacci** that returns the **n**th element of the Fibonacci sequence, the first element being at the 0 index. We'll consider that the Fibonacci sequence starts like this: 0, 1, 1, 2.
- Here's how it should be prototyped:
```C
int	ft_fibonacci(int index);
```
- Obviously, **ft_fibonacci** has to be recursive.
- If the index is less than 0, the function should return -1.

## Understanding Fibonacci Sequence
- The Fibonacci Sequence is the series of numbers: 0, 1, 1, 2, 3, 5, 8, 13,...
- The next number is found by adding up the two numbers before it.
	- the 2 is found by adding the two numbers before it (1+1),
	- the 3 is found by adding the two numbers before it (1+2),
	- the 5 is (2+3),
	- and so on!
- Example: the next number is the sequence above is 8 + 13 = 21.
- Here is a longer list:
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 
10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, ...
```

### Makes A Spiral
- When we make squares with those widths, we get a nice spiral:

 ![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/fibonacci.jpg)

- This spiral found in nature! See: [Nature, The Golden Ratio and Fibonacci Numbers](https://www.mathsisfun.com/numbers/nature-golden-ratio-fibonacci.html)

### The Rule
- The Fibonacci Sequence can be written as a "Rule" (See [Sequences](https://www.mathsisfun.com/algebra/sequences-series.html))
- First, the terms are numbered from 0 onwards like this:
   ![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/fib_b%26w.png)

	So term number 6 is called x6 (which equals 8)\
	Example: the 8th term is the 7th term plus the 6th term

```
	+----+----+----+----+----+-----+
	|f(5)|f(6)|f(7)|f(8)|f(9)|f(10)|
	+----+----+----+----+----+-----+
	|  5 |  8 | 13 | 21 | 34 |  55 |
	+----+----+----+----+----+-----+
		^    ^	  |
		| +  |____|	
		|_________| f(8) = f(7) + f(6)

```

	So we can write the rule: f(n) = `f(n - 1) + f(n - 2)


### More
- [Fibonacci Sequence](https://www.mathsisfun.com/numbers/fibonacci-sequence.html)

### Notes
- Base case = if index < 2 return index

