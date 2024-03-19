<h1 align="center">This is CS50 - 2024<h1>
<h2 align="center">CS50's Introduction to Computer Science.

### CS50 Library for C

> #### Have this installed in your system to compile this C files
>
1. libcs50
2. clang*
>
> Instead of using a makefile, you can add the following alias to your ***~/.bashrc:***

````bash
  alias make50='make CC=clang CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow" LDLIBS="-lcrypt -lcs50 -lm"'
````
