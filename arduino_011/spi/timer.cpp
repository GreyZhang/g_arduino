#include "timer.h"
#include "task.h"

uint32_t timer_isr_counter = 0;
/*
    Set timer1 to get a periodic ISR for 1ms.
*/
void TaskTimer_Init(void)
{
//     configurations for timer1
     TCCR1A = 0; // Normal port operation, OC1A/OC1B disconnected.
     TCCR1B = 0; // Normal port operation, OC1A/OC1B disconnected.
     TCNT1 = 0;  // set counter to 0.
     OCR1A = 15999;
     TCCR1B |= (1 << WGM12);  // use wave genreation
     TCCR1B |= (1 << CS10);   // use system clock
     TIMSK1 |= (1 << OCIE1A); // Timer/Counter 1, Output Compare A Match Interrupt Enable
}

ISR(TIMER1_COMPA_vect)
{
    timer_isr_counter++;
        
    if(timer_isr_counter % 20 == 0)
    {
        task_20ms();
    }

    if(timer_isr_counter % 50 == 0)
    {
        task_50ms();
    }

    if(timer_isr_counter % 100 == 0)
    {
        task_100ms();
    }

    if(timer_isr_counter % 1000 == 0)
    {
        task_1000ms();
        timer_isr_counter = 0;
    }
}
