void Mode::begin()
{
  mode = OFF;
  lastCycleSignal = NO_SIGNAL;
}

#ifdef SETTING_BUTTON
void Mode::setOperationMode(bool newMode)
{
  mode = (newMode) ? AUTOMATIC : PERMANENT;
}
#endif

#ifdef ULTRASONIC_SENSOR
void Mode::changeOperationMode()
{
  IrSignals_t currentSignal = ir_sensor.getLastSignal();
  if(lastCycleSignal != currentSignal)
  {
    switch(ir_sensor.getLastSignal())
    {
      case POWER:
        if(powerMode)
        {
          powerMode = false;
          mode = OFF;
          rgb_led.changeCurrentColor(BLACK);
        }
        else
        {
          powerMode = true;
          mode = AUTOMATIC;
        }
        break;
      case ONE:
        if(powerMode)
        {
          mode = AUTOMATIC;
        }
        break;
      case TWO:
        if(powerMode)
        {
          mode = PERMANENT;
        }
        break;
      default:
        //Do nothing
        break;
    }
    lastCycleSignal = currentSignal;
  }
}
#endif

void Mode::activeMode()
{
  switch (mode)
  {
    case OFF:
      rgb_led.changeCurrentColor(BLACK);
      break;
    case AUTOMATIC:
      if ((ultrasonic_sensor.getDistance() > ULTRASONIC_SENSOR_TRIGGER_DISTANCE) && (light_sensor.getLightIntensitiy() <= LIGHT_SENSOR_BORDER))
      {
        rgb_led.changeCurrentColor(rgb_led.getCurrentColor());
      }
      else
      {
        rgb_led.changeCurrentColor(rgb_led.getCurrentColor());
      }
      break;
    case PERMANENT:
      rgb_led.changeCurrentColor(rgb_led.getCurrentColor());
      break;
  }
  //DEBUG_PRINTLN("POWER STATE: " + String(powerMode));
  //DEBUG_PRINTLN("CURRENT MODE: " + String(mode));
}