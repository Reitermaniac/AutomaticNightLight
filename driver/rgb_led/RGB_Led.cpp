#ifdef RGB_LED
void RGB_Led::begin()
{
  pinMode(RGB_LED_RED_PIN, OUTPUT);
  pinMode(RGB_LED_GREEN_PIN, OUTPUT);
  pinMode(RGB_LED_BLUE_PIN, OUTPUT);
}

void RGB_Led::setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue)
{
  analogWrite(RGB_LED_RED_PIN, redValue);
  analogWrite(RGB_LED_GREEN_PIN, greenValue);
  analogWrite(RGB_LED_BLUE_PIN, blueValue);
}
#endif

