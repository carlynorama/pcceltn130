/*
  Blink an External 12V LED Strip

  Behavior:
  Fades LED up and then down in brightness.

  Circuit:
  * Pin A0: Attach center lead of a potentiometer to pin A0. Attach the left lead 
    to 5V and right lead to GND. 
  * Pin A1: Attach center lead of a potentiometer to pin A1. Attach the left lead 
    to 5V and right lead to GND. 
  * Pin A2: Attach center lead of a potentiometer to pin A2. Attach the left lead 
    to 5V and right lead to GND. 
  * Pin 3: R MOSFET Gate
  * Pin 5: G MOSFET Gate
  * Pin 6: B MOSFET Gate

   _________
  |	    |      potentiometer      
  |         |     ----------|5V+  
  |    	  A2|-----| (+) |      
  |  	    |     ----------|l> GND 
  | Arduino |
  |	    |      potentiometer      
  |         |     ----------|5V+  
  |    	  A1|-----| (+) |      
  |  	    |     ----------|l> GND 
  |         |
  |	    |      potentiometer      
  |         |     ----------|5V+  
  |    	  A0|-----| (+) |      
  |  	    |     ----------|l> GND   
  |	    |
  |         |         ____D____(LOAD)---|12V+           
  |    	    |        /|
  |    PIN 6|-----G--||
  |         |        \|<--S-------------|l> GND
  |	    |   
  |         |         ____D____(LOAD)---|12V+           
  |    	    |        /|
  |    PIN 5|-----G--||
  |         |        \|<--S-------------|l> GND
  |	    |   
  |    	    |   
  |         |         ____D____(LOAD)---|12V+           
  |    	    |        /|
  |    PIN 3|-----G--||
  |         |        \|<--S-------------|l> GND
  |	    |   
  |_________|

  Based on Example Code included w/ Arduino 1.0.5.

 http://arduino.cc/en/Tutorial/Fading
 http://arduino.cc/en/Tutorial/PWM

 Adapted for an RGB LED STRIP by Carlyn Maw Apr 2014

 */
//where the led is
const int rLedPin = 3;
const int gLedPin = 5;
const int bLedPin = 6;

const int rSensor = A0;
const int gSensor = A1;
const int bSensor = A2;

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

// the loop() method runs over and over again,as long as the Arduino has power
void loop()
{
updateLED(rLedPin, rSensor);
updateLED(gLedPin, gSensor);
updateLED(bLedPin, bSensor);
delay(10);
}

void updateLED(int myLedPin, int mySensorPin) {
  //get the analog pin reading
  int sensorValue = analogRead(mySensorPin);
  //write to the led the sensor value with an inverted 
  //mapping because the LED is common anode
  analogWrite(myLedPin, map(sensorValue, 0, 1023, 0, 255));
}


void fadeDown(int myPin, int myDelay) {
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(myPin, 255 - fadeValue);
    // wait for myDelay milliseconds to see the dimming effect
    // the delay turns the behavior into human scale.
    delay(myDelay);
  }
}

void fadeUp(int myPin, int myDelay) {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(myPin, 255 - fadeValue);
    // wait for myDelay milliseconds to see the dimming effect
    // the delay turns the behavior into human scale.
    delay(myDelay);
  }
}
