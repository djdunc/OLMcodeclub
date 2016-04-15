// the actual game

void playGame(){

  //unsigned long finishTime = millis() + (gameLength*1000);
  long previousMillis = millis();        // time now

  while(gameInPlay){
    
    
    while(waiting == false){
      index = random(numberofLEDs);    // pick a random number between 0 and 2
   
      digitalWrite(ledPins[index], HIGH);  // turn LED on
  
      delay(50);
      waiting = true;
      points = 100; // points between 100 and 10 are awarded depended on how quickly the button is pressed
    }
    
    while(waiting){
    // read the state of the switch into a local variable:
      if(digitalRead(buttonPins[index])==1){

        digitalWrite(ledPins[index], LOW);  // turn LED off
        delay(50);
        waiting = false;
        score = score + points;
        
      }
      delay(50);
      if(points > 10){
        points = points - 5;
      }
    }
    
    unsigned long currentMillis = millis();
    
    if(currentMillis - previousMillis > gameLength){
      gameInPlay = false;
    }

  } // end of while(gameInPlay)
  
}

