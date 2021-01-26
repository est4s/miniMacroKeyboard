#include <Keyboard.h> // The main library for sending keystrokes.

#define buttonPin1 2
#define buttonPin2 3
#define buttonPin3 5
#define buttonPin4 7
#define buttonPin5 8

#define changeButton 4
int buttonPushCounter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int nowState=0;

#define buttonKey11 KEY_F13
#define buttonKey12 KEY_F14
#define buttonKey13 KEY_F15
#define buttonKey14 KEY_F16
#define buttonKey15 KEY_F17

#define buttonKey21 KEY_F18
#define buttonKey22 KEY_F19
#define buttonKey23 KEY_F20
#define buttonKey24 KEY_F21
#define buttonKey25 KEY_F22

#define redLightPin 6
#define greenLightPin 9
#define blueLightPin 10

void setup() {
  Serial.begin(115200);
  
  Keyboard.begin();  // Initialise the library.
  
  pinMode(redLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(blueLightPin, OUTPUT);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  
  pinMode(changeButton, INPUT_PULLUP);
}

void loop() {
  programState();
  if(buttonPushCounter==1){
    rgbColor(0, 255, 255);
    }
  else
    rgbColor(255, 255, 125);
    
  if(digitalRead(buttonPin1)!=1){keyOne(buttonPushCounter);}
  if(digitalRead(buttonPin2)!=1){keyTwo(buttonPushCounter);}
  if(digitalRead(buttonPin3)!=1){keyThree(buttonPushCounter);}
  if(digitalRead(buttonPin4)!=1){keyFour(buttonPushCounter);}
  if(digitalRead(buttonPin5)!=1){keyFive(buttonPushCounter);}
}

void keyOne(int dataBank){
  if(buttonPushCounter!=0){
    Keyboard.press(buttonKey11);
  }
  else
    Keyboard.press(buttonKey21);
  Keyboard.releaseAll();
}
void keyTwo(int dataBank){
  if(dataBank!=0){
    Keyboard.press(buttonKey12);
  }
  else
    Keyboard.press(buttonKey22);
  Keyboard.releaseAll();
}
void keyThree(int dataBank){
  if(dataBank!=0){
    Keyboard.press(buttonKey13);
  }
  else
    Keyboard.press(buttonKey23);
  Keyboard.releaseAll();
}
void keyFour(int dataBank){
  if(dataBank!=0){
    Keyboard.press(buttonKey14);
  }
  else
    Keyboard.press(buttonKey24);
  Keyboard.releaseAll();
}
void keyFive(int dataBank){
  if(dataBank!=0){
    Keyboard.press(buttonKey15);
  }
  else
    Keyboard.press(buttonKey25);
  Keyboard.releaseAll();
}

void programState(){
  
  buttonState = digitalRead(changeButton);
  if(buttonPushCounter>1){buttonPushCounter=0;}

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}


void rgbColor(int redLightValue, int greenLightValue, int blueLightValue){
  analogWrite(redLightPin, redLightValue);
  analogWrite(greenLightPin, greenLightValue);
  analogWrite(blueLightPin, blueLightValue);
}
