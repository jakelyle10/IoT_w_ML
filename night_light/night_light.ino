/*
 * Project Distance_Detect
 * Description:
 * Author:
 * Date:
 */

#include <Grove_ChainableLED.h>     // RGB LED library


double currentLightLevel;
ChainableLED leds(D2, D3, 1);       // LED object constructor

void setup()
{
  pinMode(A0, INPUT);
  leds.init();                    // initialise the LED
  Serial.begin(9600);             // Begin serial communications
}



void loop()
{
  double lightAnalogVal = analogRead(A0);
  currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);

  if (currentLightLevel > 7) {
 //   Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
    leds.setColorRGB(0, 0, 0, 0);                   
  }
  else if (currentLightLevel <= 7){
    leds.setColorRGB(0, 0, 255, 255);   
  }                      
	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
