<h1 align="center">
	42cursus' get_next_line
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' get_next_line project</i></b><br>
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
</h3>

---

## 🗣️ About

> _The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor._

	🚀 TLDR: this project consists of coding a function that returns one line at a time from a text file.

## 📑 Index

`@root`

* [**📁 get_next_line:**](get_next_line/) source code developed for the project.

`@/get_next_line/`

_Note: Files suffixed with *_bonus* are exact copies of corresponding files._

**Functions in `get_next_line.c`**

* `ft_free_null`	- free and null a pointer.
* `ft_cpy_exc_buff`	- copy read excess (string after \n) to static variable (buffer).
* `ft_buff2line`	- copy read line from buffer.
* `get_next_line`	- main function.

**Functions in `get_next_line_utils.c`**

* `ft_strlen`		- find length of string.
* `ft_strdup`		- save a copy of a string (with malloc).

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

If you're on Linux, you may as well need the following flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```

## 📋 Testing

**1. Configuring**

First, open the [`Makefile`](testing/Makefile) inside `/testing/` and configure the path to the `get_next_line` folder:

```Makefile
GNL_FOLDER	= ../get_next_line
```

**2. Running:**

For basic testing, run:

```shell
make
```

For other tests, check all available rules in the [`Makefile`](testing/Makefile).

```shell
make buf5000
```
_Usage example_

### Third-party testers

* [mrjvs/42cursus_gnl_tests](https://github.com/mrjvs/42cursus_gnl_tests)
* [Hellio404/Get_Next_Line_Tester](https://github.com/Hellio404/Get_Next_Line_Tester)
* [saarikoski-jules/gnl_unit_tests](https://github.com/saarikoski-jules/gnl_unit_tests)
* [charMstr/GNL_lover](https://github.com/charMstr/GNL_lover)
* [Mazoise/42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)


- static keyword
	- Making a global variable/function static: only visible within its own translation unit.
	- static (local variable): presistent across function calls and only visible within its function. 

note: you cant use the same name for static variable and global static variable! but never do it.
