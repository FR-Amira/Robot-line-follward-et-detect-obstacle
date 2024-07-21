
 //////////// black ==0  and while ==1

//**********5 Channel IR Sensor Connection**********//
#define ir1 2
#define ir2 3
#define ir3 4
#define ir4 5
#define ir5 6

void setup() {

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
   Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  //Reading Sensor Values

  
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  Serial.print("S1: "); Serial.println(s1);
  Serial.print(" S2: "); Serial.println(s2);
   Serial.print(" S3: "); Serial.println(s3);
   Serial.print(" S4: "); Serial.println(s4);
   Serial.print(" S5: "); Serial.println(s5);
 
}
