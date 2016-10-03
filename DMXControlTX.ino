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

//Pin 7,6,5,4 are for Left Down Right Up, active Low (Pullup)

 //A0 - Color
 //A1 - Brightness

int left = 7;
int right = 6;
int down = 5;
int up = 4;

int val=0;

int bright=0;
int oldbright=0;

int color=0;
int oldcolor=0;

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  pinMode(up,INPUT_PULLUP);
}

void loop() {

  color=analogRead(0);
  bright=analogRead(1);

  delay(50);
  
  val=digitalRead(left);
  if(val==0)
  {
    Serial.print('L');
  }

  val=digitalRead(right);
  if(val==0)
  {
    Serial.print('R');
  }

  val=digitalRead(up);
  if(val==0)
  {
    Serial.print('U');
  }

  val=digitalRead(down);
  if(val==0)
  {
    Serial.print('D');
  }

  oldcolor = analogRead(0);//read color
  oldbright = analogRead(1);//read brightness again

  color = map (color,0,1023,0,255);
  oldcolor = map (oldcolor,0,1023,0,255);
  bright = map (bright,0,1023,0,255);
  oldbright = map (oldbright,0,1023,0,255);

  if (abs(color-oldcolor)>1)
  {
    Serial.print('C');
    delay(10);
    Serial.print(color);
  }

  if (abs(bright-oldbright)>1)
  {
    Serial.print('B');
    delay(10);
    Serial.print(bright);
  }
  
}
