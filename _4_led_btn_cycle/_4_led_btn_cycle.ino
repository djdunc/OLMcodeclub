
int ledPins[] =    {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};
int buttonPins[] = {47,24,4,7,5,10,52,46,3,6,9,8,23,49,53,22,48,50,25,51};
int numberofLEDs = 20; // ie size of arrays above
                                                  

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState = LOW;       // the current reading from the input pin
int index = 0; // we use this variable to count through our list of LEDS and Buttons
boolean waiting = false; // we use this variable to store the state of a button press


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

  while(waiting == false){
 
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    Serial.print("Turned on LED ");
    Serial.print(index);
    delay(50);
    waiting = true;
  }
  
  
  while(waiting){
    // read the state of the switch into a local variable:
    if(digitalRead(buttonPins[index])==1){

      Serial.print("Button pressed = ");
      Serial.println(index);
      digitalWrite(ledPins[index], LOW);  // turn LED off
      delay(50);
      waiting = false;
      if(index < 20){
        index=index+1;
      }else{
        index = 0;
      }
    }
    delay(50);
    
  }

  
  

}



