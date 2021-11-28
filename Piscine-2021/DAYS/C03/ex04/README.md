## Exercise 05: ft_strstr

- Reproduce the behavior of the function __strstr__ (man strstr).
- Here's how it should be prototyped:
```C
	char	*ft_strstr(char *str, char *to_find);
```

## Understanding strstr

### Description
The strstr() function locates the first occurrence of the null-terminated string __to_find__ in the null-terminated string __str__.

### Return values
If __to_find__ is an empty string, __str__ is returned; if __to_find__ occurs nowhere in __str__, NULL is returned; otherwise a pointer to the first character of the first occurrence of __to_find__ is returned.

### Example
The following sets the pointer ptr to the "Bar Baz" portion of str:

```C
           const char *str= "Foo Bar Baz";
           const char *to_find= "Bar";
           char *ptr;

           ptr = strstr(str, to_find);
```

## Solution
1. We declare two index variables
	- first one to keep track the count of __str__ characters.
	- second one to keep track of the count of __to_find__ characters.
2. We check if the string __to_find__ is empty, if True we return __str__.
3. We start a while loop as long as we didn't reach the end of __str__.
	- We initialize the second index in (1) to 0 (inside the while loop because sometimes we can find some letters from __to_find__ in __str__ therefore we want to reset the count every time that's happen).
	- Go through a nested while loop (4).
	- We increment the first index count. (1)
4. We start a nested while loop inside (3) checking as long as:
	- __str__[index 1 + 2] is equal to __to_find__[index 2]: When we enter the nested loop we only increment the second index, the first index is always fixed on the first occurrence of the first character of __to_find__.
	- and __str__[index 1 + 2] not the '\0'. 
	- As long as it's true we check if the next character of __to_find__ is '\0', if True we know that we find the first occurrence of __to_find__ and return the address it which is __&str[first index]__ because the count of the first index stops every time we enter the nested loop.
	- finally we increment the second index;
5. If we reached this step that means we didn't find any occurrence of __to_find__ in __str__ so we just return null.

