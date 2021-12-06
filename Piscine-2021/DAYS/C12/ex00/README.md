# Exercise 00: Makefile
- Create the `Makefile` that'll compile your `libft.a`.
- The `Makefile` will get its source files from the __"srcs"__ directory.
- The `Makefile` will get its header files from the __"includes"__ directory.
- The `lib` will be at the root of the exercise.
- The `Makefile` should also implement the following rules: `clean`, `fclean` and `re` as we as `all`.
- `fclean` does the equivalent of a make `clean` and also erases thee binary created during the make. `re` does the equivalent of a make `fclean` followed by a `make`.
- We’ll only fetch your `Makefile` and test it with our files. For this exercise, only the following 5 mandatory functions of your lib have to be handled : (`ft_putchar`, `ft_putstr`, `ft_strcmp`, `ft_strlen` and `ft_swap`).
- Note: Watch for wildcards!
