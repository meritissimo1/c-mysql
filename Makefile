CC			= gcc
CFLAGS		= -Wall -I/usr/include/mysql/
LDFLAGS		= -lmysqlclient

main : main.c
	@if [ ! -d "bin" ]; then  mkdir bin; fi
	$(CC) $(CFLAGS) -o bin/$@ $< $(LDFLAGS)
