int LED = 13; // Use the onboard Uno LED
int ObstaclePin = A0;  // This is our input pin
int Obstacle = HIGH;  // MEANS NO OBSTACLE

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(ObstaclePin, INPUT); //CW increases, CCW decreases
  Serial.begin(115200);
  
}

void loop() {
  Obstacle = digitalRead(ObstaclePin);
  if (Obstacle == LOW)
  {
    Serial.println("OBSTACLE!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(250);
}
