//       _________    __       ___       ___
//      |   ---   |  |  |     |    \   /    |
//      |  |   |  |  |  |     |  |\ \ / /|  |
//      |  |   |  |  |  |     |  | \   / |  |
//      |  |___|  |  |  |___  |  |  \ /  |  |
//      |_________|  |______| |__|   V   |__|

// Code Club Light Wall Experimetation Kit
// OLM Codeclub 2016

// this is the list of the locations for each of the Lights - do not change
int ledPins[] =    {44,29,34,43,35,30,39,40,28,32,41,31,33,36,37,26,42,45,27,38};
int numberofLEDs = 20; // ie size of arrays above

void setup()
{
  // turn all lights on and then off to test they are all connected
  turnAllOn(numberofLEDs);
  delay(1000);
  turnAllOff(numberofLEDs);
}

void loop()
{
//  turnon(0); // turns on light 0
//  flashAllLights(500,20); // time delay for flash and number of lights
  

//  turnoff(2); // turns off light 2
//  flashlights(19, 500, 300); // blinks light 19 on for 500ms and off for 300ms
  flashlights(random(0,19), 300, 200); // blinks light 19 on for 500ms and off for 300ms
  
}








