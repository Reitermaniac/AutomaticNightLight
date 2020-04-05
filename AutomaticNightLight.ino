//**********************************************************************************************************
// CONFIGURATIONS SECTION
//**********************************************************************************************************
char VERSION[] = "1.0.0";

//**********************************************************************************************************
// DEBUG configuration
//**********************************************************************************************************
#define DEBUG_PROJECT

//**********************************************************************************************************

#include "configuration/config.h"
#include "libraries/IRremote/IRremote.h"
#include "libraries/NewPing/NewPing.h"
#include "driver/ultrasonic_sensor/Ultrasonic_sensor.h"
#include "driver/rgb_led/RGB_Led.h"
#include "driver/button/Button.h"
#include "driver/light_sensor/Light_sensor.h"
#include "driver/ir_sensor/Ir_sensor.h"

#ifdef ULTRASONIC_SENSOR
  NewPing sonar(ULTRASONIC_SENSOR_TRIGGER_PIN, ULTRASONIC_SENSOR_ECHO_PIN, MAX_MEASURED_DISTANCE_CM);
  Ultrasonic_sensor ultrasonic_sensor;
#endif
#ifdef RGB_LED
  RGB_Led rgb_led;
#endif
#ifdef SETTING_BUTTON
  Button button;
#endif
#ifdef LIGHT_SENSOR
  Light_sensor light_sensor;
#endif
#ifdef IR_SENSOR
  IRrecv irReceiver(IR_SENSOR_INPUT_PIN);
  decode_results ir_undecoded_signal;
  Ir_sensor ir_sensor;
  IrSignals_t ir_decoded_signal;
#endif

#include "libraries/IRremote/IRremote.cpp"
#include "libraries/NewPing/NewPing.cpp"
#include "driver/ultrasonic_sensor/Ultrasonic_sensor.cpp"
#include "driver/rgb_led/RGB_Led.cpp"
#include "driver//Button/Button.cpp"
#include "driver/light_sensor/Light_sensor.cpp"
#include "driver/ir_sensor/Ir_sensor.cpp"

//**********************************************************************************************************
// Prototypes
//**********************************************************************************************************
void ir_sensor_getSignal();
