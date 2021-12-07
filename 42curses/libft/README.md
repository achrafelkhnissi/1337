<h1 align="center">
	42cursus' libft
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' libft project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/tree/master/42curses"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/achrafelkhnissi/1337/42cursus/libft?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/ael-khni/42cursus-00-Libft?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/ael-khni/42cursus-00-Libft?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ael-khni/42cursus-00-Libft?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ael-khni/42cursus-00-Libft?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to code a C library regrouping usual functions that you'll be allowed to use in all your other projects._

For detailed information, refer to the [**subject of this project**](https://github.com/appinha/42cursus/tree/master/_PDFs).

	🚀 TLDR: this project consists of coding basic C functions (see below), which are then compiled
	into a library for use in other projects of the cursus.

### Functions from `<ctype.h>` library

* [`ft_isascii`](ft_isascii.c)		- test for ASCII character.
* [`ft_isalnum`](ft_isalnum.c)		- alphanumeric character test.
* [`ft_isalpha`](ft_isalpha.c)		- alphabetic character test.
* [`ft_islower`](ft_islower.c) *	- lower-case character test.
* [`ft_isupper`](ft_isupper.c) *	- upper-case character test.
* [`ft_isdigit`](ft_isdigit.c)		- decimal-digit character test.
* [`ft_isxdigit`](ft_isxdigit.c) *	- hexadecimal-digit character test.
* [`ft_isprint`](ft_isprint.c)		- printing character test (space character inclusive).
* [`ft_isgraph`](ft_isgraph.c) *	- printing character test (space character exclusive).
* [`ft_isspace`](ft_isspace.c) *	- white-space character test.
* [`ft_isblank`](ft_isblank.c) *	- space or tab character test.
* [`ft_ispunct`](ft_ispunct.c) *	- punctuation character test.
* [`ft_iscntrl`](ft_iscntrl.c) *	- control character test.
* [`ft_tolower`](ft_tolower.c)		- upper case to lower case letter conversion.
* [`ft_toupper`](ft_toupper.c)		- lower case to upper case letter conversion.

### Functions from `<stdlib.h>` library

* [`ft_atoi`](ft_atoi.c)		- convert ASCII string to integer.
* [`ft_atof`](ft_atof.c) *		- convert ASCII string to integer.
* [`ft_calloc`](ft_calloc.c)	- memory allocation.

### Functions from `<strings.h>` library

* [`ft_bzero`](ft_bzero.c)		- write zeroes to a byte string.
* [`ft_memset`](ft_memset.c)		- write a byte to a byte string.
* [`ft_memchr`](ft_memchr.c)		- locate byte in byte string.
* [`ft_memcmp`](ft_memcmp.c)		- compare byte string.
* [`ft_memmove`](ft_memmove.c)	- copy byte string.
* [`ft_memcpy`](ft_memcpy.c)		- copy memory area.
* [`ft_memccpy`](ft_memccpy.c)	- copy string until character found.

### Functions from `<string.h>` library

* [`ft_strlen`](ft_strlen.c)				- find length of string.
* [`ft_strlen_2`](ft_strlen_2.c) *				- find length of 2D array (i.e. splitted string).
* [`ft_strchr`](ft_strchr.c)				- locate character in string (first occurrence).
* [`ft_strrchr`](ft_strrchr.c)			- locate character in string (last occurence).
* [`ft_strstr`](ft_strstr.c) *		- locate a substring in a string.
* [`ft_strnstr`](ft_strnstr.c)			- locate a substring in a string (size-bounded).
* [`ft_strcmp`](ft_strcmp.c) *		- compare strings.
* [`ft_strncmp`](ft_strncmp.c) *			- compare strings (size-bounded).
* [`ft_strnrcmp`](ft_strnrcmp.c)			- reversely compare strings (size-bounded).
* [`ft_strcpy`](ft_strcpy.c) *		- copy strings.
* [`ft_strncpy`](ft_strncpy.c) *	- copy strings (size-bounded).
* [`ft_strdup`](ft_strdup.c)				- save a copy of a string (with malloc).
* [`ft_strndup`](ft_strndup.c) *	- save a copy of a string (with malloc, size-bounded).
* [`ft_strcat`](ft_strcat.c) *		- concatenate strings (s2 into s1).
* [`ft_strncat`](ft_strncat.c) *	- concatenate strings (s2 into s1, size-bounded).
* [`ft_strlcpy`](ft_strlcpy.c)			- size-bounded string copying.
* [`ft_strlcat`](ft_strlcat.c)			- size-bounded string concatenation.

### Functions from `<math.h>` library

* [`ft_sqrt`](ft_sqrt.c) *	- square root function.
* [`ft_pow`](ft_pow.c) *	- power function.

### Non-standard functions

* [`ft_swap`](ft_swap.c) *			- swap value of two integers.
* [`ft_putchar`](ft_putchar.c) *	- output a character to stdout.
* [`ft_putchar_fd`](ft_putchar_fd.c)		- output a character to given file.
* [`ft_putstr`](ft_putstr.c) *		- output string to stdout.
* [`ft_putstr_fd`](ft_putstr_fd.c)		- output string to given file.
* [`ft_putendl`](ft_putendl.c) *	- output string to stdout with newline.
* [`ft_putendl_fd`](ft_putendl_fd.c)		- output string to given file with newline.
* [`ft_putnbr`](ft_putnbr.c) *		- output integer to stdout.
* [`ft_putnbr_fd`](ft_putnbr_fd.c)		- output integer to given file.
* [`ft_itoa`](ft_itoa.c)					- convert integer to ASCII string.
* [`ft_substr`](ft_substr.c)				- extract substring from string.
* [`ft_strtrim`](ft_strtrim.c)			- trim beginning and end of string with the specified characters.
* [`ft_strjoin`](ft_strjoin.c)			- concatenate two strings into a new string (with malloc).
* [`ft_split`](ft_split.c)				- split string, with specified character as delimiter, into an array of strings.
* [`ft_split_free`](ft_split_free.c) *				- free splitted string.
* [`ft_strmapi`](ft_strmapi.c)			- create new string from modifying string with specified function.
* [`ft_ftoa_rnd`](ft_ftoa_rnd.c)			- convert float to ASCII string.

### Linked list functions

* [`ft_lstnew`](ft_lstnew.c)				- create new list.
* [`ft_lstsize`](ft_lstsize.c)			- count elements of a list.
* [`ft_lstlast`](ft_lstlast.c)			- find last element of list.
* [`ft_lstadd_back`](ft_lstadd_back.c)	- add new element at end of list.
* [`ft_lstadd_front`](ft_lstadd_front.c)	- add new element at beginning of list.
* [`ft_lstdelone`](ft_lstdelone.c)		- delete element from list.
* [`ft_lstclear`](ft_lstclear.c)			- delete sequence of elements of list from a starting point.
* [`ft_lstiter`](ft_lstiter.c)			- apply function to content of all list's elements.
* [`ft_lstmap`](ft_lstmap.c)				- apply function to content of all list's elements into new list.

_Note: functions marked with * are bonus functions (not mandatory by the project's subject)._

## 📑 Index

`@root`

* [**📁 libft:**](libft/) updated source code, refactored for use in other projects; includes [`get_next_line`](https://github.com/appinha/42cursus-01-get_next_line) and [`printf`](https://github.com/appinha/42cursus-01-ft_printf) functions.
* **📁 submX folder(s):** source code submitted to the cursus (including failed and succeeded submissions).
* [**📁 testing:**](testing/) my own testing program.

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/libft && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "libft.h"
```

and, when compiling your code, add the required flags:

```shell
-lft -L path/to/libft.a -I path/to/libft.h
```

## 📋 Testing

**1. First, configure the path to the libft folder in the Makefile (inside `/testing/`):**

```Makefile
#############################
## Path to Libft directory ##
#############################
DIR		= ../
```

**2. Then run:**

```shell
make t
```

### Third-party testers

* [jtoty/Libftest](https://github.com/jtoty/Libftest)
* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)
* [Night-squad/libft-war-machine-v2019](https://github.com/Night-squad/libft-war-machine-v2019)
* [t0mm4rx/libftdestructor](https://github.com/t0mm4rx/libftdestructor)
