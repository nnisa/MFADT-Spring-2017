//Took help from a friend, Wicher Thomas. 



#include <Servo.h>
Servo myservo;
int val;

// transistor stuff
// constants won't change. Used here to set a pin number :
const int transistorPin =  10;      // the number of the LED pin

// Variables will change :
int transistorState = LOW;             // ledState used to set the LED
//////////////////////

const int buttonPin1 = 5;     // the number of the pushbutton pin
const int buttonPin2 = 6;     // the number of the pushbutton pin
const int buttonPin3 = 7;     // the number of the pushbutton pin

const int ledPin =  13;      // the number of the LED pin

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status

//boolean buttonPressed1 = false;         // variable for reading the pushbutton status
//boolean buttonPressed2 = false;         // variable for reading the pushbutton status
//boolean buttonPressed3 = false;         // variable for reading the pushbutton status

//int LockCombination[] = {2, 3, 1};  //right combination for the lock
int userInput[3] = {0, 0, 0};

int lastPressed=0;

void setup() {
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);  
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(transistorPin, OUTPUT);
  digitalWrite(transistorPin, HIGH);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
}

void loop() {

// read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

  // IF NOTHING IS PRESSED, DONT RUN
  if (buttonState1 == LOW && buttonState2 == LOW && buttonState3 == LOW) {
    return;
  }

  Serial.print("USER INPUT=");
  Serial.print(userInput[0]);
  Serial.print(userInput[1]);
  Serial.print(userInput[2]);
  Serial.println();  

  if (buttonState1 == HIGH && lastPressed == 3) {
    userInput[2] = 1;
    lastPressed = 1;
  } else if (buttonState2 == HIGH && lastPressed == 0) {
    userInput[0] = 2;
    lastPressed = 2;
  } else if (buttonState3 == HIGH && lastPressed == 2) {
    userInput[1] = 3;
    lastPressed = 3;
  }

  if (userInput[0]==2 && userInput[1]==3 && userInput[2]==1) {
    digitalWrite(ledPin, HIGH);

    digitalWrite(transistorPin, HIGH);

    myservo.write(90);
    delay(2000);
  }  
  
  //for (int i=0; i <3; i++){
  // if (buttonState3 == HIGH) {
  //    userInput[i] = 3;
  //    buttonState3 == LOW;
  //     }    
  //  Serial.println(userInput[i]);


//    if (buttonState1 == HIGH) {
//    userInput[i] = 1;
//    Serial.println(userInput[i]);
//    Serial.println("hello");
//
//    } 
//  
//    else if (buttonState2 == HIGH) {
//    userInput[i] = 2;
//    } 
//
//    else if (buttonState3 == HIGH) {
//    userInput[i] = 3;
//    } 
//      delay(10);
//   } 

  

//  if (buttonState1 == HIGH) {
//    userInput[2] = 1;
//  } 
//  
//  if (buttonState2 == HIGH) {
//    userInput[0] = 2;
//  } 
//
//  if (buttonState3 == HIGH) {
//    userInput[1] = 3;
//  } 

  
}
