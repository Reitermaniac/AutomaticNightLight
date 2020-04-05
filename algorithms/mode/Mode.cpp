void Mode::begin()
{
  mode = OFF;
  lastCycleSignal = NO_SIGNAL;
  lastColorChangeTimestamp = 0;
}

#ifdef SETTING_BUTTON
void Mode::setOperationMode(bool newMode)
{
  mode = (newMode) ? AUTOMATIC : PERMANENT;
}
#endif

#ifdef ULTRASONIC_SENSOR
void Mode::changeOperationMode(IrSignals_t lastSignal)
{
  if(lastCycleSignal != lastSignal)
  {
    switch(lastSignal)
    {
      case POWER:
        if(powerMode)
        {
          powerMode = false;
          mode = OFF;
          rgb_led.changeCurrentColor(BLACK);
          rgb_led.setCurrentColor();
        }
        else
        {
          powerMode = true;
          mode = AUTOMATIC;
          rgb_led.changeCurrentColor(RED);
          rgb_led.setCurrentColor();
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
  }
  lastCycleSignal = lastSignal;
}
#endif

void Mode::activeMode()
{
  switch (mode) {
    case AUTOMATIC:
      if ((ultrasonic_sensor.getDistance() > ULTRASONIC_SENSOR_TRIGGER_DISTANCE) &&
          (light_sensor.getLightIntensitiy() <= LIGHT_SENSOR_BORDER)) {
        rgb_led.setCurrentColor();
      } else {
        rgb_led.changeCurrentColor(BLACK);
        rgb_led.setCurrentColor();
      }
      break;
    case PERMANENT:
      rgb_led.setCurrentColor();
      break;
    default:
      //Do nothing
      break;
  }
  DEBUG_PRINTLN("POWER STATE: " + String(powerMode) + ", " + "CURRENT MODE: " + String(mode));
}

void Mode::switchColor(IrSignals_t lastSignal)
{
  if((millis() - lastColorChangeTimestamp) >= MIN_TIME_BETWEEN_COLOR_CHANGE_MS)
  {
    Color_t oldColor = rgb_led.getCurrentColor();
    switch (lastSignal) {
      case UP:
        if (powerMode) {
          switch (oldColor) {
            case BLACK:
              rgb_led.changeCurrentColor(RED);
            case RED:
              rgb_led.changeCurrentColor(GREEN);
              break;
            case GREEN:
              rgb_led.changeCurrentColor(BLUE);
              break;
            case BLUE:
              rgb_led.changeCurrentColor(RED);
              break;
            default: //Do nothing
              break;
          }
        }
        break;
      case DOWN:
        if (powerMode) {
          switch (oldColor) {
            case BLACK:
              rgb_led.changeCurrentColor(BLUE);
            case RED:
              rgb_led.changeCurrentColor(BLUE);
              break;
            case GREEN:
              rgb_led.changeCurrentColor(RED);
              break;
            case BLUE:
              rgb_led.changeCurrentColor(GREEN);
              break;
            default: //Do nothing
              break;
          }
        }
        break;
      default: //Do nothing
        break;
    }
    lastColorChangeTimestamp = millis();
  }
}