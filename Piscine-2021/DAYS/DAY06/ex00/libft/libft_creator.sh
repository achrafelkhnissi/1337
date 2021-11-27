mkdir obj
cd obj
gcc -Wall -Wextra -Werror -c ~/Computer\ Science/1337/libft/src/int/*.c ~/Computer\ Science/1337/libft/src/str/*.c ~/Computer\ Science/1337/libft/src/put/*.c
ar rcs ../libft.a *.o
cd ..
rm -r obj
