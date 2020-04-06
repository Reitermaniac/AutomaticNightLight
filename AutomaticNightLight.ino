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
#ifdef IR_SENSOR
//#include "libraries/IRremote/IRremote.h"
#endif
//#include "libraries/NewPing/NewPing.h"
#include <NewPing.h>
#include "driver/ultrasonic_sensor/Ultrasonic_sensor.h"
#include "driver/rgb_led/RGB_Led.h"
#include "driver/button/Button.h"
#include "driver/light_sensor/Light_sensor.h"
#include "driver/ir_sensor/Ir_sensor.h"
#include "algorithms/mode/Mode.h"

bool powerMode;
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
Mode mode;

#ifdef IR_SENSOR
#include "libraries/IRremote/IRremote.cpp"
#endif
//#include "libraries/NewPing/NewPing.cpp"
#include "driver/ultrasonic_sensor/Ultrasonic_sensor.cpp"
#include "driver/rgb_led/RGB_Led.cpp"
#include "driver//Button/Button.cpp"
#include "driver/light_sensor/Light_sensor.cpp"
#include "driver/ir_sensor/Ir_sensor.cpp"
#include "algorithms/mode/Mode.cpp"

//**********************************************************************************************************
// Prototypes
//**********************************************************************************************************
#ifdef IR_SENSOR
void ir_sensor_getSignal();
#endif
