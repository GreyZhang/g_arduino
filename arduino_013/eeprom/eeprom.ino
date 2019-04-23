#include <EEPROM.h>

static unsigned char read_finished_flg = 0;
unsigned char data_eeprom;

void setup()
{
// put your setup code here, to run once:
    int i  = 0;

    Serial.begin(9600);
    Serial.println("test start...");

    for(i = 0; i < 256; i++)
    {
        EEPROM.write(i,i);
    }

    Serial.println("eeprom write finished.");

    read_finished_flg = EEPROM.read(256);
    Serial.println(read_finished_flg);


    if(read_finished_flg % 2 == 1)
    {
        for(i = 0; i < 256; i++)
        {
            data_eeprom = EEPROM.read(i);
            Serial.println(data_eeprom);
            delay(10);
        }
    }
    if(read_finished_flg < 255)
    {
        read_finished_flg += 1;
    }
    else
    {
        read_finished_flg = 0;
    }
    EEPROM.write(256,read_finished_flg);
}

void loop()
{
// put your main code here, to run repeatedly:
}
