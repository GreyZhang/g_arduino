#include "serial.h"

void setup()
{
    // put your setup code here, to run once:
    MySerialInit();
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println("arduino");
    delay(1000);
}
