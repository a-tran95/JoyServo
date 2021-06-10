#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

// Creating variables to reference joystick directions
int D = 5;
int U = 4;
int L = 3;
int R = 2;


void setup() {
  // Connecting Joystick to all 4 directions
  pinMode(D, INPUT_PULLUP);
  pinMode(U, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);

  // Connecting Servo
  myservo.attach(11);

  Serial.begin(9600);
}

void loop() {
  static int spd = 1;              // Initialising speed variable
  
  if (digitalRead(U) == LOW)
  {
    if (spd < 10){
    spd += 1;                     // Increases speed when up is pressed on joystick
    Serial.println(spd);
    } 
    else{
    Serial.println("You are at max speed");
    }
  }

  if (digitalRead(D) == LOW)
  {
    if (spd > 1){
    spd -= 1;                     // Decreases speed when down is pressed on joystick
    Serial.println(spd);
    } 
    else {
    Serial.println("You are at the lowest speed");
    }
  }
    
  if (digitalRead(R) == LOW)
  {
    for (pos; pos>= 0; pos -= spd){
        myservo.write(pos);       // Swing servo clockwise to position 0 when right is pressed on joystick
        delay(15);
    }
    Serial.println("Moving to Position 0");
  }
  else if (digitalRead(L) == LOW)
  {
    for (pos; pos<= 180; pos += spd){
        myservo.write(pos);       // Swing servo clockwise to position 180 when left is pressed on joystick
        delay(15);
    }
    Serial.println("Moving to Position 180");
  }
  

  delay(100);
}
