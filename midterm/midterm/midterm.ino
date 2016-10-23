#include <NewPing.h>2 
#define motorPin 9
int ledPin = 3;
int buttonPin = 5;
int debouceTime = 10;
bool state = false;
NewPing SonarRight(12, 11, 400);

void setup() {
  
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int oldButtonState = digitalRead(buttonPin);
  delay(debouceTime);
  int newButtonState = digitalRead(buttonPin);

  if (oldButtonState != newButtonState) {
    if (newButtonState == LOW) {
      state = !state;
    }

  }

  if (state == false) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
    unsigned int uS = SonarRight.ping();
    if (uS / US_ROUNDTRIP_CM < 10) {
      digitalWrite(motorPin, HIGH);
    } else {
      digitalWrite(motorPin, LOW);
    }
  }
}

