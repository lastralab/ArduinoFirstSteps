//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// AnalogReadSerial
// 
// Made by Tania Molina
// License: MIT
// Downloaded from: https://circuits.io/circuits/3657578-analogreadserial

//LED turns on when room is dark

#define LED 9

void setup() {
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  delay(25);  
  
  if (sensorValue > 628) {
   
    digitalWrite(LED, HIGH);
    
  }
 	 else  {
    digitalWrite(LED, LOW);
  }
}
