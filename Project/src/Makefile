COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf
	(cd ../timerLib; make)

main.elf: ${COMMON_OBJECTS} main.c switches.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f -r *.o *.elf *shell* *shell*~ *~
	(cd ../timerLib; make clean)

switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
wdInterruptHandler.o: wdInterruptHandler.c
p2_interrupt_handler.o: p2_interrupt_handler.c
