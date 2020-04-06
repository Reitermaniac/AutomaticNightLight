#ifndef AUTOMATIC_NIGHT_LIGHT_ULTRASONIC_SENSOR_H
  #define AUTOMATIC_NIGHT_LIGHT_ULTRASONIC_SENSOR_H

  #ifdef ULTRASONIC_SENSOR

    #define  TIME_BETWEEN_MEASUREMENTS_MS     500

    class Ultrasonic_sensor
    {
      public:
        void begin();
        void getDistance();
        unsigned int getLastMeasuredValue();

      private:
        unsigned long timeOfLastMeasurement;
        unsigned int lastMeasuredValue;
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_ULTRASONIC_SENSOR_H
