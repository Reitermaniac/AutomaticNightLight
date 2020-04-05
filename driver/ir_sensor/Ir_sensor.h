#ifndef AUTOMATIC_NIGHT_LIGHT_IR_SENSOR_H
  #define AUTOMATIC_NIGHT_LIGHT_IR_SENSOR_H

  #ifdef IR_SENSOR

    class Ir_sensor
    {
      public:
        void begin();
        unsigned long getLastSignalTimestamp();
        void resetLastSignalTimestamp();
        IrSignals_t translate(unsigned long signal);
        IrSignals_t getLastSignal();

      private:
        unsigned long lastSignalTimestamp;
        IrSignals_t lastSignal;
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_IR_SENSOR_H
