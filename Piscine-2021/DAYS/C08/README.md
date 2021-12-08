# LIST OF C08 EXERCISES

|Exercise  |Description |Solution                     
|----------|------------|---------
|[ex00](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex00/) | [ft.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex00/README.md) | [ft.hc](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex00/ft.h)
|[ex01](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex01) | [ft_boolean.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex01/README.md) | [ft_boolean.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex01/ft_boolean.h)
|[ex02](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex02) | [ft_abs.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex02/README.md) | [ft_abs.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex02/ft_abs.h)
|[ex03](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex03) | [ft_point.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex03/README.md) | [ft_point.h](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex03/ft_point.h)
|[ex04](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex04) | [ft_strs_to_tab.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex04/README.md) | [ft_strs_to_tab.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex04/ft_strs_to_tab.c)
|[ex05](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex05) | [ft_show_tab](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex05/README.md) | [ft_show_tab.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C08/ex05/ft_show_tab.c)

## Header and their purpose
As programs grow larger (and make use of more files), it becomes increasingly tedious to have to forward declare every function you want to use that is defined in a different file. Wouldn’t it be nice if you could put all your forward declarations in one place and then import them when you need them? \
C code files (with a .c extension) are not the only files commonly seen in C programs. The other type of file is called a header file. Header files usually have a .h extension. The primary purpose of a header file is to propagate declarations to code files. \
- Key point: Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing in multi-file programs.

## Using standard library header files
Consider the following program:
```c
#include <stdio.h>

int main(void)
{
    printf("Hello world");
    return (0);
}
```
This program prints “Hello, world!” to the console using `printf`. However, this program never provided a definition or declaration for `printf`, so how does the compiler know what `printf` is? \
The answer is that `printf` has been forward declared in the `"stdio.h"` header file. When we `#include <stdio.h>`, we’re requesting that the preprocessor copy all of the content (including forward declarations for `printf`) from the file named `"stdio.h"` into the file doing the `#include`.
- When you `#include` a file, the content of the included file is inserted at the place where it's included. This provides a useful way to pull in declarations from another file.

