#include "SoftwareSerial.h"

// 创建一个串口对象，10号管脚用于接收，11号管脚用于发送。这个函数还有一个可选的参数，默认为false，用于指示是否逻辑反转
SoftwareSerial my_serial(10, 11);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    while(!Serial)
    {
        /* 等待连接 */
    }
    
    Serial.println(" Serial init for arduino");
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println(" Serial task for arduino");
    delay(1000);                       // wait for a second
}
