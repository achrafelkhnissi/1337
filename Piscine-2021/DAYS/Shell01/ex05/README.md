# Exercise 05: Can you create it?

- Create a file containing only "42", and NOTHING else.
- Its name will be: `"\?$*MaRViN*$?\"`
- Example:
```
$>ls -lRa *waM* | cat -e
-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*KwaMe*$?\"$
$>
```
------------------------------------------
## There are two solutions (that I know of) for this:
* The easiest is just use the command `touch` to create the file and we need to
specify the name like this:
	```
	touch \"\\\?\$\*'KwaMe'\*\$\?\\\"
	```
* And the other way is just to create a temp file with whichever name you want
and rename it to "\?$*'MaRViN'*$?\"

> Let's not forget to include the '42' inside that file after completing the
previous steps.

