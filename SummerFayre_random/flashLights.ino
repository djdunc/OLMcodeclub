// a light flashing function that allows you to say how long light should be on and off

void flashLights(int blinkon, int blinkoff){

  for(index = 0; index < numberofLEDs; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
  }
  delay(blinkon);
  
  for(index = 0; index < numberofLEDs; index++)
  {
    digitalWrite(ledPins[index],LOW);
  }
  delay(blinkoff);
  
}

