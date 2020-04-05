#ifndef AUTOMATIC_NIGHT_LIGHT_RGB_LED_H
  #define AUTOMATIC_NIGHT_LIGHT_RGB_LED_H

  #ifdef RGB_LED

    class RGB_Led
    {
      public:
        void begin();
        void setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_RGB_LED_H
