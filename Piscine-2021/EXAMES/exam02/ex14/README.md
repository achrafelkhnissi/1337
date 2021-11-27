## Exercise

```
======================================./2-6-is_power_of_2.txt=========================================
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
------------------------------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
======================================================================================================
```

### Algorithm

- We declare a variable and assign it to 1.
- We go through a lop as long as the variable is less than the given number
	- multiplying the number by 2 with each iteration.
- Then we check if the variable is equal to the given number.
	- if so we return true.
- We return false. (means the previous conditions is false)
