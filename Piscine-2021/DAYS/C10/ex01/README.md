## Exercise 01: cat

- Create a "program" called `ft_cat` which does the same thing as the system's `cat` command-line.
- You don't have to handle options.
- The submission directory should have a `Makefile` with the following rules: `all`, `clean`, `fclean`
- You may use the variable `errno` (check `man errno`)
- You can only do this exercise by declaring a fixed-sized array. This array will have a size limited to a little less than `30ko`. In order to test that size-limit, use the `limit` command-line in your `Shell`
```
$> limit stacksize 32
$> limit stacksize
stacksize 32 kbytes
$>
```
