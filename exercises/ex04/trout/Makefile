main.o: trout.h util.h main.c
	gcc -c main.c

trout.o: trout.h util.h trout.c
	gcc -c trout.c

util.o: trout.h util.h util.c
	gcc -c util.c

test_util.o: test_util.c util.h minunit.h
	gcc -c test_util.c

trout: main.o trout.o util.o
	gcc -g -o trout trout.o util.o main.o -Wall

test_util: util.o test_util.o
	gcc -g -o test_util util.o test_util.o

# trout: trout.h trout.c util.c main.c
# 	gcc -g -o trout trout.c util.c main.c
