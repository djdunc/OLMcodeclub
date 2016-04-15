// Game over and game reset sequence

void showGameOver(){
 
  int tempBubblesOn = 0;
  
  if(score > highScore){
    lcd.setRGB(0, 255, 0); // RGB 0-255
    highScore = score;
    digitalWrite(relayPin, HIGH); // turn on bubble machine
    tempBubblesOn = 1;
  }else{
    lcd.setRGB(255, 0, 0); // RGB 0-255
  }
  
  lcd.clear();  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  lcd.print("Game Over");
  lcd.setCursor(0,1);
  lcd.print("score:"); 
  lcd.setCursor(6,1);
  lcd.print(score);

  
  boolean waitForReset = true;
  
  while(waitForReset){
    
    flashLights(200,100);
    
    if(digitalRead(buttonPins[3])==1){
      waitForReset = false;
      delay(500);
    }

    
  }
  if(tempBubblesOn){
    digitalWrite(relayPin, LOW); // turn off bubble machine
  }

  
}

