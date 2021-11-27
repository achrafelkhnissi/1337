## Exercise 00: display_file

- Create a `program` called `ft_display_file` that displays, on the standard output, only the content of the file given as argument.
- The submission directory should have a `Makefile` with the following rules: `all`, `clean`, `fclean`. The binary will be called `ft_display_file`.
- The `malloc` function is forbidden. You can only do this exercise by declaring fixed-sized array.
- All files given as arguments will be valid.
- Error messages have to be displayed on their reserved output.
```
$> ./ft_display_file
File name missing.
$> ./ft_display_file Makefile
*contenu du Makefile*
$> ./ft_display_file Makefile display_file.c
Too many arguments.
$>
```
- Allowed functions: close, open, read, write
