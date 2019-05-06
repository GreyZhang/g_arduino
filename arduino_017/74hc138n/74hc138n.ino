void setup()
{
    // put your setup code here, to run once:
    pinMode(8, OUTPUT); // A1
    pinMode(9, OUTPUT); // A2
    pinMode(10, OUTPUT); // A3
}

void loop()
{
    // put your main code here, to run repeatedly:
    // digitalWrite(8, LOW);
    // digitalWrite(9, LOW);
    // digitalWrite(10, LOW);
    // delay(1000);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    delay(1000);
}
