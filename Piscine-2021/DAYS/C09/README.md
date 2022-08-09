# C09 EXERCISES


|Exercise  |Description |Solution                     
|----------|------------|---------
|[ex00](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex00/) | [libft](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex00/README.md) | [libft_creator.sh](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex00/libft_creator.sh)
|[ex01](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex01) | [Makefile](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex01/README.md) | [Makefile](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex01/makefile)
|[ex02](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex02) | [split](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex02/README.md) | [ft_split.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/C09/ex02/ft_split.c)


## How to create a static libarary
![pic alt](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/static_vs_dynamic1.png)
![pic alt](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/static_vs_dynamic2.png)

### The idea:
1. Compile files containing functions to object files "__.o__".
2. Bundle these object files together into one archive "__.a__".
3. Link the library to your code containing the main function.
4. After that, we compile the program using the library instead of all the source files.

### __ar__ command:
- ar [option] \<archive_name> \<member_files>
- Example: `ar rcs libsource.a source.a`

### Modify a library:
1. Compile the source.c into an object file: `gcc -c source.c -o source.o`.
2. Archive it using the command: `ar rcs libsource.a source.o`.
3. Create another source file and another header file (or add the prototype to the original header file.):
	- Compile them using `gcc -c source2.c`
4. Add it to the library using: `ar rcs libsource.a source.o source2.o`
5. Now we just have to compile the whole program into an executable:
	- `gcc main.(c/o?) -o main -L. -lsource`.

## Notes
1. On step (1): files that contains functions called source files.
2. On step (2): To bundle together all the __.o__ files that make up the library, we use the `ar` command as an archive, and it gets us parameters `r`, `c` and `s`
	- `r` stands for replace, in case a certain __.o__ file is already part of your library, you could replace it if you want.
	- `c` stands for create, to create if doesn't exist yet.
	- `s` means create an index for faster access.
	- Those are the most popular options.
3. On step (3): the linker will only extract those functions from the archive of object files that are necessary and used in your code.
4. On step (4): we compile it using: 
	- `gcc -o main main.(o/c?) library.a`
	- another way is: `gcc -o main main.o -l(libname)`
	- the `-l` adds the lib to the beginning and finds the correct extension. However, because this is a personal library and it's not contained in the standard library path, we have to add the path to the library. So `-L.` the `.` stands for the current directory. If the library was located somewhere else, the we should replace the `.` with wherever else the library is located. Ex: `gcc -o main main.o -L. -lsource`.
5. In the `ar` command example: usually the libraries start with `lib` so we need to add lib before the name of the library and adding the extension ".a" at the end.
6. In the modifying library: note that we can include all the header files into one general header file and include that one file in the main program.
7. In step of modifying the library using `gcc main.c` is the same as using `gcc main.o`.

## Resources
- [Create Libraries](https://randu.org/tutorials/c/libraries.php)


## Makefile
### Useful sources

> [GNU Make [manual]](https://www.gnu.org/software/make/manual/html_node/index.html)\
> [Makefile Tutorial](https://makefiletutorial.com/#-wildcard)\
> [C Programming: Makefiles - YT[super basic]](https://www.youtube.com/watch?v=GExnnTaBELk&t=14s)\
> [Makefile [5S]](https://www.youtube.com/watch?v=FfG-QqRK4cY)
> [Little Cheat Sheet](https://swcarpentry.github.io/make-novice/reference.html)\
> [Pitfalls of Using Wildcards](https://www.gnu.org/software/make/manual/html_node/Wildcard-Pitfall.html#Wildcard-Pitfall)

> [-I Flag [stackoverflow]](https://stackoverflow.com/questions/27660713/including-header-file-from-static-library)\
> [gcc -I option flag](https://www.rapidtables.com/code/linux/gcc/gcc-i.html)

### makefile syntax [basic]
A makefile consists of a set of rules, a rule generally looks like this:
```makefile
targets: prerequisites
	command
	command
	command
```
- the targets are file name, separated by spaces. typically, there is only one per rule.
- the commands are a series of steps typically used to make the target(s). these need to start with a `\tab` character, not spaces.
- The prerequisites are also file names, separated by spaces. These files needs to exist before the commands for the target are run. These are also called dependencies.

The following `Makefile` has three separate rules. When you run `make exec` int the terminal, it will build a program called `exec` in a series of steps:

```Makefile
exec: main_obg.o
    cc obj.o -o exec # Runs third

obj.o: main.c
    cc -c main.c -o obj.o # Runs second

main.c:
    echo "int main() { return 0; }" > main.c # Runs first
```

- `Make` is given `exec` as the target, so it first searches for this target.
- `exec` requires `obj.o`, so 'make' searches for the `obj.o` target.
- `obj.o` requires `main.c`, so make searches for the `main.c` target.
- `main.c` has no dependencies, so the echo command is run.
- The `gcc -c` command is then run, because all of the `obj.o` dependencies are finished.
- The top `gcc` command is run, because all the `exec` dependencies are finished.
- That's it: `exec` is a compiled `c` program.
    touch file2

### Assignment Operators

```Makefile
SRCS = main.c
SRCS := $(wildcard *.c)
SRCS != find . -name '*.c'
SRCS := $(shell find -name '*.c')
CC_FLAGS += -Wextra
CFLAGS ?= $(CC_FLAGS)
FOO := $(BAR) # Comment
```
- `=` Verbatim assignment.
- `:=` Simple expansion.
- `!=` Shell output
- `?=` Conditional assignment.
- `+=` Append to.

### Built in functions

```Makefile
$(SRCS:.c=.o)			# Text functions
$(addprefix build/), $(OBJS))	# Filename functions
$(if ..) $(or ..) $(and ..) 	# Conditional functions
$(foreach var, list, text)	#
$(value (VARIABLE))		# Value function
$(shell ..)			# Shell function
$(error ..)			# Control functions
$(warning ..)			#
$(info ..)			#	
```

### Rules
```Makefile
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
%.o: %.f
	$(FC) -c $(FFLAGS) -o $@ $<
%.o: %.p
	$(PC) -c $(PFLAGS) -o $@ $<
```
- Rules are shell commands emitted by Make to produce an output file.
- Rules use pattern matching on file types. The rule Make uses depends on how the recipe is configured.
- There are many implicit rules built into Make for different file types.
- Implicit rules become obsolete very quickly.

### Automatic Variables

- `$@`: Current target
- `@<`: First dependency
- `$^`: All dependencies
- `$?`: Dependencies that have changed
- `$|`: Order-only dependency. # Prevent the whole dir to be rebuilt.. (just the changed files)

### Automatic Dependency
> [Makefiles [min 25:00]](https://youtu.be/FfG-QqRK4cY?t=1500)

#### Template Makefile
```Makefile
SRCS := $(wildcard *.c)
OBJDIR = .build
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

DEPDIR = .dep
DEPS := $(SRCS:%.c=$(DEPDIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.PHONY: clean
TARGET = foo 	# Change this.

$(OBJDIR)/%.o: %.c | $(OBJDIR) $(DEPDIR)
	@echo [CC] $@
	@$(CC) -c $(CFLAGS) $(DEPFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	@echo [LD] $@
	@$(CC) $(LDFLAGS) -o $@ $^

clean:
	@rm -rf $(OBJDIR) $(DEPDIR) $(TARGET)

$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

$(DEPFILES):

include $(wildcard $(DEPFILES))
```

### Notes
- Add an `@` sign to suppress output of the command that is executed.
- If `target` isn't a file you want to build, please add `.PHONY`. `<target>` at the end of the build step. Common phony targets are: clean, install, run,...
```Makefile
install:
	npm install
.PHONY: install
```
Otherwise, if somebody creates an `install` directory, `make` will silently fail, because the build target already exists.

- If you run this command, it will output the makefile database: `make -p`
- [What does % symbol in Makefile mean? [stackexchange]](https://unix.stackexchange.com/questions/346322/what-does-symbol-in-makefile-mean)
 - OBJS = $(SRCS:.c=.o) 	# replaces .c with .o

### cheatsheet

[Make Cheat Sheet [pdf]](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/PDF/make_cheatsheet.pdf)
