#include <avr/sleep.h>
#include <SoftwareSerial.h>

void TaskTimer_Init(void);
void SerialCfg_Init(void);

unsigned long counter_ms;
unsigned long counter_us;

/*
    Set timer1 to get a periodic ISR for 1ms.
*/
void TaskTimer_Init(void)
{
    // configurations for timer1
    TCCR1A = 0; // Normal port operation, OC1A/OC1B disconnected.
    TCCR1B = 0; // Normal port operation, OC1A/OC1B disconnected.
    TCNT1 = 0;  // set counter to 0.
    OCR1A = 15999;
    TCCR1B |= (1 << WGM12);  // use wave genreation
    TCCR1B |= (1 << CS10);   // use system clock
    TIMSK1 |= (1 << OCIE1A); // Timer/Counter 1, Output Compare A Match Interrupt Enable
}

void SerialCfg_Init(void)
{
    Serial.begin(9600);
    while (!Serial)
    {
        /* 等待连接 */
    }
}
void setup()
{
    // put your setup code here, to run once:
    // disable interrupt
    cli();
    // LED configuration
    pinMode(LED_BUILTIN, OUTPUT);
    TaskTimer_Init();
    SerialCfg_Init();
    // enable interrupt
    sei();
}

ISR(TIMER1_COMPA_vect)
{
    static unsigned long i = 0;
    static unsigned long j = 0;

    if (i % 1000 == 0)
    {
        counter_ms = millis();
        counter_us = micros();
        if (j % 2 == 0)
        {
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW);
        }
        j++;

        Serial.print("counter_ms: ");
        Serial.print(counter_ms);
        Serial.print("\t");
        Serial.print("counter_us: ");
        Serial.println(counter_us);
    }
    i++;
}

void loop()
{
    // put your main code here, to run repeatedly:
}
