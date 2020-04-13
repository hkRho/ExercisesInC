# ex_compile.o: ex_compile.c
# 	gcc -c ex_compile.c -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
#
# ex_compile: ex_compile.o
# 	gcc -g -o ex_compile ex_compile.o


### This is better!
### Easier to replace files and include other libraries
ex_compile: ex_compile.c
	gcc ex_compile.c `pkg-config --cflags --libs glib-2.0` -o ex_compile

word_count: word_count.c
    gcc word_count.c `pkg-config --cflags --libs glib-2.0` -o word_count
