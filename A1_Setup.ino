void setup() 
{
  DEBUG_BEGIN(9600);
  powerMode = false;
  mode.begin();
  #ifdef SETTING_BUTTON
  button.begin();
  #endif
  #ifdef RGB_LED
  rgb_led.begin();
  #endif
  #ifdef IR_SENSOR
  ir_sensor.begin();
  irReceiver.enableIRIn();
  #endif
  DEBUG_PRINTLN("Setup finished.");
}
