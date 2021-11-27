# LIST OF DAY06 EXERCISES

|Exercise  |Description |Solution                     
|----------|------------|---------
|[ex00](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex00/libft) | [libft](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex00/README.md) | [libft](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex00/libft)
|[ex01](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex01) | [print program name](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex01/README.md) | [ft_print_program_name.c](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex01/ft_print_program_name.c)
|[ex02](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex02) | [print params](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex02/README.md) | [ft_print_params.c](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex02/ft_print_params.c)
|[ex03](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex03) | [rev params](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex03/README.md) | [ft_rev_params.c](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex03/ft_rev_params.c)
|[ex04](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex04) | [sort params](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex04/README.md) | [ft_sort_params.c](https://github.com/achrafelkhnissi/Computer-Science/tree/master/1337/DAYS/DAY06/ex04/ft_sort_params.c)

## How to create a static libarary
![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/static_vs_dynamic1.png)
![pic alt](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/imgs/static_vs_dynamic2.png)

### The idea:
1. Compile files containing functions to object files "__.o__".
2. Bundle these object files together into one archive "__.a__".
3. Link the library to your code containing the main function.
4. After that, we compile the program using the library instead of all the source files.

### __ar__ command:
- ar [option] \<archive_name> \<member_files>
- Example: `ar rcs libsource.a source.a`

### Modify a library:
1. Compile the source.c into an object file: `gcc -c source.c -o source.o`.
2. Archive it using the command: `ar rcs libsource.a source.o`.
3. Create another source file and another header file (or add the prototype to the original header file.):
	- Compile them using `gcc -c source2.c`
4. Add it to the library using: `ar rcs libsource.a source.o source2.o`
5. Now we just have to compile the whole program into an executable:
	- `gcc main.(c/o?) -o main -L. -lsource`.

## Notes
1. On step (1): files that contains functions called source files.
2. On step (2): To bundle together all the __.o__ files that make up the library, we use the `ar` command as an archive, and it gets us parameters `r`, `c` and `s`
	- `r` stands for replace, in case a certain __.o__ file is already part of your library, you could replace it if you want.
	- `c` stands for create, to create if doesn't exist yet.
	- `s` means create an index for faster access.
	- Those are the most popular options.
3. On step (3): the linker will only extract those functions from the archive of object files that are necessary and used in your code.
4. On step (4): we compile it using: 
	- `gcc -o main main.(o/c?) library.a`
	- another way is: `gcc -o main main.o -l(libname)`
	- the `-l` adds the lib to the beginning and finds the correct extension. However, because this is a personal library and it's not contained in the standard library path, we have to add the path to the library. So `-L.` the `.` stands for the current directory. If the library was located somewhere else, the we should replace the `.` with wherever else the library is located. Ex: `gcc -o main main.o -L. -lsource`.
5. In the `ar` command example: usually the libraries start with `lib` so we need to add lib before the name of the library and adding the extension ".a" at the end.
6. In the modifying library: note that we can include all the header files into one general header file and include that one file in the main program.
7. In step of modifying the library using `gcc main.c` is the same as using `gcc main.o`.

## Resources
- [Create Libraries](https://randu.org/tutorials/c/libraries.php)

