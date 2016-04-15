
//int ledPins[] = {45,37,27,32,41,36,33,28,38,42,31,30,40,43,35,26,44,39,29,34};
//int buttonPins[] = {22,23,24,25,26,27};
int ledPins[] =    {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};


int numberofLEDs = 20; // ie size of arrays above

int index; // used for counting which loop we are on

int pattern1[] = {2,3,6,7,10,11,14,15,18,19};
int pattern2[] = {0,1,4,5,8,9,12,13,16,17};

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
  // player 1 wins
  for(index = 0; index < sizeof(pattern1)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern1[index]], HIGH);  // turn LED on
  }
  delay(300);

  for(index = 0; index < sizeof(pattern1)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern1[index]],LOW);
  }
  delay(200);


}



