#ifdef SETTING_BUTTON
void Button::begin()
{
  pinMode(BUTTON_TOGGLE_COLOR_PIN, INPUT_PULLUP);
  pinMode(BUTTON_TOGGLE_ON_OFF_PIN, INPUT_PULLUP);
  pinMode(BUTTON_SENSOR_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PERM_PIN, INPUT_PULLUP);

  buttonShortlyPressed = false;
  buttonPressTime = 0;
}

void Button::getButtonInput()
{
  if(!buttonShortlyPressed)
  {
    if(digitalRead(BUTTON_TOGGLE_COLOR_PIN) == LOW)
    {
      //ToDo: Set LED on Sensor Mode
      DEBUG_PRINTLN("Button Color");
      mode.setOperationMode(COLOR);
      buttonShortlyPressed = true;
      buttonPressTime = millis();
    }

    if(digitalRead(BUTTON_TOGGLE_ON_OFF_PIN) == LOW)
    {
      //ToDo: Set LED on Sensor Mode
      DEBUG_PRINTLN("Button ON/OFF");
      mode.setOperationMode(POWER);
      buttonShortlyPressed = true;
      buttonPressTime = millis();
    }

    if(digitalRead(BUTTON_SENSOR_PIN) == LOW)
    {
      //ToDo: Set LED on Sensor Mode
      DEBUG_PRINTLN("Button Sensor");
      mode.setOperationMode(AUTO);
      buttonShortlyPressed = true;
      buttonPressTime = millis();
    }

    if (digitalRead(BUTTON_PERM_PIN) == LOW)
    {
      //ToDo: Set LED Permanent
      DEBUG_PRINTLN("Button Perm");
      mode.setOperationMode(PERM);
      buttonShortlyPressed = true;
      buttonPressTime = millis();
    }
  }
  else
  {
    if((millis() - buttonPressTime) >= TIME_BETWEEN_BUTTON_PRESS_MS)
    {
      buttonShortlyPressed = false;
    }
  }
}
#endif

