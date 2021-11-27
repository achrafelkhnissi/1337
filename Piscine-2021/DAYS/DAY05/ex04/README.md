## Exercise 04: ft_strncpy

- Reproduce the behavior of the function __strncpy__ (man strncpy).
- Here's how it should be prototyped:
```C
	char	*ft_strncpy(char *dest, char *src, unsigned int n);
```

## Understanding strncpy
### Description:
The stpncpy() and strncpy() functions copy at most len characters
from src into dst.  If src is less than len characters long, the
remainder of dst is filled with `\0' characters.  Otherwise, dst is
not terminated.

### Return Values
The strcpy() and strncpy() functions return dst.  The stpcpy() and
stpncpy() functions return a pointer to the terminating `\0' character of dst.  If stpncpy() does not terminate dst with a NUL character, it instead returns a pointer to dst[n] \(which does not necessarily refer to a valid memory location.)

### Examples
- The following sets chararray to ''abc\0\0\0'':

```C
           char chararray[6];

           (void)strncpy(chararray, "abc", sizeof(chararray));
```

- The following sets chararray to ''abcdef'':

```C
           char chararray[6];

           (void)strncpy(chararray, "abcdefgh", sizeof(chararray));
```

Note that it does not NUL terminate chararray because the length ofthe source string is greater than or equal to the length argument.

- The following copies as many characters from input to buf as will
fit and NUL terminates the result.  Because strncpy() does not guarantee to NUL terminate the string itself, this must be done explicitly.

```C
           char buf[1024];

           (void)strncpy(buf, input, sizeof(buf) - 1);
           buf[sizeof(buf) - 1] = '\0';
```

This could be better achieved using strlcpy(3), as shown in the following example:

```C
           (void)strlcpy(buf, input, sizeof(buf));
```

Note that because strlcpy(3) is not defined in any standards, it should only be used when portability is not a concern.

