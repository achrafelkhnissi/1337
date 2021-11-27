### Exercise

```
======================================./2-4-do_op.txt=========================================
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
----------------------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
==============================================================================================
```

## Algorithm

- First we check if the number of arguments is 4
- If so. We convert the string to int using atoi.
- Then we go though each element of the struct array
	- checking if the third argument is equal to one of the operations.
		- if so we print the result of the operation.
	- else we increment the index.
- We print a new line.

Note: We need to create a struct to hold a string. and a pointer to a function. Then We create an array of structs and assign each operation with it's sign.

