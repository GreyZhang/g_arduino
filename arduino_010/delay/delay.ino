void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    uint32_t i = 0U;
    // put your main code here, to run repeatedly:
    Serial.println("test for ms delay");
    delay(500);
    Serial.println("test for us delay");
    for (i = 0; i < 1000; i++)
    {
        delayMicroseconds(500);
    }
}
