/*
 * Project First_Project2
 * Description:
 * Author:
 * Date:
 */
#include "Grove_ChainableLED.h"
ChainableLED leds(A4, A5, 1);

int toggleLed(String args) {
leds.setColorHSB(0, 0.0, 1.0, 0.5);

delay(500);

leds.setColorHSB(0, 0.0, 0.0, 0.0);

delay(500);

return 1;
}

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
leds.init();
leds.setColorHSB(0, 0.0, 0.0, 0.0);

Particle.function("toggleLed", toggleLed);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
}