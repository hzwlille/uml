CC=arm-none-eabi-gcc
DEBUG=arm-none-eabi-gdb
TARGET_ARCH=-mcpu=cortex-m0plus -mthumb
CFLAGS=-c -g -O1 -std=gnu99
CIBLE=xxx.elf
OBJS=main.o init.o led.o
EXE=main init led

all: $(EXE) 

$(OBJS): main.c init.c led.c led.h

$(EXE): $(OBJS) clocks.o
	$(CC) -T ld_ram.lds -nostdlib  $^ crt0.s  -o $@ 

startgdbserver :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly
debug:
	$(DEBUG) $(EXE)
verify:
	arm-none-eabi-objdump 	-h $(EXE)

clean:
	rm  $(OBJS) $(EXE)