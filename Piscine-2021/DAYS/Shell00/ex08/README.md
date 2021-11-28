## EXERCISE 10

* In a file called **clear**, place the command line that will search for all files - in the current directory as well as in its sub-directories - end by ~, and/or all files that start or end by #
* The command line will show and erase all files found.
* Only one command is allowed: no ';' or '&&' or other shenanigans.

HINT: man find

------------------------------------------
## If we STFE!(Search the Fuc***g Ethernet) we will see that:

* `find` is the command that can address all the requirements.
* so next we can `man find` and we can with the next solution:

```
$ find . -name "*~" -print -delete -o -name "*#" -print -delete -o -name "#*" -print -delete

-name [pattern]
		Base of file name (the path with the leading directories removed)
		matches shell pattern.
-print [format]
-delete:
		Delete  files;  true  if  removal succeeded.  If the removal failed,
		an error message is issued.  If -delete fails, find's exit status will
		be nonzero (when it eventually exits).  Use of -delete automatically
		turns on the `-depth' option.
-o:
		Ensures that the right hand side is evaluated only for those directories
		which didn't get deleted before.
```
---------------------

```bash
find . -type f \( -name "#*#" -o -name "*~" \) -delete
```
