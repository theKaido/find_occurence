CC=gcc
SRC=main.c initialization.c
OBJ=$(SRC:.c=.o)

algo:		$(OBJ)
	$(CC) $(OBJ) -o $@

%.o:	%.c
	$(CC) -c -Wall $< 
clean:
	rm *.o algo

