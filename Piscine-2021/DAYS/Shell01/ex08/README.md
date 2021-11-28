# Exercise 09: add_chelou

- Write a command line that takes numbers from variables FT_NBR1, in ’\"?! base, and FT_NBR2, in mrdoc base, and displays the sum of both in gtaio luSnemf base.


	- Example 1:
	```
	FT_NBR1=\?"\"\
	FT_NBR2=rcrdmddd
	```
	- The sum is:
	```
	Salut
	```
	- Example 2:
	```
	FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"!\"\"
	FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
	```
	- The sum is:
	```
	Segmentation fault
	```

## Notes

### Replacement command: substitution
```
sed 's/search-pattern/replecement-string/flags'
```
- the flag `-i` stands for in place editing (to save the changes to the file).
- Sed goes through each lines at a time and change the first occurrence of the matching pattern with the replacement.
- It is optional to add flags
- Idk if you can add more than 1 flag and how (yet)
- By default, only the first occurrence of the matching pattern in the current line gonna get replaced, to change that you need to add the flag `g` for global.
- [Error: extra characters at the end of l command](https://stackoverflow.com/questions/35620009/sed-extra-characters-at-end-of-l-command)
- Instead of forward slash `/` you can use any symbol by using it like this: `s#pattern#replacement`


### Delete command: d
```
sed '/This/d' filename.txt
# delete all the lines that contains the word 'This'
```
- To use multiple commands or multiple sed expressions we use `;` `sed '/^#/d ; /^$/d' filename.txt` or use the `-e` option.


## Resources

- [sed, a stream editor](https://www.gnu.org/software/sed/manual/sed.html)
- [Sed - Intro and Tutorial by Bruce Barnett](https://www.grymoire.com/Unix/Sed.html)
- [Sed basics](https://www.youtube.com/watch?v=qEA7FGNAMrU)
- [RegEx](https://www.youtube.com/watch?v=AHn9HMTG9Yc)
- [Sed Tutorial - tutorialspoint](https://www.tutorialspoint.com/sed/index.htm)
- [Linux sed command](https://www.computerhope.com/unix/used.htm)
- [Sed: a 5min practical guide](https://cameronnokes.com/blog/sed-5-min-practical-guide/)
- [Sed advanced](https://www.linuxtopia.org/online_books/advanced_bash_scripting_guide/x17375.html)
