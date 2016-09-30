
const int analogInPin = A0;  
const int analogOutPin = 9; 
int sensorLow = 0;
int sensorHigh = 800;
int sensorValue = 0;        
int outputValue = 0;       

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue,sensorLow,sensorHigh, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  delay(2);
}
