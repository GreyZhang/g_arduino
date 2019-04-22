const int arduino_ad_pin0 = 0;
const int arduino_ad_pin1 = 1;
const int arduino_ad_pin2 = 2;
const int arduino_ad_pin3 = 3;
const int arduino_ad_pin4 = 4;
const int arduino_ad_pin5 = 5;

void setup()
{
    // put your setup code here, to run once:
    pinMode(arduino_ad_pin0 , INPUT);
    pinMode(arduino_ad_pin1 , INPUT);
    pinMode(arduino_ad_pin2 , INPUT);
    pinMode(arduino_ad_pin3 , INPUT);
    pinMode(arduino_ad_pin4 , INPUT);
    pinMode(arduino_ad_pin5 , INPUT);
    Serial.begin(9600);
}

void loop()
{
    int ad_ret_val;
    // put your main code here, to run repeatedly:

    /* ad0 */
    ad_ret_val = analogRead(arduino_ad_pin0);
    Serial.print("AD0: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    /* ad1 */
    ad_ret_val = analogRead(arduino_ad_pin1);
    Serial.print("AD1: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    /* ad2 */
    ad_ret_val = analogRead(arduino_ad_pin2);
    Serial.print("AD2: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    /* ad3 */
    ad_ret_val = analogRead(arduino_ad_pin3);
    Serial.print("AD3: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    /* ad4 */
    ad_ret_val = analogRead(arduino_ad_pin4);
    Serial.print("AD4: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    /* ad5 */
    ad_ret_val = analogRead(arduino_ad_pin5);
    Serial.print("AD5: ");
    Serial.print(ad_ret_val);
    Serial.print("\t");
    Serial.print(ad_ret_val * 5000.0f / 1024.0f);
    Serial.println("mv");
    delay(100);

    Serial.println("-------------------------------------------------------------");
    delay(1000);
}
