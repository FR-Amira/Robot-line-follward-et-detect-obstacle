
// Define IR sensor pins
const int sensor1Pin = 2;
const int sensor2Pin = 3;
const int sensor3Pin = 4;
const int sensor4Pin = 5;
const int nearPin = 7;    // Optional, if NEAR pin is used

void setup() {


  // Set IR sensor pins as inputs
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);
  pinMode(nearPin, INPUT);  // Optnal, if NEAR pin is used

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Read the IR sensors
  int sensor1 = digitalRead(sensor1Pin);
  int sensor2 = digitalRead(sensor2Pin);
    int sensor3 = digitalRead(sensor3Pin);
  int sensor4 = digitalRead(sensor4Pin);
  int near = digitalRead(nearPin); // Optional

  // Print sensor values for debugging
//  Serial.print("S1: "); Serial.print(sensor1);
  //Serial.print(" S2: "); Serial.print(sensor2);
 //Serial.print(" S3: "); Serial.print(sensor3);
  //Serial.print(" S4: "); Serial.print(sensor4);
  Serial.print(" NEAR: "); Serial.println(near);

  // Simple obstacle avoidance logic
  if (near == HIGH) {
    // Obstacle detected, stop motors
   Serial.println("detect");   // detect 10cm 
  } else {
    // No obstacle, move forward
   Serial.println("NON detect");
  }

  delay(100); // Small delay to avoid overwhelming the serial output
}
