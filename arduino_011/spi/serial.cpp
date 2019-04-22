#include "serial.h"

void SerialCfg_Init(void)
{
   Serial.begin(9600);
   while (!Serial)
    {
        /* wait for conection */
    }
}
