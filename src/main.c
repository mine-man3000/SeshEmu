#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "instructions.h"
#include "cpu.h"

int main(void) {
	cpu_t cpu = {0};
	unsigned char instruction;
	unsigned char program[256] = {MUL, 2, 4, END};
	bool running = true;

	while (running) {
		instruction = program[cpu.PC];
		switch (instruction) {
		case INA: // Increment register A
			cpu.A++;
			cpu.PC++;
			break;
		case DEA: // Decrement register A
			cpu.A--;
			cpu.PC++;
			break;
		case JMP: // jmp
			cpu.PC = program[++cpu.PC];
			break;
		case END: // end
			cpu.PC++;
			running = false;
			break;
		case MUL: // multiply
			cpu.A = program[++cpu.PC];
			cpu.B = program[++cpu.PC];
			cpu.C = cpu.A * cpu.B;
			cpu.PC++;
			break;
		case DIV: // divide
			cpu.A = program[++cpu.PC];
			cpu.B = program[++cpu.PC];
			cpu.C = cpu.A / cpu.B;
			cpu.PC++;
			break;
		case MOV: // move

		default:
			printf("\e[1;33mWARN: Unimplemented instruction:\e[0m\e[1;36m %02X\e[0m\r\n", instruction);
			cpu.PC++;
			break;
		};
		for (uint_fast8_t i = 0; i != (sizeof(cpu_t) / 8) - 1; i++) {
			uint64_t *tmp = (uint64_t *)&cpu;
			printf("CPU Register %c: %08lX\r\n", 'A' + i, tmp[i]);
		}
		printf("CPU Program Counter: %08lX\r\n", cpu.PC);
	}
}