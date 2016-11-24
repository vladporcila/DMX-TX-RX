#include <DmxSimple.h>

//Channel 1 - Pan (0-255)
//Channel 2 - Tilt
//Channel 3 - Dimmer/Strobe
//Channel 4 - Color

//Sending characters "U"(Tilt up),"D"(Tilt down),"L"(pan left),"R"(pan right) will move the light by a fraction of a turn.
//To send commands, send a letter, then follow with the control setting
//P is for pan, followed by a a number 0-255
//T is for tilt followed by a number 0-255
//C - Color 0-255
//B - Brightness/ Strobe 0-255
// Example : 
//To pan the light to a value of 120, send the character "C" and then send the value "120" 

char command;
int pan = 127;
int tilt = 127;

int control=0;

void setup() {
  Serial.begin(9600);
  DmxSimple.write(1,pan);
  DmxSimple.write(2,tilt);
}

void loop() {
  if (Serial.available()>0)
  {
    command = Serial.read();

    if ((command == 'U')&&(tilt <255))//Up
    {
      tilt++;
      DmxSimple.write(2,tilt);
    }
    else if((command == 'D')&&(tilt>0))//Down
    {
      tilt--;
      DmxSimple.write(2,tilt);
    }
    if ((command == 'R')&&(pan<255))//Right
    {
      pan++;
      DmxSimple.write(1,pan);
    }
    else if ((command == 'L')&&(pan>0))//Left
    {
      pan--;
      DmxSimple.write(1,pan);
    }

    if (command == 'B')//Brightness
    {
      Serial.read();
      while(Serial.available()==0)
      {
        //Wait for input
      }
      control = Serial.parseInt(); 
      
      //Serial.print(control);
      
      if (control > 20){
        control =20;
      }
            
      DmxSimple.write(3,control); //Adjust brightenss based on given string value
      control = 0;
    }

     if (command == 'C')//Color
    {
      Serial.read();
      while(Serial.available()==0)
      {
        //Wait for input
      }
       control = Serial.parseInt();
       //Serial.print(control);
       DmxSimple.write(4,control); //Adjust color based on given string value
       control=0;      
    }

     if (command == 'T')//Color
    {
      Serial.read();
      while(Serial.available()==0)
      {
        //Wait for input
      }
       tilt = Serial.parseInt();
       //Serial.print(control);
       DmxSimple.write(2,tilt); //Adjust Tilt based on given string value     
    }

     if (command == 'P')//Color
    {
      Serial.read();
      while(Serial.available()==0)
      {
        //Wait for input
      }
       pan = Serial.parseInt();
       //Serial.print(control);
       DmxSimple.write(1,pan); //Adjust Pan based on given string value     
    }

  }
}
