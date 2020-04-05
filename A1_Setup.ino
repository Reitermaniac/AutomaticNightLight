void setup() 
{
  DEBUG_BEGIN(9600);

  #ifdef SETTING_BUTTON
  button.begin();
  #endif
  #ifdef RGB_LED
  rgb_led.begin();
  #endif
  DEBUG_PRINTLN("Setup finished.");
}
