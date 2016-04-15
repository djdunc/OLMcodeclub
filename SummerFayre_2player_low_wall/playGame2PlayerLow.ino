// the actual game

void playGame2PlayerLow(){

  //unsigned long finishTime = millis() + (gameLength*1000);
  long previousMillis = millis();        // time now

  
  points = 10; // define how many points are awarded per button push
  scoreP1 = 0; // reset scores
  scoreP2 = 0;

  // turn on all player 1 LEDS
  player1LightsOnLow();
  player2LightsOnLow();

  while(gameInPlay){
    

    //////////////////////////////
    // PLAYER 1
    //////////////////////////////
    
    // check to see if a player 1 button has been pressed
    for(int i = 0; i < sizeof(player1Low)/sizeof(int); i++)
    {
      if(digitalRead(buttonPins[player1Low[i]])==1 && digitalRead(ledPins[player1Low[i]])==1){

        digitalWrite(ledPins[player1Low[i]], LOW);  // turn LED off
        delay(20);
        scoreP1 = scoreP1 + points;
        
      }
    }

    // see if player1 has killed all lights
    boolean player1ClearedLEDs = true;

    for(int i = 0; i < sizeof(player1Low)/sizeof(int); i++)
    {
      if(digitalRead(ledPins[player1Low[i]])==1){  // if led is on then we need to wait until next go
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
    for(int i = 0; i < sizeof(player2Low)/sizeof(int); i++)
    {
      if(digitalRead(buttonPins[player2Low[i]])==1 && digitalRead(ledPins[player2Low[i]])==1){

        digitalWrite(ledPins[player2Low[i]], LOW);  // turn LED off
        delay(20);
        scoreP2 = scoreP2 + points;
        
      }
    }

    // see if player1 has killed all lights
    boolean player2ClearedLEDs = true;
    for(int i = 0; i < sizeof(player2Low)/sizeof(int); i++)
    {
      if(digitalRead(ledPins[player2Low[i]])==1){  // if led is on then we need to wait until next go
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

void player1LightsOnLow(){
  for(int i = 0; i < sizeof(player1Low)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player1Low[i]], HIGH);  // turn LED on
  }
}

void player2LightsOnLow(){
  for(int i = 0; i < sizeof(player2Low)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player2Low[i]], HIGH);  // turn LED on
  }
}

