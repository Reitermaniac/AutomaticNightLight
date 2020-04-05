#ifndef AUTOMATIC_NIGHT_LIGHT_LIGHT_SENSOR_H
  #define AUTOMATIC_NIGHT_LIGHT_LIGHT_SENSOR_H

  #ifdef LIGHT_SENSOR

    class Light_sensor
    {
      public:
        uint16_t getLightIntensitiy();
    };
  #endif
#endif //AUTOMATIC_NIGHT_LIGHT_LIGHT_SENSOR_H
