// Summer Fayre Code Club Game for Lightwall
// OLM Code Club 2015

// a couple of libraries for the LCD display
#include <Wire.h>
#include "rgb_lcd.h"

// define how many LEDs and Buttons exist and what their pin locations are on Arduino
const int ledPins[] = {45,37,27,32,41,36,33,28,38,42,31,30,40,43,35,26,44,39,29,34};
const int buttonPins[] = {50,53,25,6,9,49,23,3,51,48,8,10,46,7,5,22,47,52,24,4};
const int numberofLEDs = 20; // ie size of arrays above
const int relayPin =  11;     // the relay is attached to digital pin 9

// create an instance of the LCD
rgb_lcd lcd;

// Variables will change:
int ledState = LOW;          // the current state of the output pin
int buttonState = LOW;       // the current reading from the input pin
int index = 0;               // we use this variable to count through our list of LEDS and Buttons
long gameLength = 5000;     // gamelength in milliseconds
int score = 0;               // variable to store current score
int highScore = 0;           // stores high score
int points = 0;              // the amount of points you can get for pushing the button, set in game play
long buttonOnTime = 2000;     // the time in milliseconds we wait for a button press
boolean waiting = false;     // we use this variable to store if we are waiting for a button press
boolean gameInPlay = false; // has the game started

void setup()
{
  Serial.begin(9600); // initialize serial:

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(0, 0, 255); // RGB 0-255
  lcd.clear();  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  lcd.print("Welcome from"); // 16 characters max
  lcd.setCursor(0,1);
  lcd.print("Code Club!"); // 16 characters max

  // set up LEDs and Buttons - set all to LOW
  int i;
  for(i = 0; i < numberofLEDs; i++)
  {
    pinMode(ledPins[i],OUTPUT);
    digitalWrite(ledPins[i],ledState);
    pinMode(buttonPins[i],INPUT);
    digitalWrite(buttonPins[i],buttonState);
  }
  pinMode(relayPin, OUTPUT);
  
}

void loop()
{

  if(gameInPlay){
    
    playGame();
    showGameOver();
    
  }else{
    
    setupGame();
    gameInPlay = true;
    
  }
  
}


