// Summer Fayre Code Club Game for Lightwall
// OLM Code Club 2015

// a couple of libraries for the LCD display
#include <Wire.h>
#include "rgb_lcd.h"

// define how many LEDs and Buttons exist and what their pin locations are on Arduino
//old const int ledPins[] = {45,37,27,32,41,36,33,28,38,42,31,30,40,43,35,26,44,39,29,34};
// old const int buttonPins[] = {50,53,25,6,9,49,23,3,51,48,8,10,46,7,5,22,47,52,24,4};
int ledPins[] = {45,37,33,32,41,44,29,28,42,43,31,30,36,39,34,26,40,38,35,27};
int buttonPins[] = {50,53,23, 6, 9,47,24,3,48,7,8,10,49,52,4,22,46,51,5,25};


const int numberofLEDs = 20; // ie size of arrays above
const int relayPin =  11;     // the relay is attached to digital pin 9

// define which buttons are player 1 and 2
const int player1[] = {0,1,4,5,8,9,12,13,16,17};
const int player2[] = {2,3,6,7,10,11,14,15,18,19};

// create an instance of the LCD
rgb_lcd lcd;

// Variables will change:
int ledState = LOW;          // the current state of the output pin
int buttonState = LOW;       // the current reading from the input pin
int index = 0;               // we use this variable to count through our list of LEDS and Buttons
long gameLength = 10000;     // gamelength in milliseconds
int game = 1;                // defines which game is being played
int score = 0;               // variable to store current score
int highScore = 0;           // stores high score
int points = 0;              // the amount of points you can get for pushing the button, set in game play
int scoreP1 = 0;              // we also have 2 player game
int scoreP2 = 0;
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
    
    if(game==1){
      playGame();
      showGameOver();
    }
    if(game==2){
      playGame2Player();
      showGameOver2Player();
    }
    
  }else{
    
    setupGame();
    gameInPlay = true;
    
  }
  
}


