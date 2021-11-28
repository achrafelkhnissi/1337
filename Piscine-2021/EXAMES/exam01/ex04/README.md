## Exercise

```
======================================./1-0-ulstr.txt=====================================
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
------------------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
==========================================================================================
```

## Algorithm

- First we check if the input is 2 `argc`
- If true. We go through each character of the second argument of the input.
- We check if the character is lowercase.
	- If True. We print it in uppercase. (by subtracting 32 from it)
- We check if the character is uppercase.
	- If True. We print it in lowercase. (by adding 32 from it)
- Else we print the char as it is.
- Finally we print a new line.

