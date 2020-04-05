void loop() 
{
  #ifdef SETTING_BUTTON
  button.getButtonInput();
  #endif
  #ifdef ULTRASONIC_SENSOR
  //DEBUG_PRINTLN("Distance: " + String(ultrasonic_sensor.getDistance()) + " cm");
  #endif
  #ifdef LIGHT_SENSOR
  DEBUG_PRINTLN("Intensity: " + String(light_sensor.getLightIntensitiy()));
  #endif
}
