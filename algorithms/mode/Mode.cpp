void Mode::begin()
{
  mode = OFF;
#ifdef IR_SENSOR
  lastCycleSignal = NO_SIGNAL;
#endif
  lastColorChangeTimestamp = 0;
}

#ifdef SETTING_BUTTON
void Mode::setOperationMode(ButtonMode_t newMode)
{
  switch(newMode)
  {
    case POWER:
      updatePowerMode();
      break;
    case AUTO:
      mode = AUTOMATIC;
      break;
    case PERM:
      mode = PERMANENT;
      break;
    case COLOR:
      Color_t currColor = rgb_led.getCurrentColor();
      if (powerMode) {
        switch (currColor) {
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
  }
}
#endif

#ifdef IR_SENSOR
void Mode::changeOperationMode(IrSignals_t lastSignal)
{
  if(lastCycleSignal != lastSignal)
  {
    switch(lastSignal)
    {
      case POWER:
        updatePowerMode();
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

#ifdef RGB_LED

void Mode::activeMode()
{
  switch (mode) {
    case AUTOMATIC:
      if (/*(ultrasonic_sensor.getLastMeasuredValue() > ULTRASONIC_SENSOR_TRIGGER_DISTANCE) &&*/
          (light_sensor.getLightIntensitiy() <= LIGHT_SENSOR_BORDER)) {
        DEBUG_PRINTLN(light_sensor.getLightIntensitiy());
        rgb_led.setCurrentColor();
      } else {
        rgb_led.setColor(255,255,255);
      }
      break;
    case PERMANENT:
      if (digitalRead(BUTTON_PERM_ON_PIN) == LOW)
      {
        DEBUG_PRINTLN("Button Perm off");
        rgb_led.setCurrentColor();
      }
      else if (digitalRead(BUTTON_PERM_OFF_PIN) == LOW)
      {
        DEBUG_PRINTLN("Button Perm off");
        rgb_led.setColor(255,255,255);
      }
      break;
    default:
      //Do nothing
      break;
  }
  //DEBUG_PRINTLN("POWER STATE: " + String(powerMode) + ", " + "CURRENT MODE: " + String(mode));
}

#ifdef IR_SENSOR
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
#endif
#endif

void Mode::updatePowerMode()
{
  if(powerMode)
  {
    powerMode = false;
    mode = OFF;
    rgb_led.changeCurrentColor(BLACK);
    rgb_led.setCurrentColor();
#ifdef POWER_LED
    digitalWrite(POWER_LED_PIN, LOW);
#endif
  }
  else
  {
    powerMode = true;
    mode = AUTOMATIC;
    rgb_led.changeCurrentColor(RED);
    rgb_led.setCurrentColor();
#ifdef POWER_LED
    digitalWrite(POWER_LED_PIN, HIGH);
#endif
  }
}