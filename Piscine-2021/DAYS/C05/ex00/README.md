## Exercise 00: ft_iterative_factorial
- Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
- If there's an error, the function should return 0.
- Here's how it should be prototyped:
```C
int	ft_iterative_factorial(int nb);
```
- Your function must return its result in less that two seconds.

## Understanding Factorial
- The factorial of a whole number n, written as n!, is found by multiplying n by all the whole numbers less than it. For example, the factorial of 4 is 24, because 4 × 3 × 2 × 1 = 24. Hence one can write 4! = 24. For some technical reasons, 0! is equal to 1.

![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/factorial.png)

- The factorial function (symbol: !) says to multiply all whole numbers from our chosen number down to 1.
- Example:
```
4! = 4 × 3 × 2 × 1 = 24
7! = 7 × 6 × 5 × 4 × 3 × 2 × 1 = 5040
1! = 1
```
### Calculating From The Previous Value
- We can easily calculate a factorial from the previous one:\

	![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/factorial-how.svg)

- As a table:

|n |  n!  | | | 
|--|--|--|--|
|1|  1  |1  |1|
|2|  2 × 1|  = 2 × 1!|  = 2|
|3|  3 × 2 × 1|  = 3 × 2!|  = 6|
|4|  4 × 3 × 2 × 1|  = 4 × 3!|  = 24|
|5|  5 × 4 × 3 × 2 × 1|  = 5 × 4!  |= 120|
|6|  etc  |etc  |

To work out 6!, multiply 120 by 6 to get 720\
To work out 7!, multiply 720 by 7 to get 5040\
And so on..

Example:
```
9! equals 362,880. Try to calculate 10!
10! = 10 × 9!
10! = 10 × 362,880 = 3,628,800
```
So the rule is: `n! = n * (n - 1)!`
Which says "the factorial of any number is **that number** times the **factorial of (that number minus 1)"**\
so `10! = 10 * 9!`, ... and `125! = 125 * 124!`, etc.

### What About "0!"
- Zero factorial is interesting... it is generally agreed that 0! = 1.
- It may seem funny that multiplying no numbers together results in 1, but let's follow the pattern backwards from, say, 4! like this:

     ![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/zero-factorial.svg)

And in many equations using 0! = 1 just makes sense.
- Example: how many ways can we arrange letters (without repeating)?
```
For 1 letter "a" there is only 1 way: a
For 2 letters "ab" there are 1×2=2 ways: ab, ba
For 3 letters "abc" there are 1×2×3=6 ways: abc acb cab bac bca cba
For 4 letters "abcd" there are 1×2×3×4=24 ways: (try it yourself!)
etc
```
The formula is simply **n!**. Now How many ways can we arrange no letters?\
Just one way, an empty space: so `0! = 1`

### Where is Factorial Used?
[More examples](https://www.mathsisfun.com/numbers/factorial.html)
