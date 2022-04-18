/*
 Example sketch for the PS3 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */

#include <PS3BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x0C, 0xBF, 0xEB); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch


void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}

void loop() {
  Usb.Task();
    if ( conn == true){
        if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 || PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
        Serial.print(F("\r\nLeftHatX: "));
        Serial.print(PS3.getAnalogHat(LeftHatX));
        Serial.print(F("\tLeftHatY: "));
        Serial.print(PS3.getAnalogHat(LeftHatY));
        Serial.print(F("\tRightHatX: "));
        Serial.print(PS3.getAnalogHat(RightHatX));
        Serial.print(F("\tRightHatY: "));
        Serial.print(PS3.getAnalogHat(RightHatY));
      }
    
    if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2)) {
      Serial.print(F("\r\nL2: "));
      Serial.print(PS3.getAnalogButton(L2));
      Serial.print(F("\tR2: "));
      Serial.print(PS3.getAnalogButton(R2));
    }

    if (PS3.getButtonClick(TRIANGLE))
      Serial.print(F("\r\nTriangle"));
    if (PS3.getButtonClick(CIRCLE)) 
      Serial.print(F("\r\nCircle"));
    if (PS3.getButtonClick(CROSS))
      Serial.print(F("\r\nCross"));
    if (PS3.getButtonClick(SQUARE))
      Serial.print(F("\r\nSquare"));
    if (PS3.getButtonClick(UP))
      Serial.print(F("\r\nUp"));
    if (PS3.getButtonClick(RIGHT)) 
      Serial.print(F("\r\nRight"));
    if (PS3.getButtonClick(DOWN)) 
      Serial.print(F("\r\nDown"));
    if (PS3.getButtonClick(LEFT)) 
      Serial.print(F("\r\nLeft"));
    if (PS3.getButtonClick(L1))
      Serial.print(F("\r\nL1"));
    if (PS3.getButtonClick(L3))
      Serial.print(F("\r\nL3"));
    if (PS3.getButtonClick(R1))
      Serial.print(F("\r\nR1"));
    if (PS3.getButtonClick(R3))
      Serial.print(F("\r\nR3"));
    if (PS3.getButtonClick(SELECT))
      Serial.print(F("\r\nSelect - "));
    if (PS3.getButtonClick(START))
      Serial.print(F("\r\nStart"));
  }
}
