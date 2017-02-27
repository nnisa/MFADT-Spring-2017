
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int socialStatus = 1;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  if (socialStatus == 5){ 
     setColor(0, 255, 255);  // green

    } 
  
  while (socialStatus == 4) {
     setColor(0, 255, 255);  // green
     delay(500);
     setColor(0, 0, 0);
     delay(500);
    }

  if (socialStatus == 3){ 
     setColor(0, 0, 255);  // Yellow
    } 

  while (socialStatus == 2) {
    setColor(0, 0, 255);  // Yellow
    delay(500);
    setColor(0, 0, 0);    
    delay(500);
    }

  if (socialStatus == 1){ 
      setColor(255, 0, 255);  // red  
    } 

//  setColor(0, 0, 255);  // Yellow
//  delay(1000);
//
//  setColor(0, 255, 255);  // green
//  delay(1000);
//
//  setColor(255, 0, 255);  // red
//  delay(1000);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
