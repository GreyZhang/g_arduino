#include "SoftwareSerial.h"

// 创建一个串口对象，10号管脚用于接收，11号管脚用于发送。这个函数还有一个可选的参数，默认为false，用于指示是否逻辑反转
SoftwareSerial my_serial(10, 11);
unsigned int counter;
int read_first_byte;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    while (!Serial)
    {
        /* 等待连接 */
    }

    Serial.println(" Serial init for arduino");
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.begin(9600);
    Serial.println("------------------------Serial test task for arduino------------------------");
    Serial.print(counter);
    Serial.print("\t");
    Serial.print(counter, BIN);
    Serial.print("\t");
    Serial.print(counter, HEX);
    Serial.print("\n");
    Serial.println("test for format print function:");
    Serial.print(3.14159265358);
    Serial.print("\t");
    Serial.print(3.14159265358, 2);
    Serial.print("\t");
    Serial.print(3.14159265358, 5);
    Serial.print("\t\n");
    // test for read function
    if(Serial.available() > 0)
    {
        // read first byte
        read_first_byte = Serial.read();
        Serial.print("data come from serial interface!\t");
        Serial.print(read_first_byte);
    }
    // test for write function
    Serial.write("test for write function");
    Serial.end();
    Serial.print(3.14159265358, 8);
    Serial.println("should not display on screen!");
    delay(1000); // wait for a second
    counter++;
}
