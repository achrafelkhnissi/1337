## Project Information

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*. \
Keep in mind:
- You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc).
- Your program cannot have memory leaks.
- You can use one global variable but it must be justified.

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- ['ft_printf']() and any equivalent YOU coded
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

## Compilation

1. Clone repo including [`libft`](../../../42-libft) submodule via `git clone --recursive https://github.com/hanshazairi/42-minitalk.git`.
2. Compile files into `server` & `client` executables via `make -C 42-minitalk`.
