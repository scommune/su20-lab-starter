#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    int counter = 15;
    uint16_t input=reg[0]^reg[2]^reg[3]^reg[5];
    while(counter>=0){
        uint16_t tmp=reg[counter];
        reg[counter]= input;
        input=tmp;
        counter--;
    }
}

