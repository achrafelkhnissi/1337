## EXERCISE 05
* Create a function that displays all different combinations of three different digits in ascending order, listed by ascending order - yes, repetition is voluntary.
* Here's the intended output:
```
$>./a.out | cat -e
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>
```
* 987 isn't there because 789 already is.
* 999 isn't there because digit 9 is present more than once.
* Here's how it should be prototyped:
```C
void	ft_print_comb(void);
```
+ Files to turn in: ft_print_comb.c
+ Allowed functions: ft_putchar


## Solution

- Considering d = digit, so d3 d2 d1
  and because the digits has to be listed in ascending order
  we need to start from 000, but remember repetition isn't allowed.
  let's start with the possibilities.
  some number has to go fist and there is 10 possibilities.
  We gonna start with d1 because that's the first number
  we can put 10 possibilities there from 0 to 9, d3 d2 9
  now but things gets a little different for the second number
  we no longer have 10 options because whatever digit does first
  we can't use it again.
  So now there is only 9 possibilities (0 to 8): d3 8 9
  then for the third digit we there are now 8 possibilities
  (0 to 7): 7 8 9.
  
- We notice that it starts with 012 and ends with 789
  in other words if 
  - d3 = n
  - d2 = d3 + 1
  - d1 = d2 + 1

- The ```ft_putchar(d + '0')```
  We know that if the input is char representation of a digit
  and we want to get the actual value of that digit we need 
  to use ```d - '0'``` taking in consideration that 'd' is
  a char data type.
  Therefore if we want to opsite we reverse the formula.
