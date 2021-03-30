main: main.c rtc.o socket.o 
	gcc -o main main.c rtc.o socket.o

rtc.o: clock/rtc.c clock/rtc.h
	gcc -c clock/rtc.c

socket.o: server/socket.c server/socket.h
	gcc -c server/socket.c 
