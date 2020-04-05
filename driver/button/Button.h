#ifndef AUTOMATIC_NIGHT_LIGHT_BUTTON_H
  #define AUTOMATIC_NIGHT_LIGHT_BUTTON_H

  #ifdef SETTING_BUTTON
    #define TIME_BETWEEN_BUTTON_PRESS_MS    1000

    class Button
    {
      public:
        void begin();
        void getButtonInput();

      private:
        bool buttonShortlyPressed;
        unsigned long buttonPressTime;
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_BUTTON_H
