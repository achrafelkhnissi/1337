<h1 align="center">
	42cursus' ft_printf
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' ft_printf project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/42curses"><b>42cursus repo</b></a>.
</p>


<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
</h3>

---

## 🗣️ About

> _This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments._

	🚀 TLDR: this project consists of coding a library that contains a simplified version (more
	information below) of the printf function.

### Mandatory

* **format specifiers** - `cspdiuxX%`

## 📑 Index

`@root`

* [**📁 ft_printf:**](ft_printf/) source code developed for the project.
* [**📁 testing:**](testing/) my own testing program.


## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/ft_printf.h
```

## 📋 Testing

**1. Configuring**

First, open the [`Makefile`](testing/Makefile) inside `/testing/` and configure the path to the `ft_printf` folder:

```Makefile
PROJECT_DIR	= ../ft_printf/
```

Then, configure the tests to your needs in the [`/testing/main.c`](testing/main.c) file.

**2. Running:**

```shell
make
```

### Third-party testers

* [gavinfielder/pft](https://github.com/gavinfielder/pft)
* [Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
* [HappyTramp/ft_printf_test](https://github.com/HappyTramp/ft_printf_test)
* [t0mm4rx/ftprintfdestructor](https://github.com/t0mm4rx/ftprintfdestructor)
* [charMstr/printf_lover_v2](https://github.com/charMstr/printf_lover_v2)

## 📌 Useful Links

* [C++ Reference - printf](http://www.cplusplus.com/reference/cstdio/printf/)
* [Article: Secrets of “printf” (PDF)](https://www.cypress.com/file/54441/download)
* [MacOS documentation - printf](https://opensource.apple.com/source/xnu/xnu-201/osfmk/kern/printf.c.auto.html)
* [IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)
* [How does one print floats for ft_printf? - Stack Overflow - 42 Network](https://stackoverflow.com/c/42network/questions/133/134#134)
* [Printing Floating-Point Numbers](http://www.ryanjuckett.com/programming/printing-floating-point-numbers/)
* [Printing Floating-Point Numbers Quickly and Accurately with Integers](https://www.cs.tufts.edu/~nr/cs257/archive/florian-loitsch/printf.pdf)
* [What precisely does the %g printf specifier mean? - Stack Overflow](https://stackoverflow.com/questions/54162152/what-precisely-does-the-g-printf-specifier-mean)

## Notes

1. What is Variadic Functions?
	- Variadic function takes indefinite size arity and a variable number of arguments as a parameter. Situations that you do not know how many parameters pass the function.
2. what is ellipses (...)?
	- The ellipsis (...) is part of the C language and indicates that there are 0 or more optional arguments.
2. What is va_list?
	-
3. What is va_start?
	- gets the address of the first argument.
4. What is va_arg?
	- dereference the block address and type cast it to the appropriate type. then goes to the next block of memory.
	- What is a "Type Descriptor"?
5. What is va_end?
	-
6. Calling convensions!
	- https://www.youtube.com/watch?v=JHGTXM3oIs0
	- https://en.wikipedia.org/wiki/X86_calling_conventions
	- https://www.youtube.com/watch?v=F3XiH78erNM&t=1615s
## notes
- man stdarg
