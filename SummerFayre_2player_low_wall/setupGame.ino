// code for starting up sequence for game

void setupGame(){

  boolean enterStartMode = true; 
  lcd.setRGB(0, 255, 255); // RGB 0-255
  lcd.clear();  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  lcd.print("HIT 3 TO START"); 
 
  flashLights(200,100); // reset all leds

  while(enterStartMode){
    
    if(digitalRead(buttonPins[3])==1){
      enterStartMode = false;
      score = 0;
    }
  }
 
  
 boolean waitForGo = true;

 lcd.setRGB(0, 255, 255); // RGB 0-255
 lcd.clear();  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(0,0);
 lcd.print("HIT GREEN TO GO"); 
 lcd.setCursor(0,1);
 lcd.print("HIGH:"); 
 lcd.setCursor(5,1);
 lcd.print(highScore);
 
 while(waitForGo){
  
  digitalWrite(ledPins[8],HIGH);
  digitalWrite(ledPins[9],HIGH);
  digitalWrite(ledPins[10],HIGH);
  digitalWrite(ledPins[11],HIGH);
  delay(300);
  digitalWrite(ledPins[8],LOW);
  digitalWrite(ledPins[9],LOW);
  digitalWrite(ledPins[10],LOW);
  digitalWrite(ledPins[11],LOW);
  delay(200);
  
  if(digitalRead(buttonPins[8])==1){
    game = 1;
    waitForGo = false;
    score = 0;
    flashLights(200,100);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("PLAYING GAME!"); 
  }
  if(digitalRead(buttonPins[9])==1){
    game = 3;
    waitForGo = false;
    score = 0;
    flashLights(200,100);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("PLAYING GAME!"); 
  }
  if(digitalRead(buttonPins[10])==1){
    game = 4;
    waitForGo = false;
    score = 0;
    flashLights(200,100);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("PLAYING GAME!"); 

  }
  if(digitalRead(buttonPins[11])==1){
    game = 2;
    waitForGo = false;
    score = 0;
    flashLights(200,100);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("PLAYING GAME!"); 

  }
  
  

 } 
 delay(1000); // wait a little to build anticipation  
  
}

