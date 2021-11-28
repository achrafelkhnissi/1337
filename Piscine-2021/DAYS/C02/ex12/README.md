# Exercise:
* Create a function that displays the memory area on screen.
* The display of this memory area should be split into three columns:
	* The hexadecimal address of the first line's first character;
	* The content in hexadecimal;
	* The content in printable characters.
* If characters is non-printable, it'll be replaced by a dot.
* Each line should handle sixteen characters.
* If size equal to 0, nothing should be displayed.
* It should return addr;

* Here how it should be prototyped:
```C
	void	*ft_print_memory(void *addr, unsigned int size);
```

## Example:
```
guilla_i@seattle $> ./ft_print_memory
00000000: 5361 6c75 7420 6c65 7320 616d 696e 6368  Salut les aminch 
00000010: 6573 2063 2765 7374 2063 6f6f 6c20 7368  es c'est cool sh
00000020: 6f77 206d 656d 206f 6e20 6661 6974 2064  ow mem on fait d 
00000030: 6520 7472 7563 2074 6572 7269 626c 6500  e truc terrible.
00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f    ...............
guilla_i@seattle $> ./ft_print_memory | cat -te
00000000: 5361 6c75 7420 6c65 7320 616d 696e 6368  Salut les aminch$
00000010: 6573 2063 2765 7374 2063 6f6f 6c20 7368  es c'est cool sh$ 
00000020: 6f77 206d 656d 206f 6e20 6661 6974 2064  ow mem on fait d$
00000030: 6520 7472 7563 2074 6572 7269 626c 6500  e truc terrible.$
00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f    ...............$
guilla_i@seattle $>
```


# Solution

* First we divide the problem into smaller problems and for out case\
  since we expect the output to be divided by 3 columns we create:
	* A put_addr function to print the byte of the first character;
	* A put_hex function to print the content in hexadecimal;
	* A put_str function to print the content in printable characters;
* We call the 3 function inside the print_memory function;

###  put_addr
1. **put_addr**: this function is a bit tricky even though it appears simple
   the idea is to print the address of the first character in the that\
   particular row int hexadecimal.\
   ex: considering the string "Future is loading!" of size 18\
   the put_addr function sould give the address of the first byte;\
   which is: 00000000;

   but we don't need to take the given string in order to print the addr\
   of the first character of each 16 bytes;\
   rather it is better to receive the index of the target byte from\
   the ft_print_memory function and print the addr of the target byte\
   in hex;

   **note**:
   Each hexadecimal digit represents four bits (binary digits), also known\
   as a nibble (or nybble), which is half a byte. For example, a single byte\
   can have values ranging from 00000000 to 11111111 in binary form, which\
   can be conveniently represented as 00 to FF in hexadecimal.

	* First declare the (char \*) variable to hold a string from 0 to f
	that represent hexadecimal.
	* then we declare a (static int) variable (check) to keep track of
	if the given number is checked or not\
	* Now to the step of checking, knowing that we expect the address\
	to be shown as\
	a string of size 8 (00000000)\
	considering:\
		```
		15		= 0xf		= we add 7 of '0'
		255		= 0xff		= we add 6 of '0'
		4095		= 0xfff		= we add 5 of '0'
		65535		= 0xffff	= we add 4 of '0'
		1048575	= 0xfffff	= we add 3 of '0'
		16777215	= 0xffffff	= we add 2 of '0'
		268435455	= 0xfffffff	= we add 1 of '0'
		```
	* (not that we need to check if nbr == 0 to add another '0')\
 	so the checking step is to check if a number >= one of these number\
	to add the right numbers or 0's before it
	* and because the put_addr function calls itself recursivly\
	the check step gonna be repeated and we'll get lot of 0's int our\
	output. that's why we declared the (static int) function.\
	we first see if the we already checked the given number, if not\
	we check it then assign 1 to checked varaible.
	* Then we check if nbr >= 16, if true we call put_add(nbr / 16)\
	same process as in the previous ft_putnbr but with base 16 because\
	we are dealing with hexadecimal.
	* Finally we print hexadecimal of the number with\
		ft_putchar(base[nbr % 16])\
	considerng base = "0123456789abcdef"\
	after finish we set the value of (checked to 0) so we can be able\
	to check the nbr in the next function call.

### put_hex
2. **put_hex**: this function prints 16 bytes of the given string\
	converted to hex, it takes 2 arguments, the first is the (char *)
	from the print_memory function, and the second is the index\
	from where to start printing the hex.\
	* First we declare (char \*) to string from '0' to 'a' representing\
	the hexadicemal values.
	* We declare an int variable (byte) to keep track of how many bytes\
	we printed, because the goal is to print exactly 16 byte each time\
	the function is called.
	* We start a while loop, while byte < 16 we keep iterating through\
	character of the giving string converting and printing each character\
	note: add a conditional statment to handle the space in every 2 bytes\
	(if bytes % 2 == 0) print space
	* And finally when the byte count reaches 16 we exit the loop & and\
	function.

### put_str
3. **put_str**: this function is the simplest one, the goal is to print the\
	content in printable characters (execluding space).\
	this funciton takes 3 arguments, the string, the current index\
	and the size of the string.\
	* First we declare a variable (done) to keep track of the end of\
	the given string. The idea behind this variable is that we don't
	want the function to stop even when we reach the end of the string\
	because we want to print exactly 16 bytes\
	therefore when the end of string is reached the value of done = 1\
	and we let the function to finish the last 16 bytes then we return
	the size to the print_memory function to break from the loop and\
	end the program.
	* we declare byte to keep track of how many character we printed so far\
	* we start a while loop to iterate through each character from the\
	given string and printing each printable character including space\
	and we check if we reached the end of the string along the way
	* Lastly we check if we reached the end of the string\
	if true we return the size of the given string to let the outer\
	function know that it needs to end the program.
	* And finally if done is not true and we still didn't reach the\
	end of the string, we return the number of bytes we printed (ofc 16)

## ft_print_memory

0. And finally since we're done praparing the the needed functions, now we just\
have to put them together.\
	* We declare a (char *) variable to hold the given string\
	or more currently to hold the pointer to first element of the given\
	array of characters terminated by the null character (aka string)\
	and because the we spicified in the parameter the the given argument\
	need to be of type void, we need to cast it to (converting it to (char *))
	* We decare and index variable to keep track of how many iteration\
	we made so far.
	* Now we start a while loop checking if the index if less than the\
	size of the given string.\
	if true we iterate through the loop
		1. Printing the address with put_addr
		2. Adding ':' after each time the function put_addr is called.
		3. Printing the content in hex with (put_hex).
		4. Adding two spalces.
		5. Now we print the final row with put_str, which is the
		content in printable characters excluding spalce. we pass\
		the string and the size of the string, and also the current index.
		6. We add the return value of put_str to the current value of\
		index, and if the function reaches the end of the given strinG\
		we add it to the value of index and therefore index now is\
		greater than the size of the given string.
		7. We exit the loop  and return addr.

	
	
 
