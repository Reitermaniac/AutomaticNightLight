#ifdef RGB_LED
void RGB_Led::begin()
{
  currentColor = BLACK;
  pinMode(RGB_LED_RED_PIN, OUTPUT);
  pinMode(RGB_LED_GREEN_PIN, OUTPUT);
  pinMode(RGB_LED_BLUE_PIN, OUTPUT);
}

Color_t RGB_Led::getCurrentColor()
{
  return currentColor;
}

void RGB_Led::changeCurrentColor(Color_t newColor)
{
  currentColor = newColor;
  DEBUG_PRINTLN("CURRENT COLOR: " + String(currentColor));
}

void RGB_Led::setCurrentColor()
{
  switch (currentColor)
  {
    case BLACK:
      setColor(0,0,0);
      break;
    case RED:
      setColor(255,0,0);
      break;
    case GREEN:
      setColor(0,255,0);
      break;
    case BLUE:
      setColor(0,0,255);
      break;
    default:
      //Do nothing
      break;
  }
}

void RGB_Led::setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue)
{
  analogWrite(RGB_LED_RED_PIN, redValue);
  analogWrite(RGB_LED_GREEN_PIN, greenValue);
  analogWrite(RGB_LED_BLUE_PIN, blueValue);
}
#endif

