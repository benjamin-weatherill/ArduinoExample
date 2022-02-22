/*


  Esplora Joystick Mouse


 This  sketch shows you how to read the joystick and use it to control the movement


 of the cursor on your computer.  You're making your Esplora into a mouse!


 WARNING: this sketch will take over your mouse movement. If you lose control


 of your mouse do the following:


 1) unplug the Esplora.


 2) open the EsploraBlink sketch


 3) hold the reset button down while plugging your Esplora back in


 4) while holding reset, click "Upload"


 5) when you see the message "Done compiling", release the reset button.


 This will stop your Esplora from controlling your mouse while you upload a sketch


 that doesn't take control of the mouse.


 Created on 22 Dec 2012


 by Tom Igoe


 Updated 8 March 2014


 by Scott Fitzgerald


 http://www.arduino.ccarduino.cc/en/Reference/EsploraReadJoystickSwitch


 This example is in the public domain.


 */


#include <Esplora.h>
#include <Mouse.h>


const int note[] = {


  262, // C


  277, // C#


  294, // D


  311, // D#


  330, // E


  349, // F


  370, // F#


  392, // G


  415, // G#


  440, // A


  466, // A#


  494, // B


  523  // C next octave

}; //13

const int RGB_Note_R[] {
  255,
  255,
  255,
  190,
  0,
  0,
  0,
  0,
  50,
  190,
  255,
  255,
  255

};

const int RGB_Note_G[] {
  0,
  0,
  0,
  0,
  0,
  230,
  255,
  255,
  255,
  255,
  210,
  150,
  0

};

const int RGB_Note_B[] {
  0,
  240,
  230,
  255,
  255,
  255,
  190,
  130,
  0,
  0,
  0,
  0,
  0

};


void setup() {


  Serial.begin(9600);       // initialize serial communication with your computer


  Mouse.begin();            // take control of the mouse

}


void loop() {


  int xValue = Esplora.readJoystickX();        // read the joystick's X position


  int yValue = Esplora.readJoystickY();        // read the joystick's Y position


  int button = Esplora.readJoystickSwitch();   // read the joystick pushbutton


  Serial.print("Joystick X: ");                // print a label for the X value


  Serial.print(xValue);                        // print the X value


  Serial.print("\tY: ");                       // print a tab character and a label for the Y value


  Serial.print(yValue);                        // print the Y value


  Serial.print("\tButton: ");                  // print a tab character and a label for the button


  Serial.print(button);                        // print the button value


  int mouseX = map(xValue, -512, 512, 10, -10);  // map the X value to a range of movement for the mouse X


  int mouseY = map(yValue, -512, 512, -10, 10);  // map the Y value to a range of movement for the mouse Y


  Mouse.move(mouseX - 1, mouseY + 1 , 0);                 // move the mouse


  if (button == 0) {                           // if the joystick button is pressed
  //if (Esplora.readButton(SWITCH_1) == HIGH) {

    Mouse.press();                             // send a mouse click

    
    

  } else {


    Mouse.release();                           // if it's not pressed, release the mouse button


  }

  //Sound
  if (Esplora.readButton(SWITCH_DOWN) == LOW) {


    int slider = Esplora.readSlider();


    // use map() to map the slider's range to the


    // range of notes you have:


    byte thisNote = map(slider, 0, 1023, 0, 13);

    Serial.print("\tthosNote: ");                  // print a tab character and a label for the button


    Serial.print(thisNote);  


    // play the note corresponding to the slider's position:

    Esplora.writeRGB(RGB_Note_R[thisNote], RGB_Note_G[thisNote], RGB_Note_B[thisNote]);
    Esplora.tone(note[thisNote]);


  } else {


    // if the button isn't pressed, turn the note off:


    Esplora.noTone();


  }
  


  delay(10);                                  // a short delay before moving again

}
