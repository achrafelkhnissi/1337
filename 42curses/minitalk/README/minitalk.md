# Project
## STEP 1: Make server receive a signal from client
in __minitalk__ there are two processes/programs: the client and the server. What the project consists of is the communication between both processes. More precisely the __client__ process sends a message - string - to the process ID that was given as a parameter - __server__

The first logical step I took while doing the project was to make the first "connection" between both programs. So I made the client sent a signal `SIGUSR1` to the server by using [`kill()`]() command.

By using the funciton [`getpid`]() I managed to get the process ID of the server program that I want to send a signal to. \
This is what happens when you execute `server`:
```
	███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗		
	██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝		 
	██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗		 
	██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗		
	╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝		

		PID: 51777			By: ael-khni
	⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰
```
The client will then receive the server's PID and by using the `kill()` command will send a signal `SIGUSR1` to the server. \
You execute client like this:
```shell
➜  minitalk git:(main) ✗ ./client 12750
```
Then just like that the server recieves a signal and outputs a message to the shell
```
	███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗		
	██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝		 
	██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗		 
	██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗		
	╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝		

		PID: 51777			By: ael-khni
	⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰		
signal 10 received.
```
CODE:
```c
// client.c
int	main(int argc, char *argv[])
{
   int	pid;

   if (argc != 2)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   kill(pid, SIGUSR1);
   return (0);
}
```
```c
// server.c
void	handler_sigusr1(int signum)
{
   printf("signal %d received.\n", signum);
}

int	main(void)
{
   pid_t	pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr1);
   while (1)
   	pause();
}
```
## STEP 2: Convert ASCII character to Binary character
ASCII stands for American Standard Code for Information Interchange and its a way to represent text in a computer. The ASCII table represents all the 127 ASCII characters and their values. That means that every character is represented by a number. \
The way two programs can communicate via signals - more precisely `SIGUSR1` and `SIGUSR2` - is to make them represent a binary value each. In this case we consider that `SIGUSR1` represents 0 and `SIGUSR2` represents 1. So when we send a `SIGUSR1` signal we are sending 0 to server and by sending a `SIGUSR2` signal we are sending 1.

This second step is focused on getting all the bits from a character - 8 bits in ASCII - this means that server will need to receive 8 signals from client for every ASCII character.
> The character __a__ is represented by the number 97 in the ASCII table. \
> In binary 97 is 01100001

The big question here is how to get the character's bits one by one.! \
We get them by using Bitwise Operators. \ 
More precisely `<<` and `&`:
> The __LEFT SHIFT__ (<<) operator moves the bits to the left, discards the far left bit, and assigns the rightmost bit a value of 0.\
> 0000 0001 << 1 = 0000 0010 [1 << 1 = 2] \
> 0000 0001 << 2 = 0000 0100 [1 << 2 = 4]

> The __AND__ (&) operator compares two bits and generates a result of 1 if both bits are 1. otherwise it returns 0.\
> 0110 0001 & 1000 0000 = 0000 0000 [97 & 128 = 0] \
> 0110 0001 << 1 = 1100 0010 = [97 << 1 = 167] \
> 1100 0010 & 1000 0000 = 1000 0000 [167 & 128 == 128]

The logic of the program is very simple!
- By using the number __128__ we get a binary number that has only 1 at the leftmost bit and the rest is 0 [1000 0000]. We then compare (by using the `&` operator) 128 with the number associated to the character we want `client` to sent to `server`
- This operator will return 0 if the first bit of that character is 0, and 128 if the first bit is 1.
- After that we shift the bits to the left by 1 to check the next bit on the line `0110 0001 << 1 == 1100 0010` & repeat the process
The code is something like this:
```c
#include <stdio.h>

void    print_bits(unsigned char octet)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		putchar((octet & 128) ? '1' : '0');
		octet <<= 1;
		bit++;
	}
	putchar('\n');
}

int main(int ac, char **av)
{
	int	i;
	char *word;
	
	i = 0;
	if (ac != 2)
		return (1);
	word = av[1];
	printf("Word = %s\n", word);
	while (word[i])
	{
		printf("%c[%d]:\t", word[i], word[i]);
		print_bits(word[i]);
		i++;
	}
	return (0);
}
```
__Desired ouput__: CHARACTER[ASCII CODE]: BINARY
```
➜  minitalk git:(main) ✗ gcc print_bits.c && ./a.out ael-khni
Word = ael-khni
a[97]:	01100001
e[101]:	01100101
l[108]:	01101100
-[45]:	00101101
k[107]:	01101011
h[104]:	01101000
n[110]:	01101110
i[105]:	01101001
```
CODE:
```c
// server.c
void	handler_sigusr2(int signum)
{
   (void)signum;
   write(1, "1", 1);
}

void	handler_sigusr1(int signum)
{
   (void)signum;
   write(1, "0", 1);
}

int	main(void)
{
   pid_t	pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr1);
   signal(SIGUSR2, handler_sigusr2);
   while (1)
   	pause();
}
```
```c
// client.c
void	send_signals(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		bit++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
   int		pid;

   if (argc != 3)
   {
   	printf("client: invalid arguments\n");
   	printf("\tcorrect format [./%s SERVER_PID MESSAGE\n]", argv[0]);
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   send_signals(*argv[2], pid);
   return (0);
}
```

## STEP 3: Convert Binary character to ASCII character
Now that `client` can send several signals to `server`, and now that `client` is able to decide whether to send a `SIGUSR1` or `SIGUSR2` signal depending on the bit value of the character it wants to send. It's up to the `server` program to convert those signals back to an ASCII character.

This third step focuses on just that! There's a lot of methods to convert from binary to decimal but i choosed to use the `|` operator. \
the program is able to convert the signals to a character.
> The __OR__ `|` operator compares two bits and generates a result of 1 if one of them is 1 otherwise it returns 1. \
> 1111 0000 | 1111 1111 = 1111 1111 \
> 0110 0001 | 1000 0000 = 0000 0000

In Step 2, an ASCII character is converted to signals. In this step, signals are turned into an ASCII character. This program is somehow the reverse logic of the previous step:
```c
c |= (sig == SIGUSR2);
c <<= 1;
```
- First we check if the signal received `sig` is the `SIGUSR2` signal! if true then the comparision is 1 and 0 if false:
- Then when server recieves a signal from client, the function `handler_sigusr()` is called. This function works with two static variables one __int__, that represents the number of bits, and one __char__ that is the character whose bits server is receiving.
- If the signal client sent to the server `SIGUSR2` - that represents 1 for client - then the program uses the `|` opertor and assign that bit to the __char__ variable. otherwies it assign bit 0.
> Example: Assuming the client sent "0110 0001" ('a' | 97) \
> The variable 'c' currently equal to 0000 0000 therefore:\
> 0000 0000 |= (0000 0000) == 0000 0000. then we shfit c to the left by 1 `c <<= 1` \
> 0000 0000 |= (0000 0001) == 0000 0001. ; `c <<= 1` \
> 0000 0010 |= (0000 0001) == 0000 0001. ; `c <<= 1` \
> 0000 0110 |= (0000 0000) == 0000 0000. ; `c <<= 1` \
> 0000 1100 |= (0000 0000) == 0000 0000. ; `c <<= 1` \
> 0001 1000 |= (0000 0000) == 0000 0000. ; `c <<= 1` \
> 0011 0000 |= (0000 0000) == 0000 0000. ; `c <<= 1` \
> 0110 0001 |= (0000 0001) == 0000 0000. ; `c <<= 1` \
> 0110 0001 to decimal == 97 and to ascii == 'a';

## STEP 4: Sending a string from client to server
This is the final step of the project. In this step I made `client` send a string to `server`

To better explain minitalk:
- `client` will send a signal - representing the first bit of the string it wants to send - to `server`
- `server` will receive the signal and start creating the first character of the string.
- `server` should then send a signal to `client` confirming that it received it's signal.
- This will happen until `client` sends 8 signals to `server`, note that the server should be confirming every signal by sending a signal back each time.
- After receiving the 8 signals `server` will have the first character of the string. This will happen untill all characters of the string are sent.
- After receiving 8 bits representing the `NULL` character `0000 0000` it means that the `server` received the full string
- `server` will send a signal to `client` confirming that the whole string was successfully send and should wait for another string to be sent from the same or different `client`
- In case of an error occurs in `server`, client will receive a signal and terminate the process (optional).

# Links

- [BitwiseCmd](https://bitwisecmd.com)
