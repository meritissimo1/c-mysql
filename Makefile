CC			= gcc
CFLAGS		= -Wall -I/usr/include/mysql/
LDFLAGS		= -lmysqlclient

main : main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/$@ $<
