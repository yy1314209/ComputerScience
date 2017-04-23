ASM_FLAGS= -m32 --pipe -Wall -fasm -g -O1 -fno-stack-protector

BOOTSECT=start16
BOOTSECT_OBJS=output/${BOOTSECT}.o
BOOTSECT_BIN=output/${BOOTSECT}.bin

OS_OBJS=output/start32.o output/main.o

myOS: ${BOOTSECT_BIN} ${OS_OBJS}
	ld -T myOS.ld ${OS_OBJS} -o output/myOS.elf
	objcopy -O binary output/myOS.elf output/myOS.bin

output/main.o: main.c
	gcc -c ${ASM_FLAGS} main.c -o output/main.o

output/start32.o: start32.S
	gcc -c ${ASM_FLAGS} start32.S -o output/start32.o

output/${BOOTSECT}.o: ${BOOTSECT}.S
	gcc -c ${ASM_FLAGS} ${BOOTSECT}.S -o output/${BOOTSECT}.o	

output/${BOOTSECT}.bin: ${BOOTSECT_OBJS}
	ld -T ${BOOTSECT}.ld ${BOOTSECT_OBJS} -o output/${BOOTSECT}.elf
	objcopy -O binary output/${BOOTSECT}.elf output/${BOOTSECT}.bin
	
clean:
	rm -f output/*.o output/*.elf output/*.bin
