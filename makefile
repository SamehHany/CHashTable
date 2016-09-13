all:
	gcc -g -Wall main.c prime.c hashtable.c hashfunction.c -lm -o hash
