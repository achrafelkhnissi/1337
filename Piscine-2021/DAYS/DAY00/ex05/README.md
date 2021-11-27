## EXERCISE 05

* Now that you understand the basics of LDAP (sort of), you can start looking for poeple.
* In a file called **poeple.sh**, type in the command that will list the **cn** list for all accounts that have a **uid** starting with 'z'. This list will only show the **cn**, in reverse alphabetical order, and NOT case-sensitive. There shouldn't be any unnecessary empty lines.

HINT: LDAP search-filters have a specific syntax.

------------------------------------------
#### If we RTFM! (man ls) we will see that:

| | |
|--|--
|-t| sort by modigication time, newst first
|-r| --reverse: reverse order while sorting
|-h| --human-readable: with -l and -s, print like 1k 33M 7G ect 
|-p| --indicator-style=slash: append / indicator to derictories
|-m| fill width with a comma separated list of entries


> Here we encounter a problem, because at least with the command `ls` we can't
truly sort the results by creation date, so we need to create a script or use
other methods to ensure we display the results in the desired manner. This is
given because most UNIXes do not have a concept of file creation time, so we
can't make `ls` print it because the information is not recorded.

For those looking for more go to my [sources](https://unix.stackexchange.com/questions/91197/how-to-find-creation-date-of-file)
here.
------------------------------------------


