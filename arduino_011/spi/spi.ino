 #include <avr/sleep.h>
#include "timer.h"
#include "serial.h"
#include "task.h"
#include <SPI.h>

static uint8_t led_value = 0;
const int SPI_CS_PIN = 10;

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
    SPI.begin();
    SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
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
}

void spi_test_task_100ms(void)
{
    uint8_t spi_data_8bit = 0x77;
    uint16_t spi_data_16bit = 0x77AB;

    digitalWrite(SPI_CS_PIN, LOW);
    SPI.transfer(spi_data_8bit);
    SPI.endTransaction();
    digitalWrite(SPI_CS_PIN, LOW);
    SPI.transfer16(spi_data_16bit);
    SPI.endTransaction();
    digitalWrite(SPI_CS_PIN, HIGH);
}
