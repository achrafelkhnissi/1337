# Exercise 09: ft_advanced_do-op

> Topic: Using Function Pointer with Struct && array of pointers to functions

- Create a program that does the same as `do-op` with one difference: you have to include the file `ft_opp.h` which will define which pointer to function corresponds to which character.

```
$>cat ft_opp.h

#ifndef FT_OPP_H
#define FT_OPP_H

t_opp g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod},
	{"", &ft_usage}
};

#endif

$>
```

- You’ll have to create at least 6 functions: `ft_add`, `ft_sub`, `ft_mul`, `ft_div`, `ft_mod`, `ft_usage`.
- `ft_usage` displays the possible characters (defined in `ft_opp.h`) just like in the following example:

```
$> make clean
$> make
$> ./ft_advanced_do-op
$> ./ft_advanced_do-op 1 + 1
2
$> ./ft_advanced_do-op 1 p 1
error : only [ - + * / % ] are accepted.
$> ./ft_advanced_do-op 1 + toto3
1
$> ./ft_advanced_do-op 25 / 0
Stop : division by zero
$> ./ft_advanced_do-op 25 % 0
Stop : modulo by zero
$>
```

- You have to define the type of `t_opp` which corresponds to the `s_opp` structure allowing the compilation of your project.
- Don’t write ANYTHING in the `ft_opp.h` file, not even `t_opp’s` definition. Add the 42 header at the top of the file to respect the Norm. Include your own files if necessary.
- Only display an error for the operators that don’t have a connection in `ft_opp.h`.
- We probably won’t be using the same `ft_opp.h` every time...
- Hint: An operator can be made up of several characters.
- Allowed functions: `write`

### Notes

- In comparing the operators "+" and so on.. It is highly important to dereference the `char * op` with `*g_do-op[i].opp`.
- Also when declaring the array of structures don't forget the = sign.
