#ifndef KERNEL_H
#define KERNEL_H

#include <cstdint>

void load_in_memory(int32_t);
void execute();
void syscall();
void computer_dump();

#endif
