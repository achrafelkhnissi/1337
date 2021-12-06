# DAY10 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex00)      |[Makefile](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex00/README.md)          |[Makefile](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex00/Makefile) |
|[ex01](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex01)     |[foreach](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex01/README.md)  |[ft_foreach.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex01/ft_foreach.c)  |
|[ex02](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex02)   |[map](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex02/README.md)           |[ft_map.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex02/ft_map.c)         |
|[ex03](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex03)   |[any](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex03/README.md)           |[ft_any.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex03/ft_any.c)      |
|[ex04](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex04)   |[count if](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex04/README.md)        |[ft_count_if.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex04/ft_count_if.c)  |
|[ex05](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex05)   |[is sort](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex05/README.md)       |[ft_is_sort.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex05/ft_is_sort.c)       |
|[ex06](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex06)   |[do-op](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex06/README.md)           |[ft_do-op.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex06/srcs/main.c) |
|[ex07](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex07)   |[sort word tab](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex07/README.md)        |[ft_sort_wordtab.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex07/ft_sort_wordtab.c)       |
|[ex08](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex08)   |[advanced sort word tab](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex08/README.md)     |[ft_advanced_sort_wordtab.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex08/ft_advanced_sort_wordtab.c)|
|[ex09](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex09)   |[advanced do-op](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex09/README.md) |[ft_advanced_do-op.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY10/ex09/srcs/main.c)


> Main (d09) Topic: Pointers to functions (intro & syntax)\
> [Use of Function Pointer in C Struct](https://aticleworld.com/function-pointer-in-c-struct/)\
> [Function Pointers](https://www.codingame.com/playgrounds/14589/how-to-play-with-pointers-in-c/function-pointers)\
> [How can I use an array of function pointers? - stackoverflow](https://stackoverflow.com/questions/252748/how-can-i-use-an-array-of-function-pointers)\
> [Array of Pointers to Functions - pdf](https://rmbconsulting.us/Publications/PointerToFunction.pdf)\
> [Function Pointer in C Struct](https://www.codeproject.com/Tips/800474/Function-Pointer-in-C-Struct)

## Understanding and Using Function Pointers

- A function pointer is just a pointer, a variable that stores the address of a function that we wanna call later on.
- `(type) (*pointer_name)(parameter);`
- Example:
```c
int	* (*foo) (int, int , int);

/*

identifier: foo
right: nothing
left: pointer!
* pupout of ()
right: function that takes 3 ints
left: returns int *

result = foo is a pointer to a function that takes 3 ints and returns an int pointer.

*/
```

## Using Function Pointers

```c
typedef int (*op_ptr)(int, int);

int	add(int x, int y) { return x + y; }
int	mult(int x, int y) { return x * y; }

/* you can change "int (*op) (int, int)" with "op_ptr op" */
int	do_operation(int (*op)(int, int), int x, int y)
{
	return op(x, y);
}

int	main(void)
{
	int	result;
	int	result2;

	result = do_operation(add, 13, 37);
	result2 = do_operation(mult, 13, 37);
	return (0);
}
```

## Function Pointers [more]

#### Definition
Function pointers are like a normal pointers but they have the capability to point to a function.

```c
int	add(int	x, int y) 	
{
	return x + y;
}		
/*	
		 +-----------+
    #0x00001	 |   Inst 1  |
addr of 1st Inst |   Inst 2  |
  		 |   Inst 3  |
 		 |   Inst 4  |
 		 +-----------+
*/
```

- A function is a set of instructions which are stored in memory. Functions like is like variables, is also stored in memory but in form of instructions.

## How to declare a pointer to a function?

## [Precedence of operators]()

First we need to know to know how to declare a pointer to an array.

```c
int	main(void)
{
	int	*ptr[10]; // <--- WRONG!

	return (0);

/*
	ptr = operand.
	 *  = operator.
	 [] = operator.
*/
}
```

- This is wrong because the __precedence__ of `[]` is higher than `*`
- We can say that `ptr` is an array of 10 pointers pointing to integers.

<p float="center">
  <img src="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/ptr_arr1.png" width="35%"/>
  <img src="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/ptr_arr2.png" width="42%"/> 
</p>

- if we want a pointer which point to an array we need to declare it like this: 

```c
int	main(void)
{
	int	(*ptr)[10];

	return (0);
}
```

- Add `()` makes the __precedence__ of `*` higher than `[]`

<p float="center">
  <img src="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/ptr_arr3.png" width="35%"/>
  <img src="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/ptr-arr4.png" width="42%"/> 
</p>

- `int (*ptr)[10]` means that `ptr` is a pointer which points to 10 integers.

## Declaring a pointer to a function

- `(type) (*pointer_name)(parameter);`

```c
int	add(int x, int y)
{
	return x + y;
}

int	main(void)
{
	/* similar as declaring a pointer to array */
	int	(*ptr)(int ,int);

	return (0);
}
```

- `ptr` is a pointer to a function that takes two int arguments and it returns an `int`

## Assigning a function to a function pointer

- In order to assign a function to a function pointer we need to assign the address of that particular function.

```c
int	main(void)
{
	int	(*ptr)(int, int);

	ptr = add;
	/* or ptr = &add; both works */
}
```

## Using the function pointer

```c
int	main(void)
{
	int	result;
	int	(*ptr)(int, int);

	ptr = add;
	result = ptr(10, 20); /* We can use the pointer as the function that points to */
	printf("result = %d\n", result);
	return (0);
}
```

