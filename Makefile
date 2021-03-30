main: rtc.o rtc.o ./clock/rtc.c
	gcc -o main main.c rtc.o

rtc.o: ./clock/rtc.c ./clock/rtc.h
	gcc -c ./clock/rtc.c
