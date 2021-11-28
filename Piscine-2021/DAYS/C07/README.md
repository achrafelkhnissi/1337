# LIST OF DAY07 EXERCISES

|Exercise  |Description |Solution                     
|----------|------------|---------
|[ex00](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex00/) | [strdup](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex00/README.md) | [ft_strdup.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex00/ft_strdup.c)
|[ex01](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex01) | [range](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex01/README.md) | [ft_range.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex01/ft_range.c)
|[ex02](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex02) | [ultimate range](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex02/README.md) | [ft_ultimate_range.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex02/ft_ultimate_range.c)
|[ex03](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex03) | [concat params](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex03/README.md) | [ft_concat_params.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex03/ft_concat_params.c)
|[ex04](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex04) | [split whitespaces](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex04/README.md) | [ft_split_whitespaces.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex04/ft_split_whitespaces.c)
|[ex05](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex05) | [print words tables](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex05/README.md) | [ft_print_words_tables.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex05/ft_print_words_tables.c)
|[ex06](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex06) | [convert base](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex06/README.md) | [ft_convert_base.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex06/ft_convert_base.c)
|[ex07](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex07) | [split](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex07/README.md) | [ft_split.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY07/ex07/ft_split.c)

## Static Memory Allocation
- Memory allocated during compile time is called static memory (allocated in stack).
- The memory allocated is fixed and cannot be increased or decreased.
- Example
```c
int	main(void)
{
	/* memory allocaed at compile time (fixed size) */
	int	arr[4] = {1, 3, 3, 7};

	return (0);
}
```
#### Problems faced in static memory allocation
- If you are allocating memory for an array during compile time then you have to __fix the size at the time of declaration__. Size is fixed and user cannot increase or decrease the size of the array at run time.
- If the value stored by the user in the array at run time is __less__ than the size specified then there will be a wastage of memory.
- If the value stored by the user in the array at run time is __more__ than the size specified then the program may crash or misbehave.

## Dynamic Memory Allocation

----

<details>
<summary>How does malloc work.</summary>

---
> [How does malloc work.](https://www.youtube.com/watch?v=SuBch2MZpZM)
---

- Ex: 

```C
char	*ptr;

ptr = (char *) malloc (4 * sizeof(char));
ptr[0] = '1';
ptr[1] = '3';
ptr[2] = '3';
ptr[3] = '7';
```
1. This statement `int	*ptr` is a static memory allocation
```
		  +-------------+
		  |    Stack    |
		  +-------------+
	S0x00     |	        |
	S0x01     | ptr = H0x44 |
	S0x02     |	        |
		  +-------------+
- S0x01 is the address of ptr variable.
```
2. Next comes our dynamic memory allocation statement `ptr = (char *) malloc (4 * sizeof(char)));`
```
# malloc takes one argument which is the size of the memory to be allocated (in bytes).
		  +-------------+
		  |    Heap     |
	          +-------------+
	H0x1336   |	        |
	H0x1337   | #GarbageV#  |
	H0x1338   | #GarbageV#  |
	H0x1338   | #GrabageV#  |
	H0x1338   | #GarbageV#  |
	H0x1338   |	        |
		  +-------------+
```
3. Malloc returns the base address of the allocated memory which gets stored in __ptr__
```
		  +---------------+
		  |    Stack      |
		  +---------------+
	S0x00     |	          |
	S0x01     | ptr = H0x1337 |
	S0x02     |	          |
		  +---------------+
- Now using ptr we can access the memory allocated in heap with malloc.
```
4. Now we can assign it. ptr[0] = '1';
```
		  +-------------+
		  |    Heap     |
	          +-------------+
	H0x1336   |	        |
	H0x1337   |     '1'     |
	H0x1338   |     '3'     |
	H0x1338   |     '3'     |
	H0x1338   |     '7'     |
	H0x1338   |	        |
		  +-------------+
```
- If the heap is full and malloc cannot allocate memory, malloc returns NULL. That's why we should always check for the return value of the malloc function.

</details>

---

- The process of allocating memory at the time of execution is called dynamic memory allocation. 

- Heap is the segment of memory where dynamic memory allocation takes place. Unlike stack where memory is allocated and deallocated in a defined order, heap is an area of memory where memory is allocated or deallocated without any order or randomly.

</p>
<p align="center">  
<img src ="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/heap.png" width="200">
</p>

- There are certain built-in function that can help in allocating or deallocating some memory space at run time.
	- malloc() and others.. (man malloc).
	- free().
- __malloc__ is used to dynamically allocate a single block of contiguous memory according to the size specified (in bytes).
- __malloc__ function simply allocates a memory block int the head and on success it returns a __pointer__ pointing to the first byte of the allocated memory, if there is an error, they return a NULL pointer and set errno to ENOMEM.
- If the return value is __NULL__ it means that memory is not available.
- Why __malloc__ returns a void pointer?
	- __malloc__ doesn't have an idea of what it is pointing to.
- [Under what circumstances can malloc return NULL? - stackoverflow](https://stackoverflow.com/questions/9101597/under-what-circumstances-can-malloc-return-null)
	```
	Just try to malloc more memory than your system can provide (either by exhausting your address space, or virtual memory - whichever is smaller).

	malloc(SIZE_MAX)
	will probably do it. If not, repeat a few times until you run out.
	```

### Notes
- Pointers play an important role in dynamic memory allocation.
- Allocated memory can only accessed through pointers.
- It is important to check for the return value of malloc! And the functions that uses malloc like __strdup__.
- [Why it is important to check  what the malloc function returns.](https://medium.com/pvs-studio/why-it-is-important-to-check-what-the-malloc-function-returned-ba39f3d13a83)

-----

<details>
<summary>Ex: Allocating Memory at Runtime</summary>

## Allocating memory at runtime

- Dynamic memory allocation is when you allocate memory for your own variables at runtime, This will happen in the heap memory location.
- Stack: is a memory location for so-called automatic duration variables that come and go as functions or blocks  are entered and exited.
- Automatically allocated variables only persist during their own block or function.
- Dynamically allocated memory on the other hand, is explicitly managed, so allocated and freed, by the user from the so-called heap.
- The function to ask from memory is called

`malloc`  as in memory allocation and is part of the standard library: `stdlib.h`.

> [Codecast sanbox (memory visualization)](https://codecast.france-ioi.org/v6/)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //! showMemory(start=272) (Codecast sandbox)
    int *intptr;
    double *doubleptr;
    intptr = (int *) malloc(sizeof(int));
    *intptr = 4;
    doubleptr = (double *) malloc(sizeof(double));
    *doubleptr = 40.5;

    printf("*intptr = %d\n", *intptr);
    printf("*doubleptr = %.2lf\n", *doubleptr);

    return 0;
}
```
### Notes:
1. include <stdio.h> if we wanna use printf or scanf
2. include <stdlib.h> if we wanna use malloc
3. We need a pointer var to store the address of where our malloc return/resurved for us.
4. (int \*) <- casting to the correct data type. You can convert the values from one type to another using casting (\*) because we are storing the return reserved address from malloc stored for us.

## Freeing dynamically allocated memory

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //! showMemory(start=438, cursors=[a,b,c])
    int *a, *b, *c;
    a = (int *) malloc(sizeof(int));
    *a = 1;
    printf("I stored %d at memory location %p.\n", *a, a);
    b = (int *) malloc(sizeof(int));
    *b = 2;
    free(a);
    c = (int *) malloc(sizeof(int));
    *c = 3;
    printf("Can I still access a?\n");
    printf("I stored %d at memory location %p.\n", *a, a);
    return 0;
}
```

### Notes:
1. The malloc() function return a void pointer which we need to then cast to the correct data type using (type \*)
2. We use free() function to deallocate memory.

</details>

-----

<details>
<summary>Ex: Storing and addressing arrays in dynamically allocated memory</summary>

## Allocate memory for arrays using malloc

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *array;
    array = (int *) malloc(5 * sizeof(int));

    int i;
    for(i = 0; i < 5; i++)
        array[i] = i * i;
    for(i = 0; i < 5; i++)
        printf("array[%d] = %d\n", i, array[i]);

    free(array);

    return 0;
}
```
### Notes:
- The idea to take the size of the data type you wish to store and then multiply it by the number of elements for which you need space.

## Learn from another example of array memory allocation

```c
#include <stdlib.h>
#include <stdio.h>

int *allocate_int_array(int n);
double find_average(int *arr, int n);
int main(void)
{
    int num, i;
    int *ptr_arr;
    double average;

    printf("How man grades would you like to enter? ");
    scanf("%d", &num);
    ptr_arr = allocate_int_array(num);
    printf("Please enter %d grades: ", num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", ptr_arr + i); // same as: &ptr_arr[i]
    }
    average = find_average(ptr_arr, num);
    for(i = 0; i < num; i++)
    {
        printf("ptr_arr[%d] = %d\n", i, ptr_arr[i]);
    }
    printf("And its average is = %.2lf.\n", average);

    free(ptr_arr);
    return 0;
}

double find_average(int *arr, int n)
{
    int i;
    double result = 0.0;
    for(i = 0; i < n; i++)
    {
        result += arr[i];
    }
    result = result / n;
    return result;
}

int *allocate_int_array(int n)
{
    // returns a pointer to the first element.
    int *ptr;
    ptr = (int *) malloc(n * sizeof(int));
    return ptr;
}
```

### Notes:
1. example of the use of malloc, memory allocation, for an array for which we don't know the size in advance.
2. We declare a function of the pointer type when we want to return a pointer (address)

