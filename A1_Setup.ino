void setup() 
{
  DEBUG_BEGIN(9600);
  configurePins();

  #ifdef SETTING_BUTTON
  button.begin();
  #endif
  
  DEBUG_PRINTLN("Setup finished.");
}

void configurePins()
{
  DEBUG_PRINTLN("Setting Output Pins");
  //pinMode(LED_PIN_GREEN, OUTPUT);
  //pinMode(LED_PIN_BLUE, OUTPUT);
}
