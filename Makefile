CC		= gcc
CFLAGS		= -Wall -I/usr/include/mysql/
LDFLAGS		= -lmysqlclient
OBJFILES	= database/db_mysql.o main.o
TARGET		= bin/main

all : $(TARGET)

$(TARGET) : $(OBJFILES)
	@if [ ! -d "bin" ]; then  mkdir bin; fi
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean : 
	rm -f $(OBJFILES) $(TARGET) *~
