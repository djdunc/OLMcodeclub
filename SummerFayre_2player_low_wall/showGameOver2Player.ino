// Game over and game reset sequence

void showGameOver2Player(){
 
  // show winner on LCD
  lcd.clear();  

  if(scoreP1 > scoreP2){
    lcd.setCursor(0,0);
    lcd.print("PLAYER 1 WINS!"); 
  }else{
    lcd.print("PLAYER 2 WINS!"); 
  }

  lcd.setCursor(0,1);
  lcd.print(scoreP1); 
  lcd.setCursor(8,1);
  lcd.print(scoreP2);
  

  // flash lights of winner  
  lightsOut();
  boolean waitForReset = true;
  
  while(waitForReset){
    
    if(scoreP1 > scoreP2){
      flashPlayer1Lights(300,200);
    }else{
      flashPlayer2Lights(300,200);
    }
   
    if(digitalRead(buttonPins[3])==1){
      waitForReset = false;
      delay(500);
    }
    
  }
  
}



void flashPlayer1Lights(int blinkon, int blinkoff){

  for(int i = 0; i < sizeof(player1)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player1[i]], HIGH);  // turn LED on
  }
  delay(blinkon);
  
  for(int i = 0; i < sizeof(player1)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player1[i]], LOW);  // turn LED on
  }
  delay(blinkoff);
  
}

void flashPlayer2Lights(int blinkon, int blinkoff){

  for(int i = 0; i < sizeof(player2)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player2[i]], HIGH);  // turn LED on
  }
  delay(blinkon);
  
  for(int i = 0; i < sizeof(player2)/sizeof(int); i++)
  {
    digitalWrite(ledPins[player2[i]], LOW);  // turn LED on
  }
  delay(blinkoff);
  
}


