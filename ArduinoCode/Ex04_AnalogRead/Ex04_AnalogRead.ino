/*
  Analog In, LED and Serial Out

  Behavior: 
  Reads an analog input on indicated pin, prints the result to the serial 
  monitor.
  
  Circuit:
  * Pin 3: LED, anode to microcontroller, 330 Ohm resistor from 
    cathode to ground
  * Pin A0: Attach center lead of a potentiometer to pin A0. Attach the left lead 
    to 5V and right lead to GND. 
                             
   _________                         
  |	    |      potentiometer      
  | Arduino |     ----------|5V+  
  |    	  A0|-----| (+) |      
  |  	    |     ----------|l> GND                 
  |  	    |                        
  |  	    |
  |    	    |    LED     330 Ohm
  |  	PIN3|----(>|)----/\/\/\----|l> GND
  |  	    |
  |_________|
 
 Based on Example Code included w/ Arduino 1.0.5.
 Adaoted by Carlyn Maw 2013
 
 */
 
//////////////////////////////////////////////////////////////////////
///////////// USER DEFINED CONSTANTS & STARTING VALUES ///////////////

//where the led is
const int ledPin = 3;

//where the sensor is, and its typical range
const int sensorPin = A0;

//////////////////////////////////////////////////////////////////////
///////////////////////// INTERNAL VARIABLES /////////////////////////
int sensorValue = 0;
int ledBrightness = 0;

// the setup routine runs once when you press reset
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop() {
  // read the analog input and store the value in sensorValue
  sensorValue = analogRead(sensorPin);
  // print out the value you read
  Serial.println(sensorValue);
  
  //map the sensor value to LED brightness
  ledBrightness = map(sensorValue, 0, 1023, 0, 255);
  
  //turn on LED at correct brightness
  analogWrite(ledPin, ledBrightness);
  
}
