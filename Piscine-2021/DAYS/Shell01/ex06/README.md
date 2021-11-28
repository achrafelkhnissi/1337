# Exercise 06: Skip

- Write a command line that displays every other line for the command ls -l, starting from the first line.

------------------------------------------
## We can use `ls` in combination with `awk` for this:
* First we use the command `ls -l` to display all contents on the current
directory in a list format, then pass the results forward using pipe `|` for
`awk` with the option:
NR → The total number of input records seen so far.
And the `% 2 == 1` to print every second line counting from line 0.
	```
	ls -l | awk 'NR % 2 == 1'
	```
