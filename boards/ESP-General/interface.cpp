#include "core/powerSave.h"
#include "core/utils.h"
#include <interface.h>

/***************************************************************************************
** GPIO setup
***************************************************************************************/
void _setup_gpio() {

    pinMode(TFT_CS, OUTPUT);
    digitalWrite(TFT_CS, HIGH);

    pinMode(TFT_MOSI, OUTPUT);
    digitalWrite(TFT_MOSI, HIGH);

    pinMode(TFT_SCLK, OUTPUT);

    pinMode(TFT_DC, OUTPUT);
    digitalWrite(TFT_DC, HIGH);

    pinMode(TFT_RST, OUTPUT);

    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

#ifdef ILI9341_DRIVER
    bruceConfig.colorInverted = 0;
#endif
}

/***************************************************************************************
** Battery / charging
***************************************************************************************/
int getBattery() { return 0; }
bool isCharging() { return false; }

/***************************************************************************************
** Brightness
***************************************************************************************/
void _setBrightness(uint8_t brightval) {
    if (brightval == 0) {
        analogWrite(TFT_BL, 0);
    } else {
        int bl = MINBRIGHT + round(((255 - MINBRIGHT) * brightval / 100));
        analogWrite(TFT_BL, bl);
    }
}

/***************************************************************************************
** Input (no buttons, no touch for now)
***************************************************************************************/
void InputHandler(void) {}

/***************************************************************************************/
void powerOff() {}
void checkReboot() {}
