#ifndef AUTOMATIC_NIGHT_LIGHT_MODE_H
#define AUTOMATIC_NIGHT_LIGHT_MODE_H

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
        void changeOperationMode();
#endif
        void activeMode();

      private:
        Mode_t mode;
        IrSignals_t lastCycleSignal;
    };

#endif //AUTOMATIC_NIGHT_LIGHT_MODE_H