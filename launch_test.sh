make
#gcc -fsanitize=address -g3 src/main.c libftprintf.a
gcc src/pf_main.c libftprintf.a
./a.out
