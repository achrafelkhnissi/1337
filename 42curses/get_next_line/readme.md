# Notes

## how realloc work!

Syntax: void \*realloc(void \*ptr, size_t newSize)
	- ptr = Pointer to the previously allocated memory.
	- NewSize = The new size.

On failure, realloc returns NULL.

if the size of the new block if greater than the size of the revious block,
	then if it is possible to extend the previous block, find some consecutive 
	memory with the same block, then the previous itself is extended.
	Else, a new block is allocated and the content of the previous block is
	copied and the previous block is de-allocated.

what will happend if the newly allocated memory is smaller than the original.

