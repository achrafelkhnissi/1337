## Exercise 02: ft_ultimate_range
- Create a function __ft_ultimate_range__ which allocates and assigns an array of __ints__. This __int__ array should contain all values between __min__ and __max__.
- __min__ included - __max__ excluded.
- Here's how it should be prototyped:
```C
	int ft_ultimate_range(int **range, int min, int max);
```
- If the value if __min__ is greater or equal to __max__'s value, __range__ will point on __NULL__.
- The size of the __range__ should be returned (or 0 on error).
- Allowed functions: __malloc__

