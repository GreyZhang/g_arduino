//——————————————————————————————————————————————————————————————————————————————
//  ACAN2515 Demo in loopback mode
//——————————————————————————————————————————————————————————————————————————————

#include <ACAN2515.h>

//——————————————————————————————————————————————————————————————————————————————
//  MCP2515 connections:
//    - standard SPI pins for SCK, MOSI and MISO
//    - a digital output for CS
//    - interrupt input pin for INT
//——————————————————————————————————————————————————————————————————————————————
// If you use CAN-BUS shield (http://wiki.seeedstudio.com/CAN-BUS_Shield_V2.0/) with Arduino Uno,
// use B connections for MISO, MOSI, SCK, #9 or #10 for CS (as you want),
// #2 or #3 for INT (as you want).
//——————————————————————————————————————————————————————————————————————————————

static const byte MCP2515_CS = 10; // CS input of MCP2515 (adapt to your design)
static const byte MCP2515_INT = 3; // INT output of MCP2515 (adapt to your design)

//——————————————————————————————————————————————————————————————————————————————
//  MCP2515 Driver object
//——————————————————————————————————————————————————————————————————————————————

ACAN2515 can(MCP2515_CS, SPI, MCP2515_INT);

//——————————————————————————————————————————————————————————————————————————————
//  MCP2515 Quartz: adapt to your design
//——————————————————————————————————————————————————————————————————————————————

static const uint32_t QUARTZ_FREQUENCY = 8UL * 1000UL * 1000UL; // 8 MHz

//——————————————————————————————————————————————————————————————————————————————
//   SETUP
//——————————————————————————————————————————————————————————————————————————————

void setup()
{
    //--- Start serial
    Serial.begin(38400);
    //--- Wait for serial (blink led at 10 Hz during waiting)
    while (!Serial)
    {
        delay(50);
    }
    //--- Begin SPI
    SPI.begin();
    //--- Configure ACAN2515
    Serial.println("Configure ACAN2515");
    ACAN2515Settings settings(QUARTZ_FREQUENCY, 500UL * 1000UL); // CAN bit rate 500 kb/s
    settings.mRequestedMode = ACAN2515Settings::NormalMode;      // Select Normal mode
    const uint16_t errorCode = can.begin(settings, [] { can.isr(); });
    if (errorCode == 0)
    {
        Serial.print("Bit Rate prescaler: ");
        Serial.println(settings.mBitRatePrescaler);
        Serial.print("Propagation Segment: ");
        Serial.println(settings.mPropagationSegment);
        Serial.print("Phase segment 1: ");
        Serial.println(settings.mPhaseSegment1);
        Serial.print("Phase segment 2: ");
        Serial.println(settings.mPhaseSegment2);
        Serial.print("SJW: ");
        Serial.println(settings.mSJW);
        Serial.print("Triple Sampling: ");
        Serial.println(settings.mTripleSampling ? "yes" : "no");
        Serial.print("Actual bit rate: ");
        Serial.print(settings.actualBitRate());
        Serial.println(" bit/s");
        Serial.print("Exact bit rate ? ");
        Serial.println(settings.exactBitRate() ? "yes" : "no");
        Serial.print("Sample point: ");
        Serial.print(settings.samplePointFromBitStart());
        Serial.println("%");
    }
    else
    {
        Serial.print("Configuration error 0x");
        Serial.println(errorCode, HEX);
    }
}

//------------------------------------------------------------------------------
#define DEBUG_MODE 1

CANMessage frame_tx;
CANMessage frame_rx;
char putc_char;
int counter = 0;
//——————————————————————————————————————————————————————————————————————————————

void loop()
{
#if DEBUG_MODE
    frame_tx.len = 8;
    frame_tx.ext = false;
    frame_tx.rtr = false;
    frame_tx.idx = 0x0;
    frame_tx.data[0] += 1U;
    if (can.tryToSend(frame_tx))
    {
        Serial.println(counter++);
    }
    delay(100);
    if (can.available())
    {
        can.receive(frame_rx);
        {
            frame_tx.id = frame_rx.id;
        }
    }
#endif
}
