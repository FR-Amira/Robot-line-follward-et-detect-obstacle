
#include <Adafruit_MotorShield.h>
#include <Wire.h>

// Création de l'objet motor shield
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Création des objets moteurs
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);


 //////////// black ==0  and while ==1

//**********5 Channel IR Sensor Connection**********//
#define ir1 2
#define ir2 3
#define ir3 4
#define ir4 5
#define ir5 6
const int nearPin = 7;    // Optional, if NEAR pin is used

// Fonction pour avancer
void GOForward(int speed) {
    leftMotor->setSpeed(speed);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    rightMotor->run(FORWARD);
}
// Fonction pour tourner à droite
void TurnRIGHT(int speed) {
    leftMotor->setSpeed(speed);
    leftMotor->run(BACKWARD); // Inversé pour tourner
    rightMotor->setSpeed(speed);
    rightMotor->run(FORWARD);
}

// Fonction pour tourner à gauche
void TurnLEFT(int speed) {
    leftMotor->setSpeed(speed);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    rightMotor->run(BACKWARD); // Inversé pour tourner
}

// Fonction pour arrêter
void Stopp() {
    leftMotor->run(RELEASE);
    rightMotor->run(RELEASE);
}



void setup() {
    // Initialisation du shield moteur
    AFMS.begin();
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  
  pinMode(nearPin, INPUT);  // Optional, if NEAR pin is used
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int near = digitalRead(nearPin); // Optional
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  // Serial.print(" NEAR: "); Serial.println(near);
   //Reading Sensor Values
  Serial.print("S1: "); Serial.println(s1);
  Serial.print(" S2: "); Serial.println(s2);
   Serial.print(" S3: "); Serial.println(s3);
   Serial.print(" S4: "); Serial.println(s4);
   Serial.print(" S5: "); Serial.println(s5);


   // Detect obstcle 
   if(near == 1)
   {
     Stopp();
   }
   
//// Pour mon capteur il y a 5 sensor . Apres le test je trouve S1=S2=S3=S4 : black ==0  and while ==1 et S5  black =1  and while ==0


  //if only middle sensor detects black line
   if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    //going forward with full speed 
   GOForward(30);  // Speed varie entre 0 et 255 .Je utilise speed 30 puisque tension de mon batterie est tres elevee 12v.
  }

  
   if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
 TurnRIGHT(30);
  }
 
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
     TurnRIGHT(30);

  } 
   if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
   TurnLEFT(30);
  }
   if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
   TurnLEFT(30);
  }
 if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {TurnLEFT(30);
  }
  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    
     TurnRIGHT(30);
  }
    if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    
     TurnRIGHT(30);
  }
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    TurnLEFT(30);
  }
   if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
 Stopp();
  }
  }
