# ArduinoDEMO

Assignments for Arduino courses.

Week 1

Build a circuit that contains two push buttons, an LED, and any other basic components you think you need. The LED should only light when both push buttons are pressed. Only use your Arduino for power and ground.

![arduinohw1](https://cloud.githubusercontent.com/assets/22894897/21952471/afed8504-d9da-11e6-8454-757a27ada72f.gif)

I don't know how to press two buttons at the same time using a Mac.

Simulator : https://circuits.io/circuits/3704783-conditions-arduino/

Week 2

Build a circuit that lights an LED when it is sufficiently dark in a room. Demonstrate the circuit by covering the photoresistor to simulate darkness.

![led](https://cloud.githubusercontent.com/assets/22894897/22086546/6d70c398-dd96-11e6-86f5-71bd12e01f8a.gif)

Simulator: https://circuits.io/circuits/3657578-analogreadserial

Week 3

Write a sketch that allows a user to access data in EEPROM using the serial monitor. In the serial monitor the user should be able to type one of two commands: “read” and “write. "Read" takes one argument, an EEPROM address. "Write" takes two arguments, an EEPROM address and a value. 

For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM.

<pre>
<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">EEPROM</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font>

<font color="#00979c">String</font> <font color="#000000">command</font><font color="#000000">;</font>

<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">9600</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;
<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>

 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">available</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#434f54">&gt;</font> <font color="#000000">0</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;<font color="#000000">command</font> <font color="#434f54">=</font> <b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">readStringUntil</font><font color="#000000">(</font><font color="#00979c">'\n'</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">commandRead</font> <font color="#434f54">=</font> <font color="#000000">command</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">commandWrite</font> <font color="#434f54">=</font> <font color="#000000">command</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">sRead</font> <font color="#434f54">=</font> <font color="#005c5f">"read"</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">sWrite</font> <font color="#434f54">=</font> <font color="#005c5f">"write"</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">commandRead</font><font color="#434f54">.</font><font color="#d35400">remove</font><font color="#000000">(</font><font color="#000000">4</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">commandWrite</font><font color="#434f54">.</font><font color="#d35400">remove</font><font color="#000000">(</font><font color="#000000">5</font><font color="#000000">)</font><font color="#000000">;</font>

 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">commandRead</font><font color="#434f54">.</font><font color="#d35400">equals</font><font color="#000000">(</font><font color="#000000">sRead</font><font color="#000000">)</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">sreadArg1</font> <font color="#434f54">=</font> <font color="#000000">command</font><font color="#434f54">.</font><font color="#d35400">substring</font><font color="#000000">(</font><font color="#000000">5</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">int</font> <font color="#000000">readArg1</font> <font color="#434f54">=</font> <font color="#000000">sreadArg1</font><font color="#434f54">.</font><font color="#d35400">toInt</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">readArg1</font> <font color="#434f54">&gt;</font> <font color="#000000">1023</font> <font color="#434f54">||</font> <font color="#000000">readArg1</font> <font color="#434f54">&lt;</font> <font color="#000000">0</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">"Invalid, please enter a value from 1 to 1023"</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">}</font>

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#5e6d03">else</font> <font color="#000000">{</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">int</font> <font color="#000000">valueEEP</font> <font color="#434f54">=</font> <b><font color="#d35400">EEPROM</font></b><font color="#434f54">.</font><font color="#d35400">read</font><font color="#000000">(</font><font color="#000000">readArg1</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"The value is "</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#000000">valueEEP</font><font color="#434f54">,</font> <font color="#00979c">DEC</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>

 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">commandWrite</font><font color="#434f54">.</font><font color="#d35400">equals</font><font color="#000000">(</font><font color="#000000">sWrite</font><font color="#000000">)</font><font color="#000000">)</font> <font color="#000000">{</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">swriteArgs</font> <font color="#434f54">=</font> <font color="#000000">command</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">swriteArgs</font><font color="#434f54">.</font><font color="#d35400">remove</font><font color="#000000">(</font><font color="#000000">0</font><font color="#434f54">,</font> <font color="#000000">6</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">int</font> <font color="#000000">swriteSpace</font> <font color="#434f54">=</font> <font color="#000000">swriteArgs</font><font color="#434f54">.</font><font color="#d35400">indexOf</font><font color="#000000">(</font><font color="#00979c">' '</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">swriteArg1</font> <font color="#434f54">=</font> <font color="#000000">swriteArgs</font><font color="#434f54">.</font><font color="#d35400">substring</font><font color="#000000">(</font><font color="#000000">0</font><font color="#434f54">,</font> <font color="#000000">swriteSpace</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">int</font> <font color="#000000">writeArg1</font> <font color="#434f54">=</font> <font color="#000000">swriteArg1</font><font color="#434f54">.</font><font color="#d35400">toInt</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">String</font> <font color="#000000">swriteArg2</font> <font color="#434f54">=</font> <font color="#000000">swriteArgs</font><font color="#434f54">.</font><font color="#d35400">substring</font><font color="#000000">(</font><font color="#000000">swriteSpace</font> <font color="#434f54">+</font> <font color="#000000">1</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">int</font> <font color="#000000">writeArg2</font> <font color="#434f54">=</font> <font color="#000000">swriteArg2</font><font color="#434f54">.</font><font color="#d35400">toInt</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font> 

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">writeArg1</font> <font color="#434f54">&lt;</font> <font color="#000000">0</font> <font color="#434f54">||</font> <font color="#000000">writeArg1</font> <font color="#434f54">&gt;</font> <font color="#000000">1023</font> <font color="#434f54">||</font> <font color="#000000">writeArg2</font> <font color="#434f54">&lt;</font> <font color="#000000">0</font> <font color="#434f54">||</font> <font color="#000000">writeArg2</font> <font color="#434f54">&gt;</font> <font color="#000000">255</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">"Invalid, enter a first number from 0 to 1023 and the second number from 0 to 255"</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">}</font>

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#5e6d03">else</font> <font color="#000000">{</font> 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">byte</font> <font color="#000000">byte1Arg2</font> <font color="#434f54">=</font> <font color="#000000">writeArg2</font> <font color="#434f54">&</font> <font color="#000000">0XFF</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#00979c">byte</font> <font color="#000000">byte2Arg2</font> <font color="#434f54">=</font> <font color="#000000">(</font><font color="#000000">writeArg2</font> <font color="#434f54">&gt;&gt;</font> <font color="#000000">8</font><font color="#000000">)</font> <font color="#434f54">&</font> <font color="#000000">0XFF</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">EEPROM</font></b><font color="#434f54">.</font><font color="#d35400">write</font><font color="#000000">(</font><font color="#000000">writeArg1</font><font color="#434f54">,</font> <font color="#000000">byte1Arg2</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">EEPROM</font></b><font color="#434f54">.</font><font color="#d35400">write</font><font color="#000000">(</font><font color="#000000">writeArg1</font> <font color="#434f54">+</font> <font color="#000000">1</font><font color="#434f54">,</font> <font color="#000000">byte2Arg2</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">"Success!"</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#000000">}</font>
 <font color="#000000">}</font>
<font color="#000000">}</font>

</pre>

Simulator: https://circuits.io/circuits/3558041-serial-monitor-arduino-eeprom

Week 4

Build a circuit and write a program that allows the user to control the brightness of an LED by turning the potentiometer. When the user turns the potentiometer, the LED brightness should change as well.

![ardpot](https://cloud.githubusercontent.com/assets/22894897/22753493/843d8d7c-edf9-11e6-8c73-7e2dc3f30d29.gif)

Simulator: https://circuits.io/circuits/3941296-arduinopot

AVA'S TRAFFIC INTERSECTION (Week 4):

<img width="763" alt="screenshot 2017-02-10 10 54 37" src="https://cloud.githubusercontent.com/assets/22894897/22837781/5c92b02c-ef7f-11e6-998d-dff554c80a3c.png">

Instructions:

Vehicle circulation can be blocked by the barrier if the train appears or the pedestrian presses the button for the green light.

The green light button is activated if there is no train approaching, and enough time (9 sec) has passed since the button was last activated.

The green light is activated for 5 seconds, which is followed by an intermittent beep. Then, the green light blinks for 3 seconds and the intermittent beep becomes more frequent. After that, the red light is activated again, and the timer counts the time from 0 to 9 seconds.

If the train appears when the green light is on for pedestrians, the red signal is activated urgently and a continuous beep of a different height can be heard.

Wiring:

<img width="1220" alt="screenshot 2017-02-10 09 54 04" src="https://cloud.githubusercontent.com/assets/22894897/22837838/9302c5ca-ef7f-11e6-8943-754db39c945e.png">
