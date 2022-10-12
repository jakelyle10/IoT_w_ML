/*
 * Project rotary_sensor
 * Description:
 * Author:
 * Date:
 */


#include <Grove_ChainableLED.h>     // RGB LED library


ChainableLED leds(D2, D3, 1);       // LED object constructor

void setup()
{
  pinMode(A2, INPUT);
  leds.init();                    // initialise the LED
  Serial.begin(9600);             // Begin serial communications
}



void loop()
{
  double rotaryAnalogVal = analogRead(A2)/16;
  leds.setColorRGB(0,255,0,0);
  leds.setColorHSB(0,0,0,rotaryAnalogVal);
                     
	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
