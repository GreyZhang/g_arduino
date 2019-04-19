#include <avr/sleep.h>
#include <SoftwareSerial.h>

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
    SerialCfg_Init();
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.print("uint8_t size: \t");Serial.println(sizeof(uint8_t));
    Serial.print("int8_t size: \t");Serial.println(sizeof(int8_t));
    Serial.print("uint16_t size: \t");Serial.println(sizeof(uint16_t));
    Serial.print("int16_t size: \t");Serial.println(sizeof(int16_t));
    Serial.print("uint32_t size: \t");Serial.println(sizeof(uint32_t));
    Serial.print("int32_t size: \t");Serial.println(sizeof(int32_t));
    Serial.print("uint64_t size: \t");Serial.println(sizeof(uint64_t));
    Serial.print("int64_t size: \t");Serial.println(sizeof(int64_t));
    Serial.print("float size: \t");Serial.println(sizeof(float));
    Serial.print("double size: \t");Serial.println(sizeof(double));
    Serial.println("-------------------------------------------");
    delay(1000);
}
