COMMON_OBJECTS = switches.o buzzer.o lcdgame.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

# Compiler and Assembler
CC = msp430-elf-gcc
AS = msp430-elf-as

# Default target: build the main program
all: main.elf

# Link all object files into the final executable
main.elf: main.o ${COMMON_OBJECTS} ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Compile individual .c files into .o files
main.o: main.c lcdgame.h switches.h buzzer.h
lcdgame.o: lcdgame.c lcdgame.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h

# Load the program onto the MSP430 microcontroller
load: main.elf
	msp430loader.sh main.elf

# Clean up generated files
clean:
	rm -f *.o *.elf *~ *shell* *shell*~

# Rebuild dependencies in the timer library and LCD library
../timerLib/libTimer.a:
	(cd ../timerLib; make)

../lcdLib/lcdutils.o:
	(cd ../lcdLib; make)

../lcdLib/lcddraw.o:
	(cd ../lcdLib; make)
