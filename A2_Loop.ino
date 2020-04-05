void loop() 
{
  #ifdef SETTING_BUTTON
  button.getButtonInput();
  #endif
  #ifdef ULTRASONIC_SENSOR
  //DEBUG_PRINTLN("Distance: " + String(ultrasonic_sensor.getDistance()) + " cm");
  #endif
  #ifdef LIGHT_SENSOR
  //DEBUG_PRINTLN("Intensity: " + String(light_sensor.getLightIntensitiy()));
  #endif
  #ifdef IR_SENSOR
  ir_sensor_getSignal();
  //DEBUG_PRINTLN("Signal: " + String(ir_decoded_signal));
  #endif
  mode.activeMode();
  mode.switchColor(ir_decoded_signal);

  delay(500);
}

void ir_sensor_getSignal()
{
  if((millis() - ir_sensor.getLastSignalTimestamp()) >= IR_SENSOR_TIME_BETWEEN_SIGNALS_MS)
  {
    if(irReceiver.decode(&ir_undecoded_signal))
    {
      ir_decoded_signal = ir_sensor.translate(ir_undecoded_signal.value);
      mode.changeOperationMode(ir_decoded_signal);
      irReceiver.resume();
      ir_sensor.resetLastSignalTimestamp();
    } 
  }
  else
  {
    ir_decoded_signal = NO_SIGNAL;
  }
}
