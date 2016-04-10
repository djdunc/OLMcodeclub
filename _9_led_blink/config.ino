
// a function to turn a specific light on
void turnon(int x){
  digitalWrite(ledPins[x], HIGH);  // turn LED on
}

// a function to turn a specific light off
void turnoff(int x){
  digitalWrite(ledPins[x], LOW);  // turn LED on
}

// a light flashing function that allows you to say how long light should be on and off
void flashlights(int light, int blinkon, int blinkoff){
  digitalWrite(ledPins[light], HIGH);  // turn LED on
  delay(blinkon);
  digitalWrite(ledPins[light],LOW);
  delay(blinkoff);  
}

// turn all lights on
void turnAllOn(int numberLEDS){
  
  for(int index = 0; index < numberofLEDs; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index],HIGH);
  }

}

// turn all lights off
void turnAllOff(int numberLEDS){
  
  for(int index = 0; index < numberofLEDs; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index],LOW);
  }

}

// flash all lights for n milliseconds
void flashAllLights(int mseconds, int numberofLEDs){
  turnAllOn(numberofLEDs);
  delay(mseconds);
  turnAllOff(numberofLEDs);
  delay(mseconds);
  
}



