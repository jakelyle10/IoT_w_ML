/*
 * Project Distance_Detect
 * Description:
 * Author:
 * Date:
 */

#include <Grove-Ultrasonic-Ranger.h> // Ultrasonic Ranger library
#include <twilio.h>					// Twilio

// Initialize some stuff
float rangeInCentimeters;			// current light level for loop
float currentLightLevel;
String movementError = "There is movement detected!";
String lightError = "There is a change in light level detected!";
Ultrasonic ultrasonic(D4);          // Ultrasonic object constructor

void setup()
{
	pinMode(A0, INPUT);
	pinMode(D2, OUTPUT);
  	Serial.begin(9600);             // Begin serial communications
}

void loop()
{
	double lightAnalogVal = analogRead(A0);
  	currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);

	// check to see if the light level is above 10
  	if (currentLightLevel > 10) {
    	Particle.publish("twilio_sms", lightError, PRIVATE);
		digitalWrite(D2, HIGH);
		delay(500);
		digitalWrite(D2, LOW);
		delay(10000);
  	}             

	rangeInCentimeters = ultrasonic.MeasureInCentimeters();

	// Check to see if something is within 15 cm
	if (rangeInCentimeters < 15){                       
		Particle.publish("twilio_sms", movementError, PRIVATE);
		digitalWrite(D2, HIGH);
		delay(500);
		digitalWrite(D2, LOW);
		delay(10000);                   
	}

	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
