// the actual game

void playGame2Player(){

  //unsigned long finishTime = millis() + (gameLength*1000);
  long previousMillis = millis();        // time now

  
  points = 10; // define how many points are awarded per button push
  scoreP1 = 0; // reset scores
  scoreP2 = 0;

  // turn on all player 1 LEDS
  player1LightsOn();
  player2LightsOn();

  while(gameInPlay){
    

    //////////////////////////////
    // PLAYER 1
    //////////////////////////////
    
    // check to see if a player 1 button has been pressed
    for(int i = 0; i < sizeof(player1)/sizeof(int); i++)
    {
      if(digitalRead(buttonPins[player1[i]])==1 && digitalRead(ledPins[player1[i]])==1){

        digitalWrite(ledPins[player1[i]], LOW);  // turn LED off
        delay(20);
        scoreP1 = scoreP1 + points;
        
      }
    }

    // see if player1 has killed all lights
    boolean player1ClearedLEDs = true;

    for(int i = 0; i < sizeof(player1)/sizeof(int); i++)
    {
      if(digitalRead(ledPins[player1[i]])==1){  // if led is on then we need to wait until next go
        player1ClearedLEDs = false;
      }
    }
    
    if(player1ClearedLEDs){
      Serial.println("all lights cleared player1");
      player1LightsOn();
      delay(20);
    }
      
     //////////////////////////////
    // PLAYER 2
    //////////////////////////////
    
    // check to see if a player 2 button has been pressed
    for(int i = 0; i < sizeof(player2)/sizeof(int); i++)
    {
      if(digitalRead(buttonPins[player2[i]])==1 && digitalRead(ledPins[player2[i]])==1){

        digitalWrite(ledPins[player2[i]], LOW);  // turn LED off
        delay(20);
        scoreP2 = scoreP2 + points;
        
      }
    }

    // see if player1 has killed all lights
    boolean player2ClearedLEDs = true;
    for(int i = 0; i < sizeof(player2)/sizeof(int); i++)
    {
      if(digitalRead(ledPins[player2[i]])==1){  // if led is on then we need to wait until next go
        player2ClearedLEDs = false;
      }
    }
    
    if(player2ClearedLEDs){
      player2LightsOn();
      delay(20);
    }
      
    // see if game has finished  
    unsigned long currentMillis = millis();
    
    if(currentMillis - previousMillis > gameLength){
      gameInPlay = false;
    }

  } // end of while(gameInPlay)
  
}

void player1LightsOn(){
  for(int i = 0; i < sizeof(player1)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player1[i]], HIGH);  // turn LED on
  }
}

void player2LightsOn(){
  for(int i = 0; i < sizeof(player2)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player2[i]], HIGH);  // turn LED on
  }
}

