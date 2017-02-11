//Ava's TRAFFIC INTERSECTION
//By Tania Molina

#include <Servo.h>
#define SENSOR A0
#define BUZZER 10
#define BUTTON 9
#define BARRIER 11
#define GREEN 13
#define RED 12

Servo myservo;

void setup() {
  
  pinMode(SENSOR, INPUT); //photoresistor
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BARRIER, OUTPUT); //servo
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  
  digitalWrite(BUTTON, HIGH);
  
  myservo.attach(BARRIER);
  
  Serial.begin(9600);

}

void loop() {
  
  int Train = analogRead(A0); // Value of photoresistor.
  int Button = digitalRead(BUTTON); // Request for crossing
  
  Serial.println(Train); 
  delay(10);  //print value to serial 
  
  if (Train > 628) { //Train passing by.
   
    digitalWrite(RED, HIGH);
    
    digitalWrite(GREEN, LOW);
    
    myservo.write(0); //barrier down
    
    
  }
  else { //Train is not passing by.
    
    digitalWrite(RED, HIGH);
    myservo.write(90); //barrier up
    
  }
  if (Train < 628 && Button == LOW) { //Button pressed.
    
    myservo.write(0); //barrier down
    digitalWrite(RED, LOW);
    delay(50);
    digitalWrite(GREEN, HIGH);
    delay(5000); //starts blinking and beeping
      tone(BUZZER, 380, 500);
    digitalWrite(GREEN, LOW); 
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
      tone(BUZZER, 380, 500);
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
      tone(BUZZER, 380, 500);
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
      tone(BUZZER, 380, 500);
    digitalWrite(GREEN, LOW); //blinking becomes more frequent
    delay(150);
    digitalWrite(GREEN, HIGH);
    delay(150);
      tone(BUZZER, 580, 150); //tone goes higher
    digitalWrite(GREEN, LOW);
    delay(150);
    digitalWrite(GREEN, HIGH);
    delay(150); 
      tone(BUZZER, 580, 150);
    digitalWrite(GREEN, LOW);
    delay(150);
    digitalWrite(GREEN, HIGH);
    delay(150);
      tone(BUZZER, 580, 150);
    digitalWrite(GREEN, LOW);
    delay(50);
    digitalWrite(GREEN, HIGH);
    delay(50);
      tone(BUZZER, 580, 50);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    myservo.write(90); //barrier up
      
  }
  else {
   
    digitalWrite(GREEN, LOW);
    delay(15);
    digitalWrite(RED, HIGH);
    myservo.write(90);
    
  }
    
}

  

/* To run the simulator:
 
 https://circuits.io/circuits/3964527-arduino-traffic-intersection/edit
 
 */
