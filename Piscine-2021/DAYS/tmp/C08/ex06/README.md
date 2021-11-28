# Exercise 06: do-op

- Create a `program` called `do-op`.
- The `progam` will be executed with three arguments: `do-op` `value1` `operateur` `value2`
- Example:

```
$>./do-op 42 "+" 21
63
$>
```

- The `operator` character corresponds to the appropriate function within an array of pointers to function.
- Your directory should contain a `Makefile` with the all and clean rules.
- In the case of an invalid argument such as `./do-op foo devide bar`, the program returns `0`.
- If the number of arguments is invalid, `do-op` doesn’t display anything.
- Here’s an example of tests the `Moulinette` will run:

```
$> make clean
$> make $> ./do-op
$> ./do-op 1 + 1
2
$> ./do-op 42amis - -20toto12
62
$> ./do-op 1 p 1
0
$> ./do-op 1 + toto3
1 $>
$> ./do-op toto3 + 4 4
$> ./do-op foo plus bar 0
$> ./do-op 25 / 0
Stop : division by zero
$> ./do-op 25 % 0 Stop : modulo by zero
$>
```

- Allowed functions: `write`

