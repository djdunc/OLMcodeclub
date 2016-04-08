
int ledPins[] = {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};

//int buttonPins[] = {22,23,24,25,26,27};
int numberofLEDs = 20; // ie size of arrays above
                                                  

// Variables will change:
int ledState = LOW;         // the current state of the output pin


void setup()
{
  Serial.begin(9600); // initialize serial:

  int index;
  for(index = 0; index < numberofLEDs; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index],ledState);
  }
}


void loop()
{

  
  
  int index;

  for(index = 0; index < numberofLEDs; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(500);
    digitalWrite(ledPins[index],LOW);
    delay(200);
  }



  for(index = numberofLEDs; index > 0; index--)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(50);
    digitalWrite(ledPins[index],LOW);
    delay(20);
  }
  
  

}



