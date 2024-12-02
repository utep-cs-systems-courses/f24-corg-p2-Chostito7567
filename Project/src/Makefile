COMMON_OBJECTS = lcdgame.o switches.o buzzer.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -I../lcdLib
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

main.elf: main.o ${COMMON_OBJECTS} ../lcdLib/lcddraw.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

main.o: main.c lcdgame.h switches.h buzzer.h
lcdgame.o: lcdgame.c lcdgame.h ../lcdLib/lcddraw.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf *~
