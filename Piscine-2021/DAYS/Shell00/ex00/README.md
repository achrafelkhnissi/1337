## EXERCISE 00

* Create a file called **z** that returns "Z", followed by a new line, whenever the command cat is used on it. 
```
?>cat z Z
?>
```

## Ok this Exercise is kind of a joke...

Because if we read the `man cat` page we see that this command just
*"concatenate files and print on the standard output"*. So is going to print
whatever we put inside the target file **z**, and in this case is only needed to
put a simple '**Z**' inside our file, using vim or nano.
You can also use echo command and redirection to redirect the character z inside the file Z.

Example:
```sh
echo "Z" > z
```
