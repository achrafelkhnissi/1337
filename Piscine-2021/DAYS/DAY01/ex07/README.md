# Exercise 07: r_dwssap

- Write a command line that displays the output of a cat /etc/passwd command, removing comments, every other line starting from the second line, reversing each lo- gin, sorted in reverse alphabetical order, and keeping only logins between FT_LINE1 and FT_LINE2 included, and they must separated by ", " (without quotation marks), and the output must end with a ".".

- Example: Between lines 8 and 16, the result should be something like this:
```
$> ./r_dwssap.sh
sstq_, sorebrek_brk_, soibten_, sergtsop_, scodved_, rlaxcm_, rgmecived_, revreswodniw_, revressta_
.$>
```

HINT: Rigorously follow the order indicated in the instructions.

## [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex07)

------------------------------------------
## Pending:
* Looking inside 'cat /etc/passwd':
We still need to deconstruct the problem and explain the solution for...
	```
	cat /etc/passwd | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e 's/:.*//g' \
	| tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" ","  \
	| sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//'
	```

> This answer is still missing the ending with a dot (.)

## Notes
- To add `.` to the end of the output: `sed 's/,$/./'`. 
