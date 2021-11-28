### Make file size = 40
After creating file testDay00 with the command touch, you should resize it,
the efficient way to do so is by using fallocate with -l flag.
You can do same thing using multiple commands, like dd (Copy and convert),
also there is a simple way to just do so, using vim editor, just open file 
using vim editor, and fill it with characters/symbols.
Example using fallocate:
```
$ fallocate -l 40 testShell00
ls -l
total 1
-rw-r--r-- 1 vlad vlad   40 sept.  4 07:53 testDay00

Example using dd:

$ dd if=/dev/zero of=testDay00 bs=40 count=1
1+0 enregistrements lus
1+0 enregistrements écrits
35 bytes copied, 0.000495593 s, 70.6 kB/s
```
------------------------------------------
### Change the timestamp
Using the command [TOUCH](https://linux.die.net/man/1/touch):
```
$ touch -amt 202406012342 file_name
```
Where:
```
-a = accessed
-m = modified
-t = timestamp - use [[CC]YY]MMDDhhmm[.ss] time format
```
What's inside [] is optional.

------------------------------------------
### Change file permissions with [CHMOD](https://en.wikipedia.org/wiki/Chmod)
The chmod command is used to change the permissions of a file or directory.
To use it, you specify the desired permission settings and the file or files
that you wish to modify. There are two ways to specify the permissions, but
I am only going to teach one way.

It is easy to think of the permission settings as a series of bits
(which is how the computer thinks about them). Here's how it works:

```
rwx rwx rwx = 111 111 111
rw- rw- rw- = 110 110 110
rwx --- --- = 111 000 000
```
and so on...
```
rwx = 111 in binary = 7
rw- = 110 in binary = 6
r-x = 101 in binary = 5
r-- = 100 in binary = 4
```

Example:
```
$ chmod 455 testDay00
```

Here the digits 4, 5, and 5 each individually represent the permissions for the
user, group, and others, in that order. Each digit is a combination of the
numbers 4, 2, 1, and 0:

* 4 stands for "read",
* 2 stands for "write",
* 1 stands for "execute", and
* 0 stands for "no permission."

So 7 is the combination of permissions 4+2+1 (read, write, and execute),\
5 is 4+0+1 (read, no write, and execute), and 4 is 4+0+0\
(read, no write, and no execute).

|  #  |       Permission        | bin | rwx |
|:---:|:-----------------------:|:---:|:---:|
|  7  | read, write and execute | 111 | rwx |
|  6  | read and write	        | 110 | rw- |
|  5  | read and execute	| 101 | r-x |
|  4  | read only		| 100 | r-- |
|  3  | write and execute	| 011 | -wx |
|  2  | write only		| 010 | -w- |
|  1  | execute only		| 001 | --x |
|  0  | none			| 000 | --- |

For more detail read `man` entry of `chmod`:
```
$ man chmod
```
