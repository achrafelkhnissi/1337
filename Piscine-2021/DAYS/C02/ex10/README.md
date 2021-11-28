## Exercise 19: ft_strlcpy
- Reproduce the behavior of the function strlcpy (man strlcpy).
- Here's how it should be prototyped:
```C
	unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
```

## Understanding strlcpy
### Description:
- The strlcpy() and strlcat() functions copy and concatenate strings with the same input parameters and output result as snprintf(3).  They are designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3). strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL should be included in dstsize. strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.

- The strcpy() function copies string s2 to s1, including the terminating null character, stopping after the null character has been copied. The strncpy() function copies exactly n bytes, truncating s2 or adding null characters to s1 if necessary. The result will not be null-terminated if the length of s2 is n or more. Each function returns s1. If copying takes place between objects that overlap, the behavior of strcpy(), strncpy(), and strlcpy() is undefined.\
The strlcpy() function copies at most dstsize−1 characters (dstsize being the size of the string buffer dst) from src to dst, truncating src if necessary. The result is always null-terminated. The function returns strlen(src). Buffer overflow can be checked as follows:
```C
if (strlcpy(dst, src, dstsize) >= dstsize)
        return −1;
```

