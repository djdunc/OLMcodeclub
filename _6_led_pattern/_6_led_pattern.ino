
int ledPins[] =    {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};
int numberofLEDs = 20; // ie size of arrays above

int index; // used for counting which loop we are on

int pattern1[] = {9,10};
int pattern2[] = {4,5,6,7,8,11,12,13,14,15};
int pattern3[] = {0,1,2,3,16,17,18,19};

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
  // first pattern
  for(index = 0; index < sizeof(pattern1)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern1[index]], HIGH);  // turn LED on
  }
  delay(500);

  for(index = 0; index < sizeof(pattern1)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern1[index]],LOW);
  }

  
  // second pattern
  for(index = 0; index < sizeof(pattern2)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern2[index]], HIGH);  // turn LED on
  }
  delay(500);

  for(index = 0; index < sizeof(pattern2)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern2[index]],LOW);
  }


  // third pattern
  for(index = 0; index < sizeof(pattern3)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern3[index]], HIGH);  // turn LED on
  }
  delay(500);

  for(index = 0; index < sizeof(pattern3)/sizeof(int); index++)
  {
    digitalWrite(ledPins[pattern3[index]],LOW);
  }

}



