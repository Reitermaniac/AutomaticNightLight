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
        void setOperationMode(ButtonMode_t newMode);
#endif
#ifdef IR_SENSOR
        void changeOperationMode(IrSignals_t lastSignal);
#endif
#ifdef RGB_LED
        void activeMode();
#ifdef IR_SENSOR
        void switchColor(IrSignals_t lastSignal);
#endif
#endif

      private:
        Mode_t mode;
#ifdef IR_SENSOR
        IrSignals_t lastCycleSignal;
#endif
        unsigned long lastColorChangeTimestamp;
        void updatePowerMode();
    };

#endif //AUTOMATIC_NIGHT_LIGHT_MODE_H