/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface. The device's I2C address is either 0x76 or 0x77.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
  See the LICENSE file for details.
***************************************************************************/
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
// Adafruit_BME280 bme(BME_CS); // hardware SPI
// Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// for SD card
const int chipSelect = 4;
unsigned long delayTime;

void setup()
{
    /* Serial.begin(9600); */
    /* Serial.println("Initializing SD card..."); */
    /* see if the card is present and can be initialized: */
    if (!SD.begin(chipSelect))
    {
        /* Serial.println("Card failed, or not present"); */
        /* // don't do anything more: */
        /* while (1) */
        /*     ; */
    }
    /* Serial.println("card initialized."); */
    /* Serial.println(F("BME280 test")); */

    if (!bme.begin(0x76, &Wire))
    {
        /* Serial.println("Could not find a valid BME280 sensor, check wiring!"); */
        /* while (1) */
        /*     ; */
    }

    /* Serial.println("-- Default Test --"); */
    /* Serial.println("normal mode, 16x oversampling for all, filter off,"); */
    /* Serial.println("0.5ms standby period"); */
    delayTime = 5000;

    /* Serial.println(); */
}

void loop()
{
    // Only needed in forced mode! In normal mode, you can remove the next line.
    bme.takeForcedMeasurement(); // has no effect in normal mode

    printValues();
    delay(delayTime);
}

void printValues()
{
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    // if the file is available, write to it:
    if (dataFile)
    {
        /* dataFile.println(dataString); */
        dataFile.print("Temperature = ");
        dataFile.print(bme.readTemperature());
        dataFile.println(" *C");
        dataFile.print("Pressure = ");
        dataFile.print(bme.readPressure() / 100.0F);
        dataFile.println(" hPa");
        dataFile.print("Approx. Altitude = ");
        dataFile.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
        dataFile.println(" m");
        dataFile.print("Humidity = ");
        dataFile.print(bme.readHumidity());
        dataFile.println(" %");
        dataFile.println();
        dataFile.close();
        // print to the serial port too:
        /* Serial.println(dataString); */
    }
    // if the file isn't open, pop up an error:
    else
    {
        /* Serial.println("error opening datalog.txt"); */
    }
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

