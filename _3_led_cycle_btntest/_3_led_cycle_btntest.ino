
//   int ledPins[] = {45,37,27,32,41,36,33,28,38,42,31,30,40,43,35,26,44,39,29,34};
//int buttonPins[] = {50,53,25, 6, 9,49,23, 3,51,48, 8,10,46, 7, 5,22,47,52,24, 4};

//int ledPins[] = {45,37,33,32,41,44,29,28,42,43,31,30,36,39,34,26,40,38,35,27};
//int buttonPins[] = {50,53,23, 6, 9,47,24,3,48,7,8,10,49,52,4,22,46,51,5,25};

//int ledPins[] =    {37,33,32,41,44,29,28,42,43,31,30,36,39,34,26,40,38,35,27};
//int buttonPins[] = {53,23, 6, 9,47,24, 3,48, 7, 8,10,49,52, 4,22,46,51, 5,25};

int ledPins[] =    {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};
int buttonPins[] = {47,24, 4, 7, 5,10,52,46, 3, 6, 9, 8,23,49,53,22,48,50,25,51};
int numberofLEDs = 19; // ie size of arrays above
                                                  

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState = LOW;       // the current reading from the input pin


void setup()
{
  Serial.begin(9600); // initialize serial:

  int index;
  for(index = 0; index < numberofLEDs; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index],ledState);
    pinMode(buttonPins[index],INPUT);
    digitalWrite(buttonPins[index],buttonState);
  }
}

void loop()
{

  
  
  int index;


  
  for(index = 0; index < numberofLEDs; index++)
  {
    if(digitalRead(buttonPins[index])==1){
        Serial.print(index);
        Serial.print(" -> ");
        Serial.println(buttonPins[index]);
        delay(100);
    }
  }

  
  

}



