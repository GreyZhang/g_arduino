#include <Wire.h>

void setup()
{
    Wire.begin(8); // join i2c bus (address optional for master)
    // Serial.begin(9600);
    // Serial.println("start test");
}

byte x = 0;

void loop()
{
    // Serial.println(x);
    Wire.beginTransmission(3); // transmit to device #8
    Wire.write("x is ");       // sends five bytes
    Wire.write(x);             // sends one byte
    Wire.endTransmission();    // stop transmitting

    x++;
    delay(100);
}
