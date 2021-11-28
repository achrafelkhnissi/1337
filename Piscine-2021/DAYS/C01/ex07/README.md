## Exercise 07:
### ft_strrev
+ Create a function that reverse the order of characters in a string.
+ It has to return str.
+ Here's how it should be prototyped:
```C
char	*ft_strrev(char *str);
```
+ Example:
```
	a     => a
	ab    => ba
	abcde => edcba
```
+ Files to turn in: ft_strrev.c
+ Allowed functions: Nothing

### ft_rev_int_tab
+ Create a function which reverses a given array of integers (first goes last, etc).
+ The arguments are a pointer to int and the number of ints in the array.
+ Here's how it should be prototyped:
```C
void	ft_rev_int_tab(int *tab, int size);
```
+ Files to turn in: ft_rev_int_tab.c
+ Allowed functions: None

### BUG I FACED!
* \*str vs str[]?: I faced this weird problem while trying to solve **"ft_strrev"**, i got a `[1]    46612 bus error  ./a.out` even though my code and everything in it was right. The weird thing is when i declare the string using (char str[]) instead of (char \*str) everything works as expected.\
Got the answer on [Stack overflow](https://stackoverflow.com/questions/3862842/difference-between-char-str-string-and-char-str-string)
```
char ptr[] = "string"; declares a char array of size 7 and initializes it with the characters
s ,t,r,i,n,g and \0. You are allowed to modify the contents of this array.

char *ptr = "string"; declares ptr as a char pointer and initializes it with address of string literal "string" which
is read-only. Modifying a string literal is an undefined behavior. What you saw(seg fault) is one manifestation of
the undefined behavior.
```

* Don't forget that the index of the last element in an array is (length - 1). 

