#define IR A5
#define MA 7
#define LED 13
int measurements[MA];
 
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);

pinMode(A0,INPUT);




}

void loop() {

Serial.println(analogRead(IR));

for (int i = 0; i < MA - 1; i++)
{
  measurements[i] = measurements [i+1];
}

measurements[MA - 1] = analogRead(IR);

long mean = 0;
for (int i = 0; i < MA; i++)
{
  mean += measurements[i];
}
mean /= MA;

Serial.println(mean);
analogWrite(LED, map(mean,0,1023,0,255));


}

