make
#gcc -fsanitize=address -g3 src/main.c libftprintf.a
gcc src/main.c libftprintf.a
./a.out
