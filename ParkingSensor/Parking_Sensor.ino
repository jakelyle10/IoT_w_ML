/*
 * Project Distance_Detect
 * Description:
 * Author:
 * Date:
 */

#include <Grove-Ultrasonic-Ranger.h> // Ultrasonic Ranger library
#include <Grove_ChainableLED.h>     // RGB LED library
#include <twilio.h>					// IDK


float distance1 = 15.0;             // car distance boundary
int ticker = 0;                 // ticker counter to see how long the car is parked
// String body = "Hey, your car is parked!";

// Twilio text();
Ultrasonic ultrasonic(D4);          // Ultrasonic object constructor
ChainableLED leds(D2, D3, 1);       // LED object constructor

void setup()
{
	Serial.begin(9600);             // Begin serial communications
    leds.init();                    // initialise the LED
}

long RangeInCentimetersPrevious = 15.0;

void loop()
{
	long RangeInCentimeters;        // Variable to hold the distance measurement


	RangeInCentimeters = ultrasonic.MeasureInCentimeters();     // Get the current distance value
	Serial.print(RangeInCentimeters);                           // Out put the value over serial
	Serial.println(" cm"); // use 'particle serial monitor --follow' in the CLI to see serial output


	if (RangeInCentimeters > distance1){                        // If range is greater than far boundary...
	    leds.setColorRGB(0, 0, 255, 0);                         // green
	}
	else if (RangeInCentimeters < distance1) {                  // too close...
	    leds.setColorRGB(0, 255, 0, 0);                         // red
	}
	
  	if (RangeInCentimeters <= RangeInCentimetersPrevious + 3 && RangeInCentimeters >= RangeInCentimetersPrevious - 3){
    	ticker = ticker +1;
  	}
	else{
		ticker = 0;
	}

  	if(ticker == 300){
		Particle.publish("parking", "parked", PRIVATE);
		// Particle.publish("twilio_sms", body, PRIVATE);
		// text.message('+16513438004', '+13854858611', body)
		ticker = 0;
  	}

  	RangeInCentimetersPrevious = RangeInCentimeters;

	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
