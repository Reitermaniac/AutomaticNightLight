#ifndef AUTOMATIC_NIGHT_LIGHT_RGB_LED_H
  #define AUTOMATIC_NIGHT_LIGHT_RGB_LED_H

  #ifdef RGB_LED

    typedef enum {
      BLACK,
      RED,
      GREEN,
      BLUE
    } Color_t;

    class RGB_Led
    {
      public:
        void begin();
        void changeCurrentColor(Color_t newColor);
        void setCurrentColor();
        Color_t getCurrentColor();

      private:
        Color_t currentColor;

        void setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_RGB_LED_H
