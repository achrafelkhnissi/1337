## Exercise 18: ft_strlcat
- Reproduce the behavior of the function strlcat (man strcat).
- Here's how it should be prototyped:
```C
	unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
```

## Understanding strlcat
### Description:
- strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room. Note that room for the NUL should be included in dstsize. strlcat() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string). If the src and dst strings overlap, the behavior is undefined.

- The strlcat() function appends at most (dstsize-strlen(dst)-1) characters of src to dst (dstsize being the size of the string buffer dst). If the string pointed to by dst contains a null-terminated string that fits into dstsize bytes when strlcat() is called, the string pointed to by dst will be a null-terminated string that fits in dstsize bytes (including the terminating null character) when it completes, and the initial character of src will override the null character at the end of dst. If the string pointed to by dst is longer than dstsize bytes when strlcat() is called, the string pointed to by dst will not be changed. The function returns min{dstsize,strlen(dst)}+ strlen(src). Buffer overflow can be checked as follows:
```C
if (strlcat(dst, src, dstsize) >= dstsize)
        return −1;
```
- strlcat() appends up to size-strlen(dst)-1 bytes from the NUL-terminated string src to the end of dst. It takes the full size of the buffer, not only the length, and terminates the result with NUL as long as size is greater than 0. Include a byte for the NUL in your size value.

### Return Value
- The strlcat() function returns the total length of the string that would have been created if there was unlimited space. This might or might not be equal to the length of the string actually created, depending on whether there was enough space. This means that you can call strlcat() once to find out how much space is required, then allocate it if you do not have enough, and finally call strlcat() a second time to create the required string.
- If the return value is >= dstsize, the output string has been truncated.  It is the caller's responsibility to handle this.

## Notes
1. The different between size and length:
	- size = includes '\0'.
	- length = doesn't include '\0'.
2. Return value: 
	- When __size__ is less than __dest__ it returns (strlen(src) + size).
	- If the size is >= the length of dest it returns (length of dest + length of src).

## Solution
1. Declarations:
	- declare __dest_len__ and initialize it to the length of dest
	- declare __src_len__ and initialize it to the length of src
	- declare n_size and initialize it to (size - dest_len). /\* remove the length of dest from the total size \*/
2. Check if the input size is greater than the length of dest.
	- if True then return the length of dest + size.
3. Move the pointer to the end of dest by doing through a while loop as long as we didn't reach the null pointer we increment the current pointer.
4. When we reach the end of the dest string now we go through another while loop to add the src string to the end of dest string.
	- as long as we didn't reach the end of the string src and as long as n_size-- is greater than 1 (1 is the place holder for the null character that we gonna append in the end)
	- we assign the value of the current pointer of src to the current value of the pointer dest and increment both pointers.
5. After the loop above finishes we add a null character to the end of concatenated string.
6. return the length of dest + length of src.

## Another versions
### My 2nd version
```C
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	n_size;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	n_size = size - dest_len;
	if (size < dest_len)
		return (src_len + size);
	while (*dest)
		dest++;
	while (*src && n_size-- != 1)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_len + src_len);
}
```

### My 3rd version
```C
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*d;
	char	*s;
	unsigned int	new_size;
	unsigned int	dest_len;
	unsigned int	src_len;

	d = dest;
	s = src;
	dest_len = strlen(dest);
	src_len = strlen(src);
	new_size = size - dest_len;
	if (size < dest_len)
		return (src_len + size);
	if (size == dest_len)
		return (dest_len + src_len);
	while (*d)
		d++;
	while (*s && new_size-- != 1)
		*d++ = *s++;
	*d = '\0';
	return (dest_len + src_len);
}
```

### Apple/Google version
```C
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	c;
	char	*d;
	char	*s;
	int	dest_len;

	d = dest;
	s = src;
	c = size;
	while (c-- != 0 && *d != '\0')
		d++;
	dest_len = d - dest;
	c = size - dest_len;
	if (c == 0)
		return (dest_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (c != 1)
		{
			*d++ = *s;
			c--;
		}
		s++;
	}
	*d = '\0';
	return (dest_len + (s - src));
}
```

