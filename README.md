# ArduinoDEMO
Assignments for Interfacing with the Arduino Course

Week 1

Build a circuit that contains two push buttons, an LED, and any other basic components you think you need. The LED should only light when both push buttons are pressed. Only use your Arduino for power and ground.

![arduinohw1](https://cloud.githubusercontent.com/assets/22894897/21952471/afed8504-d9da-11e6-8454-757a27ada72f.gif)

Simulator : https://circuits.io/circuits/3704783-conditions-arduino/

Week 2

Build a circuit that lights an LED when it is sufficiently dark in a room. Demonstrate the circuit by covering the photoresistor to simulate darkness.

![led](https://cloud.githubusercontent.com/assets/22894897/22086546/6d70c398-dd96-11e6-86f5-71bd12e01f8a.gif)

Simulator: https://circuits.io/circuits/3657578-analogreadserial

Week 3

Write a sketch that allows a user to access data in EEPROM using the serial monitor. In the serial monitor the user should be able to type one of two commands: “read” and “write. "Read" takes one argument, an EEPROM address. "Write" takes two arguments, an EEPROM address and a value. 

For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM.

#include <EEPROM.h>

String command;

void setup() {

Serial.begin(9600);

}

void loop() {

if (Serial.available() > 0) {

command = Serial.readStringUntil('\n'); 
String commandRead = command;
String commandWrite = command;
String sRead = "read";
String sWrite = "write";
commandRead.remove(4);
commandWrite.remove(5);

if (commandRead.equals(sRead)) {

String sreadArg1 = command.substring(5);

int readArg1 = sreadArg1.toInt();

if (readArg1 > 1023 || readArg1 < 0) {

Serial.println("Invalid, please enter a value from 1 to 1023");

}

else { 
int valueEEP = EEPROM.read(readArg1); 
Serial.print("The value is ");
Serial.println(valueEEP, DEC);
}
}

if (commandWrite.equals(sWrite)) { 

String swriteArgs = command;

swriteArgs.remove(0, 6);

int swriteSpace = swriteArgs.indexOf(' ');

String swriteArg1 = swriteArgs.substring(0, swriteSpace);

int writeArg1 = swriteArg1.toInt(); 

String swriteArg2 = swriteArgs.substring(swriteSpace + 1);

int writeArg2 = swriteArg2.toInt(); 

if (writeArg1 < 0 || writeArg1 > 1023 || writeArg2 < 0 || writeArg2 > 255) {

Serial.println("Invalid, enter a first number from 0 to 1023 and the second number from 0 to 255");

}

else { 
byte byte1Arg2 = writeArg2 & 0XFF;

byte byte2Arg2 = (writeArg2 >> 8) & 0XFF;

EEPROM.write(writeArg1, byte1Arg2);

EEPROM.write(writeArg1 + 1, byte2Arg2);

Serial.println("Success!");

}
}
}
}

Week 4

Build a circuit and write a program that allows the user to control the brightness of an LED by turning the potentiometer. When the user turns the potentiometer, the LED brightness should change as well.

![ardpot](https://cloud.githubusercontent.com/assets/22894897/22753493/843d8d7c-edf9-11e6-8c73-7e2dc3f30d29.gif)

Simulator: https://circuits.io/circuits/3941296-arduinopot
