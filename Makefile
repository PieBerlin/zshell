CC=gcc
CFLAGS=-Wall -Wextra  
LDFLAGS=
all:clean my_shell

my_shell : main.o helpers.o input_parser.o builtins.o  
	$(CC) $(CFLAGS) $^ -o $@
main.o : main.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
helpers.o : helpers.c  
	$(CC) $(CFLAGS) -c $< -o $@ 
input_parser.o : input_parser.c  
	$(CC) $(CFLAGS) -c  $< -o $@ 
builtins.o : builtins.c  
	$(CC) $(CFLAGS) -c  $< -o $@ 

clean:
	rm -f *.o my_shell

.PHONY: all clean 
