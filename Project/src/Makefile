COMMON_OBJECTS  =       # This can hold shared object files if needed
CPU             = msp430g2553    # Specifies the microcontroller model
CFLAGS          = -mmcu=${CPU} -I../h   # Compiler flags to specify the microcontroller and header paths
LDFLAGS         = -L/opt/ti/msp430_gcc/include   # Linker flags for library paths

# Default target: build the project
all: main.elf
	(cd ../timerLib; make)  # Compile the timer library in its directory

# Link all the necessary object files and create the main executable
main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

# Upload the compiled program to the microcontroller
load: main.elf
	msp430loader.sh main.elf

# Clean up all generated files
clean:
	rm -f -r *.o *.elf *shell* *shell*~ *~
	(cd ../timerLib; make clean)  # Also clean the timer library directory
