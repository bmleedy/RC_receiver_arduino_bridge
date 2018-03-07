     
/*
 RC PulseIn Joystick
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */

int ch1; // Here's where we'll keep our channel values
int ch2;
int ch3;
int ch4;

void setup() {

pinMode( 9, INPUT); // Set our input pins as such
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);

Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {
  
  ch1 = pulseIn( 9, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(10, HIGH, 25000); // Throttle
  ch3 = pulseIn(11, HIGH, 25000);
  ch4 = pulseIn(12, HIGH, 25000);
  
//Serial.print("Ch1:"); // Ch3 was x-axis 
Serial.print(map(ch1, 1000,2000,-500,500)); // left is negative, center at 0
Serial.print(",");
//Serial.print("Ch2:"); // Ch2 was y-axis
Serial.println(map(ch2, 1000,2000,500,-500)); // center at 0
/*
Serial.print("Ch3:"); // Ch3 was x-axis 
Serial.println(map(ch3, 1000,2000,-500,500)); // center at 0

Serial.print("Ch4:"); // Ch2 was y-axis
Serial.println(map(ch4, 1000,2000,-500,500)); // center at 0

Serial.println(); //make some room
*/
delay(100);// I put this here just to make the terminal 
           // window happier
}
