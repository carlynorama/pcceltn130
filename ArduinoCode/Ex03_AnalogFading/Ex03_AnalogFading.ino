/*
  Blink an External LED

  Behavior:
  Fades LED up and then down in brightness.

  Circuit:
  * Pin 3: LED, anode to microcontroller, 330 Ohm resistor from
  cathode to ground

   _________
  |	    |
  | Arduino |
  |    	    |    LED     330 Ohm
  |  	PIN3|----(>|)----/\/\/\----|l> GND
  |_________|

  Based on Example Code included w/ Arduino 1.0.5.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://arduino.cc/en/Tutorial/Fading
 http://arduino.cc/en/Tutorial/PWM

 Adapted by Carlyn Maw 2014 (diagram and comments only)

 */
//where the led is
int ledPin = 3;

// the setup routine runs once when you press reset:
void setup()   {
  // No need to initialize as output.
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{
  // fade in from min duty cycle to max duty cycle in increments of 5 points:
  //
  //          __       _____     _______   _________ ____________
  //          ||       |   |     |     |   |       | |         |
  //          ||       |   |     |     |   |       | |         |
  //----------||-------|   |-----|     |---|       |-|         |
  //
  //METRONOME:
  //-----+-----|-----+-----|-----+-----|-----+-----|-----+-----|

  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    // the delay turns the behavior into human scale. 
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    // the delay turns the behavior into human scale.
    delay(30);
  }
}
