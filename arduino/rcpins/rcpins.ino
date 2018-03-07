/*
 * Read the pulses from a 4-Axis RC receiver and output them via serial.
 */

//Define the list of pins to look for pulses.
//  This is also the order of the output
const unsigned char pins[] = {2, 3, 4, 5};


#define SERIAL_BAUD_RATE 9600

//Map function reference: 
// https://www.arduino.cc/reference/en/language/functions/math/map/
#define MIN_PULSE_W 1000
#define MAX_PULSE_W 2000
#define MIN_OUTPUT_RNG  -100
#define MAX_OUTPUT_RNG  100


void setup() {

  // Set all listed pins to inputs
  for(int i=0; i < sizeof(pins); i++){
    pinMode(pins[i], INPUT);
  }

  // Setup the serial port which we'll use for output
  Serial.begin(SERIAL_BAUD_RATE);
}


void loop() {
  // Every cycle, print a comma-delimited line with the following fields:
  // TIME_MILLIS,PIN_1_%,PIN_2_%,...,PIN_n_% \n

  // print timestamp_millis
  Serial.print(millis());

  // Print the comma-delimited channel %'s
  for(int i=0; i < sizeof(pins); i++){
    Serial.print(",");
    int pulse_width = pulseIn(pins[i], HIGH, 25000);
    int output_value = map(pulse_width, 
                            MIN_PULSE_W, 
                            MAX_PULSE_W, 
                            MIN_OUTPUT_RNG, 
                            MAX_OUTPUT_RNG);
    Serial.print(output_value);
  }

  // End the line with a '\n'
  Serial.println("");

  // Note: there's no delay in this loop.  We will read pulses as quickly as possible.
  //   In practice, this is about 60 ms cycle rate (17Hz)
  
}
