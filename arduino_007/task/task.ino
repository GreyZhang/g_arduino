#include <avr/sleep.h>
#include "timer.h"
#include "serial.h"

static uint8_t led_value = 0;

void setup()
{
    // put your setup code here, to run once:
    // disable interrupt
    cli();
    SerialCfg_Init();
    // LED configuration
    pinMode(LED_BUILTIN, OUTPUT);
    TaskTimer_Init();
    // enable interrupt
    sei();
}

void loop()
{
}

void LedToggle(void)
{
    if(led_value == 0)
    {
        digitalWrite(LED_BUILTIN, LOW);
        led_value = 1;
    }
    else
    {
        digitalWrite(LED_BUILTIN, HIGH);
        led_value = 0;
    }
    Serial.println(timer_isr_counter);
}
