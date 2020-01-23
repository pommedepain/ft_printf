# FT_PRINTF

4th C project for 42 Paris school.

This project consists in recoding the printf function of the libc.

(Group project carried out with @cajulien42)

## Recoding Printf

Printf is a function that writes output to stdout according to a format [(see man)](https://linux.die.net/man/3/printf).

The aim of this project is to partially reproduce this function.

#### ft_printf can handle 
<ul>
<li>c s p conversions</li>
<li>d i o u x X conversions with flags hh, h, l and ll</li>
<li>f conversion with the flags l and L</li>
<li>%%</li>
<li>flags #0-+ and space</li>
<li>precision and minimum field width</li>
</ul>

<b>NB:</b> The function uses a great deal of the libft I made earlier in my cursus.

## How to use it ?

<ul>
<li>Run: make</li>
<li>Make a main calling the ft_printf function of libft </li>
<li>Run: gcc ./main.c ./libftprintf.a (there will be warning that's normal! We're testing some undefined behaviors of the printf function)</li>
<li>Run ./a.out</li>
</ul>

![Grade](./grade.png?raw=true "grade")
