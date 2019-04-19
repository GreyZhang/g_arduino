#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

extern uint32_t timer_isr_counter;

void TaskTimer_Init(void);

#endif
