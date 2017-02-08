//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// ArduinoPot
// 
// Made by Tania Molina
// License: MIT
// Downloaded from: https://circuits.io/circuits/3941296-arduinopot

#define LED 10
#define POT A0

int PotValue = 0;
int LedValue = 0;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  PotValue = analogRead(POT);
  
  LedValue = map(PotValue, 0, 1023, 0, 255);
  
  analogWrite(LED, LedValue);
  
  Serial.print("Potentiometer = ");
  Serial.print(PotValue);
  Serial.print("\t output = ");
  Serial.println(LedValue);

  delay(2);
  
}
