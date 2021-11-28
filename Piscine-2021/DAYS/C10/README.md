# LIST OF DAY12 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex00)      |[display file](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex00/README.md)          |[display_file.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex00/srcs/display_file.c) |
|[ex01](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex01)     |[cat](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex01/README.md)  |[ft_cat.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex01/srcs/ft_cat.c)  |
|[ex02](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex02)   |[tail](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex02/README.md)           |[ft_tail.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex02/srcs/ft_tail.c)         |
|[ex03](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex03)   |[hexdump](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex03/README.md)           |[ft_hexdump.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex03/srcs/ft_hexdump.c)      |
|[ex04](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex04)   |[last](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex04/README.md)        |[ft_last.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY12/ex04/srcs/ft_last.c)  |


## System Calls
- System calls are functions in the OS code which programs can invoke using a special instruction, these functions are the primary means by which the OS exposes functionality to programs so tat programs can use freatures or hardware like read/write data on a storage device or send/receive data across the network.
- System calls provides an interface to the services made available by an OS.
- Before we try to understand system calls in a more detailed way, there are two important points that we need to know about which is the `two modes` of operations in in which a program can execute which are known as the `user mode` and the `kernel mode`. The user mode and kernel mode are two modes which a program can execute. So if a program is executing in `user mode` that program goes not have direct access to the memory or hardware and such resources. But if a program is executing in `kernel mode` that program has direct access to all the OS resources. So we say that if a program is executing in `kernel mode` then it is in a `privileged mode` because it is having direct access to many of the resources. But the problem is that when a program is executing in kernel mode and if that program happens to crash during its execution then the entire system would crash or your entire system will come to to a halt. But if a program is executing in `user mode` and if it happens to crash then the entire system does not crash or the entire system does not come to a halt if the program is executing int user mode, so `user mode` is a safer mode of operation, though `kernel mode` is a `privileged mode`.

</p>
<p align="center">  
<img src ="https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/user-kernel-mode.png">
</p>

- The `user mode` is more safe and because of that most of the programs they execute mostly in user mode. But when a program is executing in user mode it may need access to some of the resources, like your memory or your hardware and so on.. So when the program needs access to these resources, it makes a call to your operating system telling that I need access to certain resources. So it makes a `call`, when it makes that call what happens is that for an instant the program is switched from `user mode` to `kernel mode` so that it can use those resources. When a program switches from `user mode` to `kernel mode` or vice-versa that is known as `context switching`. So when the program makes a call to the operating system saying I need to user this particular resource the `context swtich` happens when the `user mode` is switched to `kernel mode` so that the program can use those resources and then the `call` that the program makes in order to access those resources or to go into kernel mode. That call is known as the `System call`..
- `System call`n is the programmatic way in which a computer program requests a service from the kernel of the operating system.
- [Kernel - Simple Wikipedia](https://simple.wikipedia.org/wiki/Kernel_(computer_science)), [Kernel - Wikipedia](https://en.wikipedia.org/wiki/Kernel_(operating_system))
- These calls are generally available as routines written in C and C++
- [Types of System Calls](https://www.youtube.com/watch?v=EavqupVh8ls&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=10)
	- Process Control
	- File Manipulation
	- Device Management
	- Information Maintenance
	- Communications

- There are 5 basic system calls that Unix provides for file I/O.
	1. open()
	2. close()
	3. read()
	4. write()
	5. lseek()

### - [open()](https://man7.org/linux/man-pages/man2/open.2.html)

```c
#include <fcntl.h>
int	open(const char *path, int oflag, ...);
```
- `path` is a string that contains name and location of the file to be opened.
- path points to a path name naming a file.  `open` opens a file descriptor for the named file and sets the file status flags according to the value of `oflag`.
- The `mode` of the file to be opened is determined by the `oflag` variable. It must have one of the following flags:
	- `O_RDONLY`	Read only mode
	- `O_WRONLY`	Write only mode
	- `O_RDWR`	Read/Write mode
- And may have on or more options bitwise OR-ed on. A few examples of options include:
	- `O_APPEND`	If the file exists, append to it.
	- `O_CREAT`	If the file does not exist create it.
	- `O_EXCL`	(Only with O_CREAT.) If the files already exists,
				open fails and returns and error.
	- `O_TRUNC`	If the file exists and is being opened for writing,
				truncate it to length 0.
- `open()`: system call to open a file
	- open returns a file descriptor, an integer specifying the position of this open file in the table of open files for the current process.
- `open()` takes a file name, then you can give a bunch of mode flags and you can basically bitwise or them together.
- Returns an `int`, and this is called a file descriptor `fd` and this fd is just the number that the OS uses to keep track of open files, every open file has a number as a file descriptor.
- `Open()` makes a request to the operating system to use a file. The `path` argument specifies what file you would like to use, and the `flags` and `mode` arguments specify how you would like to use it. If the operating system approves your request, it will return a `file descriptor` to you. This is a non-negative integer. If it returns `-1`, then you have been denied access, and you have to check the value of the variable `errno` to determine why. (That or use `perror()`) 
- Note: The first file gonna have the `fd` 3, why 3? For each process, three I/O `streams` are opened by default, they are `stdin`, `stdout` and `stderr`. These three takes the file descriptors 0, 1 and 2. And any other file opened after that gonna get the index after 3. Ex:
	- File1: fd = 3
	- File2: fd = 4
	- File3: fd = 5
	- File4: fd = 6
	- etc.
- Finally, the 'mode' argument should only be used if you are creating a new file. It specifies the protection mode of the new file. 0644 is the most typical value -- it says "I can read and write it; everyone else can only read it"
- [Why open but not fopen](https://www.youtube.com/watch?v=BQJBe4IbsvQ&t=235s)
- [What if my open file gets deleted?](https://www.youtube.com/watch?v=MruzHlXqspU)

### - [read()](https://man7.org/linux/man-pages/man2/read.2.html)
- SYNOPSIS
```c
#include <unistd.h>
ssize_t read(int fildes, void *buf, size_t nbyte);
```
- DESCRIPTION
	- `read()` attempts to read `nbytes` from the files associated with `fildes` "fd" into the buffer pointed to by buf. If `nbytes` is zero, read returns zero and has no other results.

- `Read()` tells the operating system to read `size` bytes from the file opened in file descriptor `fd`, and to put those bytes into the location pointed to by `buf`. It returns how many bytes were actually read.
- when `read()` returns 0, then the end of file has been reached. When you are reading from a file, if `read()` returns fewer bytes than you requested, then you have reached the end of the file as well.
- “Each time it is called, `getchar()` reads the next input character from a text stream and returns that as its value. That is, after” (i guess `read()` works the same.. Same as `putchar()` and `write()`).
- The function returns the number of bytes read, 0 for end of file (EOF) and -1 in case an error occurred. It reads noct bytes from the open file referred by the fd descriptor and it puts it into a buffer buf. The pointer (current position) is incremented automatically after a reading that certain amount of bytes. The process that executes a read operation waits until the system puts the data from the disk into the buffer.

### - [write()](https://man7.org/linux/man-pages/man2/write.2.html)

- SYNOPSIS
```c
#include <unistd.h>
ssize_t write(int fildes, const void *buf, size_t nbyte);
/* write([File descriptor], [& pointer to a buffer], [Number of bytes to write]); */

```
- DESCRIPTION
	- `write()` attempts to write `nbytes` bytes from the buffer pointed to by buf to the files associated with `fildes`. If `nbytes` is zero and the files is a regular file, write returns zero and has no other results. fildes is a file descriptor.

- `write()` takes three arguments:
	- `fd`:
	- `*buf`: address in memory that points to a string. (we can directly put a string there and the compiler while find a place in memory for it and place the address of it in `buf`).
	- `nbyte`: the length in bytes.

### - [close()](https://man7.org/linux/man-pages/man2/close.2.html)

- SYNOPSIS
```c
#include <unistd.h>
int	close(int fildes);
```
- DESCRIPTION
	- `close()` closes the file descriptor indicated by `fildes`.

### - Error Handling

- Anything can fail! System calls are no exception. Try to read a file that does not exist.
- Error number: `errno`
	- every process contains a global variable `errno`
	- `errno` is set to 0 when process is created
	- when error occurs `errno` is set to specific code associated with the error cause
		- trying to open file that does not exist sets `errno` to 2
- error constants are defined in `errno.h`
	- here are the first few of `errno.h` on `OX 10.6.4`
	```c
	#define EPERM	 1	/* Operation not permitted */
	#define ENOENT	 2	/* No such file or directory */
	#define ESRCH	 3	/* No such process */ 
	#define EINTR	 4	/* Interrupted system call */
	#define EIO	 5	/* Input/output error */ 
	#define ENXIO	 6	/* Device not configured */ 
	#define E2BIG	 7	/* Argument list too long */ 
	#define ENOEXEC 8	/* Exec format error */ 
	#define EBADF	 9	/* Bad file descriptor */ 
	#define ECHILD	 10	/* No child processes */ 
	#define EDEADLK 11	/* Resource deadlock avoided */
	```
- common mistake for displaying `errno`
	- from Linux `man errno`:
	```c
	if (somecall() == -1) {
		printf("somecall() failed\n");
		if (errno == ...) { ... };
	}

	/*
	where errno no longer needs to have the value it had upon return from "somecall()"
	(i.e., it may have been changed by the printf()). If the value of errno 
	should be preserved accross a library call, it must be saved.
	*/

	if (somecall() == -1) {
		int errsv = errno;
		printf("somecall() failed\n");
		if (errsv == ...) { ... };
	}
	```
- [More](http://www2.cs.uidaho.edu/~krings/CS270/Notes.S10/270-F10-24.pdf) [...](http://www2.cs.uidaho.edu/~krings/CS270/)

### - File Descriptor Table

- Note: The first file gonna have the `fd` 3, why 3? For each process, three I/O `streams` are opened by default, they are `stdin`, `stdout` and `stderr`. These three takes the file descriptors 0, 1 and 2. And any other file opened after that gonna get the index after 3. Ex:
	- File1: fd = 3
	- File2: fd = 4
	- File3: fd = 5
	- File4: fd = 6
	- etc.
- Use the command `limit` to check limit of how many files a program can open.
- The `fd` table is an array
	- for on running process
	- associated with every process
	- list of open files stored in the `fd` table
	- each entry corresponds to one open file
	- that is copied when `fork` is executed
- e.g.:
	- each process has its own table
	- `open()`: add an entry to the table (new file created)
	- `close()`: delete an entry from the table
	- this is for a "normal" process, one with no redirection of i/o (no forks)
	- fd # from 0 to 31
	```
	      __________    
	 0-   | 0	|  - stdin -- keyboard
	      | 1	|  - stdout -- screen
	      | 2	|  - stderr -- screen
	      | 3	|  - file 'A', closed, now a NULL value
	      | 4	|  - "myfile"
	      | 5	|
	      | 6	|
	      | 7	|
	      | 	|
	      | .	|
	      | :	|
	 31-  | 31	| 
	```
- `fork` -> copy of this table goes with the new process
- One unique file descriptors table is provided in operating system for each process.
- [Redirection & more](http://www2.cs.uregina.ca/~hamilton/courses/330/notes/unix/filesyscalls.html)

## File Input/Output
- Files are used for data persistence
- Files are stored on secondary storage devices, such as hard disks, CDs, flash drives, etc.
- When a file is "opened" in a program, an object (in out code) is created and a stream is associated with the object. That stream is what gives us the ability to read or write to that file.

## Notes

- [Unix System Calls (1/2)](https://www.youtube.com/watch?v=xHu7qI1gDPA)
- [Closing descriptors](https://docs.fedoraproject.org/en-US/Fedora_Security_Team/1/html/Defensive_Coding/sect-Defensive_Coding-Tasks-Descriptors.html): If a descriptor is no longer used by a program and is not closed explicitly, its number cannot be reused (which is problematic in itself, see Section 9.3, “Dealing with the select limit”), and the kernel resources are not freed. Therefore, it is important to close all descriptors at the earlierst point in time possible, but not earlier.

- To google:
	- stream oriented data files: the data is stored in the same manner as it appear on the screen.
	- system oriented data files: the data files are more closely associated with the OS.

- When we're talking about writing a file to a persistent storage which is hopefully something that when it does not have power it's still going to persist the data which is usually beyond the main memory. main memory needs power so that it can hold that data.
- Some library functions have embedded system calls. For instance, the library routines `scanf` and `printf` make use of the system calls `read` and `write`. The relationship of library functions and system calls is shown in the below diagram (taken from John Shapley Gray's Interprocess Communications in UNIX)
```
+------------+
| Executable |	     +--------------+       +--------+       +----------+
| Program    | ----> | System Calls | ----> | Kernel | ----> | Hardware |
+------------+	     +--------------+	    +--------+       +----------+
       ^   		     ^ 
       |		     |
       |    +-------------------+
       +----| Library Funcitons |
	    +-------------------+
```
- What is a process?: A process is basically a program in execution. [Detail - Wikipedia](https://en.wikipedia.org/wiki/Process_(computing))

## Resources

- [System Call in OS: Types and Examples](https://www.guru99.com/system-call-operating-system.html)
- [System calls for working with files and directories in Linux](https://profile.iiita.ac.in/bibhas.ghoshal/lab_files/System%20calls%20for%20files%20and%20directories%20in%20Linux.html)
- [man syscalls](https://man7.org/linux/man-pages/man2/syscalls.2.html)
- [How to Map Files into Memory in C (mmap, memory mapped file io)](https://www.youtube.com/watch?v=m7E9piHcfr4&t=9s)
- [System Calls Related to File Manipulation](https://docplayer.net/282598-System-calls-related-to-file-manipulation.html) (also see the section of "Similar documents")
- [CS 330 System Calls for I/O](https://www.cs.uregina.ca/Links/class-info/330/SystemCall_IO/SystemCall_IO.html)
- [CS360 Lecture notes -- Introduction to System Calls (I/O System Calls)](http://web.eecs.utk.edu/~huangj/cs360/360/notes/Syscall-Intro/lecture.html)
- [CSCI 4061: Input/Output with Files, Pipes](https://www-users.cs.umn.edu/~kauffman/4061/05-io-files-pipes.pdf)
- [What are file descriptors, explained in simple terms?](https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms)
- [What does >& mean?](https://stackoverflow.com/questions/11255447/what-does-mean)
- [Retrieve filename from file descriptor in C](https://stackoverflow.com/questions/1188757/retrieve-filename-from-file-descriptor-in-c)
- [How do file descriptors work?](https://stackoverflow.com/questions/7082001/how-do-file-descriptors-worko)
- [File Descriptors](https://www.bottomupcs.com/file_descriptors.xhtml)
- [Systems Programming in C](https://www.cs.cmu.edu/~guna/15-123S11/Lectures/Lecture24.pdf)
- [C Programming! Streams](https://www.youtube.com/watch?v=XnTcLfKxFPY)
- [C Programming! Buffers](https://www.youtube.com/watch?v=hwx3C18eQwc)
- [Open-read-write-fd](https://www.youtube.com/watch?v=ybvbDlsDdk4&list=PLlr7wO747mNp5nn0hteJFnt1rpdx6GG-_)
