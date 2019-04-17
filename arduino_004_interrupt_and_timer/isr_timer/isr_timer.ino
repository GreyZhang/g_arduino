#include "SoftwareSerial.h"

void task_100ms(void);
void led_toogle(void);

unsigned long counter_ms;
unsigned long counter_us;

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    while (!Serial)
    {
        /* 等待连接 */
    }
    Serial.println("start running...");
}

void task_1000ms(void)
{
    led_toogle();
}

void led_toogle(void)
{
    static unsigned long n = 0U;

    if(n % 2 == 0)
    {
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }
    n++;
}

void loop()
{
    // put your main code here, to run repeatedly:
    counter_ms = millis();
    counter_us = micros();
    #ifdef TEST_TIMER
    Serial.print("counter_ms: ");
    Serial.print(counter_ms);
    Serial.print("\t");
    Serial.print("counter_us: ");
    Serial.println(counter_us);
    Serial.println("-----------------------------------------------------------");
    delay(1000);
    #endif
    if(counter_ms % 1000 == 0)
    {
        task_1000ms();
    }
}
