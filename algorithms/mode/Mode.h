#ifndef AUTOMATIC_NIGHT_LIGHT_MODE_H
#define AUTOMATIC_NIGHT_LIGHT_MODE_H

#define MIN_TIME_BETWEEN_COLOR_CHANGE_MS        1000

typedef enum {
  OFF,
  AUTOMATIC,
  PERMANENT
} Mode_t;

class Mode
    {
      public:
        void begin();
#ifdef SETTING_BUTTON
        void setOperationMode(bool newMode);
#endif
#ifdef ULTRASONIC_SENSOR
        void changeOperationMode(IrSignals_t lastSignal);
#endif
#ifdef RGB_LED
        void activeMode();
        void switchColor(IrSignals_t lastSignal);
#endif

      private:
        Mode_t mode;
        IrSignals_t lastCycleSignal;
        unsigned long lastColorChangeTimestamp;
    };

#endif //AUTOMATIC_NIGHT_LIGHT_MODE_H