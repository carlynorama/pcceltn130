/*
  Blink an External LED

  Behavior:
  Fades LED up and then down in brightness.

  Circuit:
  * Pin 3: R leg of RGB LED, cathode to microcontroller, 220 Ohm resistor from
  cathode to ground
  * Pin 5: G leg of RGB LED, cathode to microcontroller, 180 Ohm resistor from
  cathode to ground
  * Pin 6: B leg of RGB LED, cathode to microcontroller, 180 Ohm resistor from
  cathode to ground

   _________
  |	    |
  | Arduino |
  |    	    |    LED     330 Ohm
  |    PIN 6|----(|<)----/\/\/\----| 5V
  |         |
  |    	    |    LED     330 Ohm
  |    PIN 5|----(|<)----/\/\/\----| 5V
  |	    |
  |    	    |    LED     330 Ohm
  |    PIN 3|----(|<)----/\/\/\----| 5V
  |_________|

  Based on Example Code included w/ Arduino 1.0.5.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://arduino.cc/en/Tutorial/Fading
 http://arduino.cc/en/Tutorial/PWM

 Adapted for an RGB LED by Carlyn Maw Apr 2014

 */
//where the led is
int rLedPin = 3;
int gLedPin = 5;
int bLedPin = 6;

int delayVar = 20;


// the setup routine runs once when you press reset:
void setup()   {
  //Test LEDs
  fadeUp(rLedPin, delayVar);
  fadeDown(rLedPin, delayVar);
  fadeUp(gLedPin, delayVar);
  fadeDown(gLedPin, delayVar);
  fadeUp(bLedPin, delayVar);
  fadeDown(bLedPin, delayVar);
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{
//Good RGB LED fading patterns are actually quite advanced. We're going to
//save them for another day. 
}




void fadeDown(int myPin, int myDelay) {
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(myPin, 255 - fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    // the delay turns the behavior into human scale.
    delay(myDelay);
  }
}

void fadeUp(int myPin, int myDelay) {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(myPin, 255 - fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    // the delay turns the behavior into human scale.
    delay(myDelay);
  }
}
