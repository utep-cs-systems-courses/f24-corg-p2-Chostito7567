COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -I../lcdLib
LDFLAGS         = -L/opt/ti/msp430_gcc/include -L../lcdLib

# switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf
	(cd ../timerLib; make)

# Additional rules for files
main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o wdInterruptHandler.o \
          p2_interrupt_handler.o switches.o buzzer.o lcdgame.o font.o \
          ../timerLib/libTimer.a ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f -r *.o *.elf *shell* *shell*~ *~
	(cd ../timerLib; make clean)

# Object files
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
lcdgame.o: lcdgame.c lcdgame.h
font-5x7.o: font-5x7.c lcdutils.h
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
