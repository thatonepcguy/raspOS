/*
    * raspix is a custom OS designed to function on the Raspberry Pi 5.
    * Copyright (C) 2025  Caleb A. Jacka
    *  
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    * 
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    * 
    * You should have received a copy of the GNU General Public License
    * along with this program.  If not, see <https://www.gnu.org/licenses/>.
    * 
    * If contact with the original author is needed, he is available via email at 
    * calebjacka@gmail.com
*/

#include "exceptions/traphandler.h"
#include "utils/common.h"
#include "utils/kprintf.h"

void handleTrap(trap_t *trapRegs, uint64_t esr_el1) {
    switch (esr_el1 & ESR_EL1_EC) {
    case SVC_TRAP:
            __asm__ __volatile__("eret" ::: "memory");
        break;
    
    default:
        kprintf("Trap Cause: %x\r\n", esr_el1);
        while (1);
        break;
    };
}