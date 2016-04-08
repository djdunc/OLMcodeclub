// Lightwall test rig
// Duncan Wilson 18th June 2015

// variables used in program
int ledPins[] = {26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45}; // each LED is connected to a unique pin

int numberofLEDs = 20; // ie size of array above

int ledState = LOW;         // the current state of the output pin

int index; // we use this variable to store which light we are talking about

// initialise the lightwall
void setup()
{
  for(index = 0; index < numberofLEDs; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index],ledState);
  }
}

// once setup complete we can run the main program
void loop()
{

  flashlights(300,200);
  
}
















// a light flashing function that allows you to say how long light should be on and off

void flashlights(int blinkon, int blinkoff){

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



