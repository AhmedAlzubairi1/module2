# Lab2- Maker Valentine Box: By My Valentine
Lab 2 for creative embedded systems

## What is it?

It is a maker inspired chocolate box. Connect the components under the chocolate box to give a unique chocolate box to your significant other this Valentine's day.
Once the enclosure has been created, you can rotate the potentiometer to turn on the LEDs in a clockwise direction. You can then turn on the switch to turn the LEDs in a counter clockwise direction. If you press the left button, the two green LEDs will blink in sequence. If you click the right button, the blue led would blink. If you would click both of them at the same time, the 3 LEDs will blink in a sequence back to back.

## Installation 

No outside packages were used.


## Setting up Wiring
Components used:
  - 2 Push buttons
  - Switch 
  - Potentiometer
  - 8 Red LED
  - 2 Green LED
  - 1 Blue LED
  - Arduino Mega 

For the specific wiring, here is the digital connection layout for all the components:
    - Connect the Potentiometer to pin 2
    - Connect the switch to pin 53
    - Connect the right push button to 49
    - Connect the left push button to 51
    - Connect the 8 Red LEDs to pins 2,3,4,5,6,7,8,9
    - Connect the 2 green LEDs to pins 47, 45
    - Connect the 1 blue LEDs to pin 43
All the above pins are digital I/O pins except for the Potentiometer. It should be in the Analog pin 2.

## Running the Program
This enclosure was created using a **Arduino Mega** and doesn't require a script to run specicially. Open the myValentine.ino file using the Arduino IDE and select the arduino mega board as one of the options and then launch the code file.


## More Documentation

The code has been very well documented through comments. See for more info. 

## Bugs:

Normally you would connect the Ground pin to the **-** on the bread board and use that section as ground. If you get to a situation where ground doesn't seem to work for more wires, just use one of the other ground pins.

See website post for more info on why an arduino mega was used. In a nutshell, my ESP32 board came out deffective and I accidenlty broke my Raspberry Pi by connecting the ground to 5v. 
