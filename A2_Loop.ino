void loop() 
{
  #ifdef SETTING_BUTTON
  button.getButtonInput();
  #endif
  #ifdef ULTRASONIC_SENSOR
  DEBUG_PRINTLN("Distance: " + String(ultrasonic_sensor.getDistance()) + " cm");
  #endif
}
